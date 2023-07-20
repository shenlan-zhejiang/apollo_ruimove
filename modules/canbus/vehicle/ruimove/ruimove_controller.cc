/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

#include "modules/canbus/vehicle/ruimove/ruimove_controller.h"

#include "modules/common/proto/vehicle_signal.pb.h"

#include "cyber/common/log.h"
#include "modules/canbus/vehicle/ruimove/ruimove_message_manager.h"
#include "modules/canbus/vehicle/vehicle_controller.h"
#include "cyber/time/time.h"
#include "modules/drivers/canbus/can_comm/can_sender.h"
#include "modules/drivers/canbus/can_comm/protocol_data.h"

namespace apollo {
namespace canbus {
namespace ruimove {

using ::apollo::drivers::canbus::ProtocolData;
using ::apollo::common::ErrorCode;
using ::apollo::control::ControlCommand;

namespace {

const int32_t kMaxFailAttempt = 10;
const int32_t CHECK_RESPONSE_STEER_UNIT_FLAG = 1;
const int32_t CHECK_RESPONSE_SPEED_UNIT_FLAG = 2;
}

ErrorCode RuimoveController::Init(
	const VehicleParameter& params,
	CanSender<::apollo::canbus::ChassisDetail> *const can_sender,
    MessageManager<::apollo::canbus::ChassisDetail> *const message_manager) {
  if (is_initialized_) {
    AINFO << "RuimoveController has already been initiated.";
    return ErrorCode::CANBUS_ERROR;
  }

  vehicle_params_.CopyFrom(
      common::VehicleConfigHelper::Instance()->GetConfig().vehicle_param());
  params_.CopyFrom(params);
  if (!params_.has_driving_mode()) {
    AERROR << "Vehicle conf pb not set driving_mode.";
    return ErrorCode::CANBUS_ERROR;
  }

  if (can_sender == nullptr) {
    return ErrorCode::CANBUS_ERROR;
  }
  can_sender_ = can_sender;

  if (message_manager == nullptr) {
    AERROR << "protocol manager is null.";
    return ErrorCode::CANBUS_ERROR;
  }
  message_manager_ = message_manager;

  // sender part
  vcu_ctrl1_2a1_ = dynamic_cast<Vcuctrl12a1*>
          (message_manager_->GetMutableProtocolDataById(Vcuctrl12a1::ID));
  if (vcu_ctrl1_2a1_ == nullptr) {
     AERROR << "Vcuctrl12a1 does not exist in the RuimoveMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  vcu_ctrl2_2a2_ = dynamic_cast<Vcuctrl22a2*>
          (message_manager_->GetMutableProtocolDataById(Vcuctrl22a2::ID));
  if (vcu_ctrl2_2a2_ == nullptr) {
     AERROR << "Vcuctrl22a2 does not exist in the RuimoveMessageManager!";
     return ErrorCode::CANBUS_ERROR;
  }

  can_sender_->AddMessage(Vcuctrl12a1::ID, vcu_ctrl1_2a1_, false);
  can_sender_->AddMessage(Vcuctrl22a2::ID, vcu_ctrl2_2a2_, false);

  // need sleep to ensure all messages received
  AINFO << "RuimoveController is initialized.";

  is_initialized_ = true;
  return ErrorCode::OK;
}

RuimoveController::~RuimoveController() {}

bool RuimoveController::Start() {
  if (!is_initialized_) {
    AERROR << "RuimoveController has NOT been initiated.";
    return false;
  }
  // const auto& update_func = [this] { SecurityDogThreadFunc(); };
  // thread_.reset(new std::thread(update_func));

  return true;
}

void RuimoveController::Stop() {
  if (!is_initialized_) {
    AERROR << "RuimoveController stops or starts improperly!";
    return;
  }

  if (thread_ != nullptr && thread_->joinable()) {
    thread_->join();
    thread_.reset();
    AINFO << "RuimoveController stopped.";
  }
}

Chassis RuimoveController::chassis() {
  chassis_.Clear();

  ChassisDetail chassis_detail;
  message_manager_->GetSensorData(&chassis_detail);

  // 21, 22, previously 1, 2
  if (driving_mode() == Chassis::EMERGENCY_MODE) {
    set_chassis_error_code(Chassis::NO_ERROR);
  }

  chassis_.set_driving_mode(driving_mode());
  chassis_.set_error_code(chassis_error_code());

  // 3
  chassis_.set_engine_started(true);

  // if there is not ruimove, no chassis detail can be retrieved and return
  if (!chassis_detail.has_ruimove()) {
    AERROR << "NO RUIMOVE chassis information!";
    return chassis_;
  }
  Ruimove ruimove = chassis_detail.ruimove();
  
  // 4 speed_mps
  if (ruimove.has_vcu_state1_2b1() &&
      ruimove.vcu_state1_2b1().has_v_state1_curspeed()) {
    chassis_.set_speed_mps(
        static_cast<float>(ruimove.vcu_state1_2b1().v_state1_curspeed()));
  } else {
    chassis_.set_speed_mps(0);
  }

  // Not Support yet
  // // 5 throttle_pedal
  // if (ruimove.has_vcu_state1_2b1() &&
  //     ruimove.vcu_state1_2b1().has_v_state1_curthrotpercent()) {
  //   chassis_.set_throttle_percentage(static_cast<float>(
  //       ruimove.vcu_state1_2b1().v_state1_curthrotpercent()));
  // } else {
  //   chassis_.set_throttle_percentage(0);
  // }

  // // 6 brake_pedal
  // if (ruimove.has_vcu_state1_2b1() &&
  //     ruimove.vcu_state1_2b1().has_v_state1_curbrakepercent()) {
  //   chassis_.set_brake_percentage(static_cast<float>(
  //       ruimove.vcu_state1_2b1().v_state1_curbrakepercent()));
  // } else {
  //   chassis_.set_brake_percentage(0);
  // }

  // 7 gear position
  if (ruimove.has_vcu_state1_2b1() &&
      ruimove.vcu_state1_2b1().has_v_state1_curgear()) {
    switch (ruimove.vcu_state1_2b1().v_state1_curgear()) {
      case Vcu_state1_2b1::GEAR_STATE_ACTUAL_D: {
        chassis_.set_gear_location(Chassis::GEAR_DRIVE);
      } break;
      case Vcu_state1_2b1::GEAR_STATE_ACTUAL_N: {
        chassis_.set_gear_location(Chassis::GEAR_NEUTRAL);
      } break;
      case Vcu_state1_2b1::GEAR_STATE_ACTUAL_R: {
        chassis_.set_gear_location(Chassis::GEAR_REVERSE);
      } break;
      case Vcu_state1_2b1::GEAR_STATE_ACTUAL_P: {
        chassis_.set_gear_location(Chassis::GEAR_PARKING);
      } break;
      default:
        chassis_.set_gear_location(Chassis::GEAR_INVALID);
        break;
    }
  } else {
    chassis_.set_gear_location(Chassis::GEAR_NONE);
  }

  // 8 steering_percentage
  if (ruimove.has_vcu_state1_2b1() &&
      ruimove.vcu_state1_2b1().has_v_state1_curangle()) {
    chassis_.set_steering_percentage(static_cast<float>(
        ruimove.vcu_state1_2b1().v_state1_curangle() * 100.0 /
        vehicle_params_.max_steer_angle()));
  } else {
    chassis_.set_steering_percentage(0);
  }

  // 9 ehb pressure adapted into epb
  if (ruimove.has_vcu_state1_2b1() &&
      ruimove.vcu_state1_2b1().has_v_state1_curbrkpres()) {
    chassis_.set_parking_brake(
        ruimove.vcu_state1_2b1().v_state1_curbrkpres() > 50);
  } else {
    chassis_.set_parking_brake(false);
  }

  // 10 error mask
  if (chassis_error_mask_) {
    chassis_.set_chassis_error_mask(chassis_error_mask_);
  }
  // Give engage_advice based on error_code and canbus feedback
  if (!chassis_error_mask_ && !chassis_.parking_brake()) {
    chassis_.mutable_engage_advice()->set_advice(
        apollo::common::EngageAdvice::READY_TO_ENGAGE);
  } else {
    chassis_.mutable_engage_advice()->set_advice(
        apollo::common::EngageAdvice::DISALLOW_ENGAGE);
    chassis_.mutable_engage_advice()->set_reason(
        "CANBUS not ready, epb is not released or firmware error!");
  }

  return chassis_;
}

void RuimoveController::Emergency() {
  set_driving_mode(Chassis::EMERGENCY_MODE);
  ResetProtocol();
}

ErrorCode RuimoveController::EnableAutoMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE) {
    AINFO << "already in COMPLETE_AUTO_DRIVE mode";
    return ErrorCode::OK;
  }

