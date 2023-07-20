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

#include "modules/canbus/vehicle/ruimove/protocol/vcu_ctrl1_2a1.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ruimove {

using ::apollo::drivers::canbus::Byte;

const int32_t Vcuctrl12a1::ID = 0x2A1;

// public
Vcuctrl12a1::Vcuctrl12a1() { Reset(); }

uint32_t Vcuctrl12a1::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Vcuctrl12a1::UpdateData(uint8_t* data) {
  set_p_v_ctrl1_steerenable(data, v_ctrl1_steerenable_);
  set_p_v_ctrl1_signalsource(data, v_ctrl1_signalsource_);
  set_p_v_ctrl1_signalenable(data, v_ctrl1_signalenable_);
  set_p_v_ctrl1_tgtdeaccel(data, v_ctrl1_tgtdeaccel_);
  set_p_v_ctrl1_brkpercent(data, v_ctrl1_brkpercent_);
  set_p_v_ctrl1_brkmode(data, v_ctrl1_brkmode_);
  set_p_v_ctrl1_tgtangle(data, v_ctrl1_tgtangle_);
  set_p_v_ctrl1_tgtgear(data, v_ctrl1_tgtgear_);
  set_p_v_ctrl1_trqpercent(data, v_ctrl1_trqpercent_);
  set_p_v_ctrl1_drivemode(data, v_ctrl1_drivemode_);
  set_p_v_ctrl1_tgtspd(data, v_ctrl1_tgtspd_);
}

void Vcuctrl12a1::Reset() {
  // TODO(All) :  you should check this manually
  v_ctrl1_steerenable_ = Vcu_ctrl1_2a1::STEERING_DISABLE_STATE_STEERING_AUTOCONTROL;
  v_ctrl1_signalsource_ = Vcu_ctrl1_2a1::SIGNAL_SOURCE_FROM_RCU;
  v_ctrl1_signalenable_ = Vcu_ctrl1_2a1::SIGNAL_CONTROL_DISABLE;
  v_ctrl1_tgtdeaccel_ = 0.0;
  v_ctrl1_brkpercent_ = 0.0;
  v_ctrl1_brkmode_ = false;
  v_ctrl1_tgtangle_ = 0.0;
  v_ctrl1_tgtgear_ = Vcu_ctrl1_2a1::GEAR_STATE_TARGET_N;
  v_ctrl1_trqpercent_ = 0;
  v_ctrl1_drivemode_ = false;
  v_ctrl1_tgtspd_ = 0.0;
}

Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_steerenable(
    Vcu_ctrl1_2a1::Steering_enable_stateType v_ctrl1_steerenable) {
  v_ctrl1_steerenable_ = v_ctrl1_steerenable;
  return this;
 }

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SteerEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl12a1::set_p_v_ctrl1_steerenable(uint8_t* data,
    Vcu_ctrl1_2a1::Steering_enable_stateType v_ctrl1_steerenable) {
  int x = v_ctrl1_steerenable;

  Byte to_set(data + 0);
  to_set.set_value(x, 6, 1);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_signalsource(
    Vcu_ctrl1_2a1::Signal_source_Type v_ctrl1_signalsource) {
  v_ctrl1_signalsource_ = v_ctrl1_signalsource;
  return this;
 }

// config detail: {'bit': 0, 'description': '0:ACU; 1:RCU', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SignalSource', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl12a1::set_p_v_ctrl1_signalsource(uint8_t* data,
    Vcu_ctrl1_2a1::Signal_source_Type v_ctrl1_signalsource) {
  int x = v_ctrl1_signalsource;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_signalenable(
    Vcu_ctrl1_2a1::Signal_control_Type v_ctrl1_signalenable) {
  v_ctrl1_signalenable_ = v_ctrl1_signalenable;
  return this;
 }

// config detail: {'bit': 1, 'description': '0:disable;1:enable', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SignalEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl12a1::set_p_v_ctrl1_signalenable(uint8_t* data,
    Vcu_ctrl1_2a1::Signal_control_Type v_ctrl1_signalenable) {
  int x = v_ctrl1_signalenable;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 1);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_tgtdeaccel(
    double v_ctrl1_tgtdeaccel) {
  v_ctrl1_tgtdeaccel_ = v_ctrl1_tgtdeaccel;
  return this;
 }

// config detail: {'bit': 24, 'description': 'target deacceleration', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TgtDeaccel', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10]', 'physical_unit': '', 'precision': 0.05, 'type': 'double'}
void Vcuctrl12a1::set_p_v_ctrl1_tgtdeaccel(uint8_t* data,
    double v_ctrl1_tgtdeaccel) {
  v_ctrl1_tgtdeaccel = ProtocolData::BoundedValue(0.0, 10.0, v_ctrl1_tgtdeaccel);
  int x = v_ctrl1_tgtdeaccel / 0.050000;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 8);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_brkpercent(
    double v_ctrl1_brkpercent) {
  v_ctrl1_brkpercent_ = v_ctrl1_brkpercent;
  return this;
 }