  vcu_ctrl1_2a1_->set_v_ctrl1_steerenable(Vcu_ctrl1_2a1::STEERING_ENABLE_STATE_STEERING_AUTOCONTROL);
  vcu_ctrl1_2a1_->set_v_ctrl1_signalsource(Vcu_ctrl1_2a1::SIGNAL_SOURCE_FROM_ACU);
  vcu_ctrl1_2a1_->set_v_ctrl1_signalenable(Vcu_ctrl1_2a1::SIGNAL_CONTROL_ENABLE);
  vcu_ctrl2_2a2_->set_v_ctrl2_signalsource(Vcu_ctrl2_2a2::SIGNAL_SOURCE_FROM_ACU);
  vcu_ctrl2_2a2_->set_v_ctrl2_signalenable(Vcu_ctrl2_2a2::SIGNAL_CONTROL_ENABLE);

  can_sender_->Update();
  // const int32_t flag =
  //     CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  // if (!CheckResponse(flag, true)) {
  //   AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
  //   Emergency();
  //   set_chassis_error_code(Chassis::CHASSIS_ERROR);
  //   return ErrorCode::CANBUS_ERROR;
  // }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
  return ErrorCode::OK;

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_enable();
  throttle_62_->set_enable();
  steering_64_->set_enable();

  can_sender_->Update();
  const int32_t flag =
      CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  if (!CheckResponse(flag, true)) {
    AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
  return ErrorCode::OK;
  */
}

ErrorCode RuimoveController::DisableAutoMode() {
  ResetProtocol();
  can_sender_->Update();
  set_driving_mode(Chassis::COMPLETE_MANUAL);
  set_chassis_error_code(Chassis::NO_ERROR);
  AINFO << "Switch to COMPLETE_MANUAL ok.";
  return ErrorCode::OK;
}

ErrorCode RuimoveController::EnableSteeringOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_STEER_ONLY) {
    set_driving_mode(Chassis::AUTO_STEER_ONLY);
    AINFO << "Already in AUTO_STEER_ONLY mode.";
    return ErrorCode::OK;
  }
  vcu_ctrl1_2a1_->set_v_ctrl1_steerenable(Vcu_ctrl1_2a1::STEERING_ENABLE_STATE_STEERING_AUTOCONTROL);
  vcu_ctrl1_2a1_->set_v_ctrl1_signalsource(Vcu_ctrl1_2a1::SIGNAL_SOURCE_FROM_ACU);
  vcu_ctrl1_2a1_->set_v_ctrl1_signalenable(Vcu_ctrl1_2a1::SIGNAL_CONTROL_ENABLE);
  vcu_ctrl2_2a2_->set_v_ctrl2_signalsource(Vcu_ctrl2_2a2::SIGNAL_SOURCE_FROM_ACU);
  vcu_ctrl2_2a2_->set_v_ctrl2_signalenable(Vcu_ctrl2_2a2::SIGNAL_CONTROL_ENABLE);

  can_sender_->Update();
  // const int32_t flag =
  //     CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  // if (!CheckResponse(flag, true)) {
  //   AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
  //   Emergency();
  //   set_chassis_error_code(Chassis::CHASSIS_ERROR);
  //   return ErrorCode::CANBUS_ERROR;
  // }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
  return ErrorCode::OK;

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_disable();
  throttle_62_->set_disable();
  steering_64_->set_enable();

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_STEER_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_STEER_ONLY);
  AINFO << "Switch to AUTO_STEER_ONLY mode ok.";
  return ErrorCode::OK;
  */
}