// config detail: {'bit': 32, 'description': 'break percent,[0,100] unit:%', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_BrkPercent', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.4, 'type': 'double'}
void Vcuctrl12a1::set_p_v_ctrl1_brkpercent(uint8_t* data,
    double v_ctrl1_brkpercent) {
  v_ctrl1_brkpercent = ProtocolData::BoundedValue(0.0, 100.0, v_ctrl1_brkpercent);
  int x = v_ctrl1_brkpercent / 0.400000;

  Byte to_set(data + 4);
  to_set.set_value(x, 0, 8);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_brkmode(
    bool v_ctrl1_brkmode) {
  v_ctrl1_brkmode_ = v_ctrl1_brkmode;
  return this;
 }

// config detail: {'bit': 5, 'description': 'break mode    0:break pedal percent; 1:deacceleration', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_BrkMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl12a1::set_p_v_ctrl1_brkmode(uint8_t* data,
    bool v_ctrl1_brkmode) {
  int x = v_ctrl1_brkmode;

  Byte to_set(data + 0);
  to_set.set_value(x, 5, 1);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_tgtangle(
    double v_ctrl1_tgtangle) {
  v_ctrl1_tgtangle_ = v_ctrl1_tgtangle;
  return this;
 }

// config detail: {'bit': 40, 'description': 'target steer angle [-36,36], Counterclockwise is positive', 'is_signed_var': True, 'len': 12, 'name': 'V_Ctrl1_TgtAngle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-36|36]', 'physical_unit': 'deg', 'precision': 0.02, 'type': 'double'}
void Vcuctrl12a1::set_p_v_ctrl1_tgtangle(uint8_t* data,
    double v_ctrl1_tgtangle) {
  v_ctrl1_tgtangle = ProtocolData::BoundedValue(-36.0, 36.0, v_ctrl1_tgtangle);
  int x = v_ctrl1_tgtangle / 0.020000;
  uint8_t t = 0;

  t = x & 0xFF;
  Byte to_set0(data + 5);
  to_set0.set_value(t, 0, 8);
  x >>= 8;

  t = x & 0xF;
  Byte to_set1(data + 6);
  to_set1.set_value(t, 0, 4);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_tgtgear(
    Vcu_ctrl1_2a1::Gear_state_targetType v_ctrl1_tgtgear) {
  v_ctrl1_tgtgear_ = v_ctrl1_tgtgear;
  return this;
 }

// config detail: {'bit': 2, 'description': 'target gear 0x01R  0x02N  0x03D', 'is_signed_var': False, 'len': 2, 'name': 'V_Ctrl1_TgtGear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vcuctrl12a1::set_p_v_ctrl1_tgtgear(uint8_t* data,
    Vcu_ctrl1_2a1::Gear_state_targetType v_ctrl1_tgtgear) {
  // v_ctrl1_tgtgear = ProtocolData::BoundedValue(0, 3, (int)v_ctrl1_tgtgear);
  int x = v_ctrl1_tgtgear;

  Byte to_set(data + 0);
  to_set.set_value(x, 2, 2);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_trqpercent(
    int v_ctrl1_trqpercent) {
  v_ctrl1_trqpercent_ = v_ctrl1_trqpercent;
  return this;
 }

// config detail: {'bit': 16, 'description': 'target torque percent[0,100] unit:%', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TrqPercent', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
void Vcuctrl12a1::set_p_v_ctrl1_trqpercent(uint8_t* data,
    int v_ctrl1_trqpercent) {
  v_ctrl1_trqpercent = ProtocolData::BoundedValue(0, 100, v_ctrl1_trqpercent);
  int x = v_ctrl1_trqpercent;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_drivemode(
    bool v_ctrl1_drivemode) {
  v_ctrl1_drivemode_ = v_ctrl1_drivemode;
  return this;
 }

// config detail: {'bit': 4, 'description': 'drive mode   0: torque percent; 1: speed', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_DriveMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl12a1::set_p_v_ctrl1_drivemode(uint8_t* data,
    bool v_ctrl1_drivemode) {
  int x = v_ctrl1_drivemode;

  Byte to_set(data + 0);
  to_set.set_value(x, 4, 1);
}


Vcuctrl12a1* Vcuctrl12a1::set_v_ctrl1_tgtspd(
    double v_ctrl1_tgtspd) {
  v_ctrl1_tgtspd_ = v_ctrl1_tgtspd;
  return this;
 }

// config detail: {'bit': 8, 'description': 'target speed,[0,60]', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TgtSpd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|60]', 'physical_unit': 'km/h', 'precision': 0.4, 'type': 'double'}
void Vcuctrl12a1::set_p_v_ctrl1_tgtspd(uint8_t* data,
    double v_ctrl1_tgtspd) {
  v_ctrl1_tgtspd = ProtocolData::BoundedValue(0.0, 60.0, v_ctrl1_tgtspd);
  int x = v_ctrl1_tgtspd / 0.400000;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 8);
}

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