ErrorCode RuimoveController::EnableSpeedOnlyMode() {
  if (driving_mode() == Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() == Chassis::AUTO_SPEED_ONLY) {
    set_driving_mode(Chassis::AUTO_SPEED_ONLY);
    AINFO << "Already in AUTO_SPEED_ONLY mode";
    return ErrorCode::OK;
  }
  vcu_ctrl1_2a1_->set_v_ctrl1_steerenable(Vcu_ctrl1_2a1::STEERING_DISABLE_STATE_STEERING_AUTOCONTROL);
  vcu_ctrl1_2a1_->set_v_ctrl1_signalsource(Vcu_ctrl1_2a1::SIGNAL_SOURCE_FROM_ACU);
  vcu_ctrl1_2a1_->set_v_ctrl1_signalenable(Vcu_ctrl1_2a1::SIGNAL_CONTROL_ENABLE);
  vcu_ctrl2_2a2_->set_v_ctrl2_signalsource(Vcu_ctrl2_2a2::SIGNAL_SOURCE_FROM_ACU);
  vcu_ctrl2_2a2_->set_v_ctrl2_signalenable(Vcu_ctrl2_2a2::SIGNAL_CONTROL_ENABLE);

  can_sender_->Update();
  // const int32_t flag =
  //     CHECK_RESPONSE_STEER_UNIT_FLAG | CHECK_RESPONSE_SPEED_UNIT_FLAG;
  // if (!CheckResponse(flag, true)) {
  //   AERROR << "Failed to switch to COMPLETE_AUTO_DRIVE mode.";
  //   Emergency();
  //   set_chassis_error_code(Chassis::CHASSIS_ERROR);
  //   return ErrorCode::CANBUS_ERROR;
  // }
  set_driving_mode(Chassis::COMPLETE_AUTO_DRIVE);
  AINFO << "Switch to COMPLETE_AUTO_DRIVE mode ok.";
  return ErrorCode::OK;

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_enable();
  throttle_62_->set_enable();
  steering_64_->set_disable();

  can_sender_->Update();
  if (!CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, true)) {
    AERROR << "Failed to switch to AUTO_SPEED_ONLY mode.";
    Emergency();
    set_chassis_error_code(Chassis::CHASSIS_ERROR);
    return ErrorCode::CANBUS_ERROR;
  }
  set_driving_mode(Chassis::AUTO_SPEED_ONLY);
  AINFO << "Switch to AUTO_SPEED_ONLY mode ok.";
  return ErrorCode::OK;
  */
}

// NEUTRAL, REVERSE, DRIVE
void RuimoveController::Gear(Chassis::GearPosition gear_position) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "This drive mode no need to set gear.";
    return;
  }

  switch (gear_position) {
    case Chassis::GEAR_NEUTRAL: {
      vcu_ctrl1_2a1_->set_v_ctrl1_tgtgear(
          Vcu_ctrl1_2a1::GEAR_STATE_TARGET_N);
      break;
    }
    case Chassis::GEAR_REVERSE: {
      vcu_ctrl1_2a1_->set_v_ctrl1_tgtgear(
          Vcu_ctrl1_2a1::GEAR_STATE_TARGET_R);
      break;
    }
    case Chassis::GEAR_DRIVE: {
      vcu_ctrl1_2a1_->set_v_ctrl1_tgtgear(
          Vcu_ctrl1_2a1::GEAR_STATE_TARGET_D);
      break;
    }
    case Chassis::GEAR_PARKING: {
      vcu_ctrl1_2a1_->set_v_ctrl1_tgtgear(
          Vcu_ctrl1_2a1::GEAR_STATE_TARGET_N); // ruimove no NOT have parking gear for now
      break;
    }

    case Chassis::GEAR_INVALID: {
      AWARN << "Gear command is invalid! default change gear to NEUTRAL";
      vcu_ctrl1_2a1_->set_v_ctrl1_tgtgear(
          Vcu_ctrl1_2a1::GEAR_STATE_TARGET_N);
      break;
    }
    default: {
      vcu_ctrl1_2a1_->set_v_ctrl1_tgtgear(
          Vcu_ctrl1_2a1::GEAR_STATE_TARGET_N);
      break;
    }
  }

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  switch (gear_position) {
    case Chassis::GEAR_NEUTRAL: {
      gear_66_->set_gear_neutral();
      break;
    }
    case Chassis::GEAR_REVERSE: {
      gear_66_->set_gear_reverse();
      break;
    }
    case Chassis::GEAR_DRIVE: {
      gear_66_->set_gear_drive();
      break;
    }
    case Chassis::GEAR_PARKING: {
      gear_66_->set_gear_park();
      break;
    }
    case Chassis::GEAR_LOW: {
      gear_66_->set_gear_low();
      break;
    }
    case Chassis::GEAR_NONE: {
      gear_66_->set_gear_none();
      break;
    }
    case Chassis::GEAR_INVALID: {
      AERROR << "Gear command is invalid!";
      gear_66_->set_gear_none();
      break;
    }
    default: {
      gear_66_->set_gear_none();
      break;
    }
  }
  */
}

// brake with pedal
// pedal:0.00~99.99 unit:
void RuimoveController::Brake(double pedal) {
  // double real_value = vehicle_params_.max_acceleration() * acceleration / 100;
  // TODO(All) :  Update brake value based on mode
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set brake pedal.";
    return;
  }

  vcu_ctrl1_2a1_->set_v_ctrl1_brkpercent(pedal);

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  brake_60_->set_pedal(pedal);
  */
}

// drive with pedal
// pedal:0.00~99.99 unit:
void RuimoveController::Throttle(double pedal) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set throttle pedal.";
    return;
  }

  vcu_ctrl1_2a1_->set_v_ctrl1_trqpercent(pedal);

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  throttle_62_->set_pedal(pedal);
  */
}

// confirm the car is driven by acceleration command or drive/brake pedal
// drive with acceleration/deceleration
// acc:-7.0 ~ 5.0, unit:m/s^2
void RuimoveController::Acceleration(double acc) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE ||
      driving_mode() != Chassis::AUTO_SPEED_ONLY) {
    AINFO << "The current drive mode does not need to set acceleration.";
    return;
  }
  // None, ruimove do NOT support this mode for now
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
}

// ruimove default, +36 deg ~ -36 deg, left:+, right:-
// need to be compatible with control module, so reverse
// steering with angle
// angle:-99.99~0.00~99.99, unit:, left:+, right:-
void RuimoveController::Steer(double angle) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }

  const double real_angle =
      vehicle_params_.max_steer_angle() * angle / 100.0;
  vcu_ctrl1_2a1_->set_v_ctrl1_tgtangle(real_angle);

  // const double real_angle =
  //     vehicle_params_.max_steer_angle() / M_PI * 180 * angle / 100.0;
  // reverse sign
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  steering_64_->set_steering_angle(real_angle)->set_steering_angle_speed(200);
  */
}

// steering with new angle speed // ruimove do NOT support set angle speed
// angle:-99.99~0.00~99.99, unit:, left:+, right:-
// angle_spd:0.00~99.99, unit:deg/s
void RuimoveController::Steer(double angle, double angle_spd) {
  if (driving_mode() != Chassis::COMPLETE_AUTO_DRIVE &&
      driving_mode() != Chassis::AUTO_STEER_ONLY) {
    AINFO << "The current driving mode does not need to set steer.";
    return;
  }

  const double real_angle =
      vehicle_params_.max_steer_angle() * angle / 100.0;
  vcu_ctrl1_2a1_->set_v_ctrl1_tgtangle(real_angle);

  /* ADD YOUR OWN CAR CHASSIS OPERATION
  const double real_angle =
      vehicle_params_.max_steer_angle() / M_PI * 180 * angle / 100.0;
  const double real_angle_spd = ProtocolData<::apollo::canbus::ChassisDetail>::BoundedValue(
      vehicle_params_.min_steer_angle_rate(), vehicle_params_.max_steer_angle_rate(),
      vehicle_params_.max_steer_angle_rate() * angle_spd / 100.0);
  steering_64_->set_steering_angle(real_angle)
      ->set_steering_angle_speed(real_angle_spd);
  */
}

void RuimoveController::SetEpbBreak(const ControlCommand& command) {
  if (command.parking_brake()) {
    // None
  } else {
    // None
  }
}

void RuimoveController::SetBeam(const ControlCommand& command) {
  if (command.signal().high_beam()) {
    // None
  } else if (command.signal().low_beam()) {
    // None
  } else {
    // None
  }
}

void RuimoveController::SetHorn(const ControlCommand& command) {
  if (command.signal().horn()) {
    // None
  } else {
    // None
  }
}

void RuimoveController::SetTurningSignal(const ControlCommand& command) {
  // Set Turn Signal
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  auto signal = command.signal().turn_signal();
  if (signal == common::VehicleSignal::TURN_LEFT) {
    turnsignal_68_->set_turn_left();
  } else if (signal == common::VehicleSignal::TURN_RIGHT) {
    turnsignal_68_->set_turn_right();
  } else {
    turnsignal_68_->set_turn_none();
  }
  */
}

void RuimoveController::ResetProtocol() {
  message_manager_->ResetSendMessages();
}

bool RuimoveController::CheckChassisError() {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
  return false;
}

void RuimoveController::SecurityDogThreadFunc() {
  int32_t vertical_ctrl_fail = 0;
  int32_t horizontal_ctrl_fail = 0;

  if (can_sender_ == nullptr) {
    AERROR << "Failed to run SecurityDogThreadFunc() because can_sender_ is "
              "nullptr.";
    return;
  }
  while (!can_sender_->IsRunning()) {
    std::this_thread::yield();
  }

  std::chrono::duration<double, std::micro> default_period{50000};
  int64_t start = 0;
  int64_t end = 0;
  while (can_sender_->IsRunning()) {
    start = ::apollo::cyber::Time::Now().ToMicrosecond();
    const Chassis::DrivingMode mode = driving_mode();
    bool emergency_mode = false;

    // 1. horizontal control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_STEER_ONLY) &&
        CheckResponse(CHECK_RESPONSE_STEER_UNIT_FLAG, false) == false) {
      ++horizontal_ctrl_fail;
      if (horizontal_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      horizontal_ctrl_fail = 0;
    }

    // 2. vertical control check
    if ((mode == Chassis::COMPLETE_AUTO_DRIVE ||
         mode == Chassis::AUTO_SPEED_ONLY) &&
        !CheckResponse(CHECK_RESPONSE_SPEED_UNIT_FLAG, false)) {
      ++vertical_ctrl_fail;
      if (vertical_ctrl_fail >= kMaxFailAttempt) {
        emergency_mode = true;
        set_chassis_error_code(Chassis::MANUAL_INTERVENTION);
      }
    } else {
      vertical_ctrl_fail = 0;
    }
    if (CheckChassisError()) {
      set_chassis_error_code(Chassis::CHASSIS_ERROR);
      emergency_mode = true;
    }

    if (emergency_mode && mode != Chassis::EMERGENCY_MODE) {
      set_driving_mode(Chassis::EMERGENCY_MODE);
      message_manager_->ResetSendMessages();
    }
    end = ::apollo::cyber::Time::Now().ToMicrosecond();
    std::chrono::duration<double, std::micro> elapsed{end - start};
    if (elapsed < default_period) {
      std::this_thread::sleep_for(default_period - elapsed);
    } else {
      AERROR
          << "Too much time consumption in RuimoveController looping process:"
          << elapsed.count();
    }
  }
}

bool RuimoveController::CheckResponse(const int32_t flags, bool need_wait) {
  /* ADD YOUR OWN CAR CHASSIS OPERATION
  */
  return false;
}

void RuimoveController::set_chassis_error_mask(const int32_t mask) {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  chassis_error_mask_ = mask;
}

int32_t RuimoveController::chassis_error_mask() {
  std::lock_guard<std::mutex> lock(chassis_mask_mutex_);
  return chassis_error_mask_;
}

Chassis::ErrorCode RuimoveController::chassis_error_code() {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  return chassis_error_code_;
}

void RuimoveController::set_chassis_error_code(
    const Chassis::ErrorCode& error_code) {
  std::lock_guard<std::mutex> lock(chassis_error_code_mutex_);
  chassis_error_code_ = error_code;
}

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
