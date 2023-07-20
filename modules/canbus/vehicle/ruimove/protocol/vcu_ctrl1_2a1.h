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

#pragma once

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/canbus/proto/chassis_detail.pb.h"

namespace apollo {
namespace canbus {
namespace ruimove {

class Vcuctrl12a1 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Vcuctrl12a1();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SteerEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl12a1* set_v_ctrl1_steerenable(Vcu_ctrl1_2a1::Steering_enable_stateType v_ctrl1_steerenable);

  // config detail: {'bit': 0, 'description': '0:ACU; 1:RCU', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SignalSource', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl12a1* set_v_ctrl1_signalsource(Vcu_ctrl1_2a1::Signal_source_Type v_ctrl1_signalsource);

  // config detail: {'bit': 1, 'description': '0:disable;1:enable', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SignalEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl12a1* set_v_ctrl1_signalenable(Vcu_ctrl1_2a1::Signal_control_Type v_ctrl1_signalenable);

  // config detail: {'bit': 24, 'description': 'target deacceleration', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TgtDeaccel', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10]', 'physical_unit': '', 'precision': 0.05, 'type': 'double'}
  Vcuctrl12a1* set_v_ctrl1_tgtdeaccel(double v_ctrl1_tgtdeaccel);

  // config detail: {'bit': 32, 'description': 'break percent,[0,100] unit:%', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_BrkPercent', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.4, 'type': 'double'}
  Vcuctrl12a1* set_v_ctrl1_brkpercent(double v_ctrl1_brkpercent);

  // config detail: {'bit': 5, 'description': 'break mode    0:break pedal percent; 1:deacceleration', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_BrkMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl12a1* set_v_ctrl1_brkmode(bool v_ctrl1_brkmode);

  // config detail: {'bit': 40, 'description': 'target steer angle [-36,36], Counterclockwise is positive', 'is_signed_var': True, 'len': 12, 'name': 'V_Ctrl1_TgtAngle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-36|36]', 'physical_unit': 'deg', 'precision': 0.02, 'type': 'double'}
  Vcuctrl12a1* set_v_ctrl1_tgtangle(double v_ctrl1_tgtangle);

  // config detail: {'bit': 2, 'description': 'target gear 0x01R  0x02N  0x03D', 'is_signed_var': False, 'len': 2, 'name': 'V_Ctrl1_TgtGear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcuctrl12a1* set_v_ctrl1_tgtgear(Vcu_ctrl1_2a1::Gear_state_targetType v_ctrl1_tgtgear);

  // config detail: {'bit': 16, 'description': 'target torque percent[0,100] unit:%', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TrqPercent', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  Vcuctrl12a1* set_v_ctrl1_trqpercent(int v_ctrl1_trqpercent);

  // config detail: {'bit': 4, 'description': 'drive mode   0: torque percent; 1: speed', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_DriveMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl12a1* set_v_ctrl1_drivemode(bool v_ctrl1_drivemode);

  // config detail: {'bit': 8, 'description': 'target speed,[0,60]', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TgtSpd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|60]', 'physical_unit': 'km/h', 'precision': 0.4, 'type': 'double'}
  Vcuctrl12a1* set_v_ctrl1_tgtspd(double v_ctrl1_tgtspd);

 private:

  // config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SteerEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl1_steerenable(uint8_t* data, Vcu_ctrl1_2a1::Steering_enable_stateType v_ctrl1_steerenable);

  // config detail: {'bit': 0, 'description': '0:ACU; 1:RCU', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SignalSource', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl1_signalsource(uint8_t* data, Vcu_ctrl1_2a1::Signal_source_Type v_ctrl1_signalsource);

  // config detail: {'bit': 1, 'description': '0:disable;1:enable', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_SignalEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl1_signalenable(uint8_t* data, Vcu_ctrl1_2a1::Signal_control_Type v_ctrl1_signalenable);

  // config detail: {'bit': 24, 'description': 'target deacceleration', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TgtDeaccel', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|10]', 'physical_unit': '', 'precision': 0.05, 'type': 'double'}
  void set_p_v_ctrl1_tgtdeaccel(uint8_t* data, double v_ctrl1_tgtdeaccel);

  // config detail: {'bit': 32, 'description': 'break percent,[0,100] unit:%', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_BrkPercent', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 0.4, 'type': 'double'}
  void set_p_v_ctrl1_brkpercent(uint8_t* data, double v_ctrl1_brkpercent);

  // config detail: {'bit': 5, 'description': 'break mode    0:break pedal percent; 1:deacceleration', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_BrkMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl1_brkmode(uint8_t* data, bool v_ctrl1_brkmode);

  // config detail: {'bit': 40, 'description': 'target steer angle [-36,36], Counterclockwise is positive', 'is_signed_var': True, 'len': 12, 'name': 'V_Ctrl1_TgtAngle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-36|36]', 'physical_unit': 'deg', 'precision': 0.02, 'type': 'double'}
  void set_p_v_ctrl1_tgtangle(uint8_t* data, double v_ctrl1_tgtangle);

  // config detail: {'bit': 2, 'description': 'target gear 0x01R  0x02N  0x03D', 'is_signed_var': False, 'len': 2, 'name': 'V_Ctrl1_TgtGear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl1_tgtgear(uint8_t* data, Vcu_ctrl1_2a1::Gear_state_targetType v_ctrl1_tgtgear);

  // config detail: {'bit': 16, 'description': 'target torque percent[0,100] unit:%', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TrqPercent', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|100]', 'physical_unit': '%', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl1_trqpercent(uint8_t* data, int v_ctrl1_trqpercent);

  // config detail: {'bit': 4, 'description': 'drive mode   0: torque percent; 1: speed', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl1_DriveMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl1_drivemode(uint8_t* data, bool v_ctrl1_drivemode);

  // config detail: {'bit': 8, 'description': 'target speed,[0,60]', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl1_TgtSpd', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|60]', 'physical_unit': 'km/h', 'precision': 0.4, 'type': 'double'}
  void set_p_v_ctrl1_tgtspd(uint8_t* data, double v_ctrl1_tgtspd);

 private:
  Vcu_ctrl1_2a1::Steering_enable_stateType v_ctrl1_steerenable_;
  Vcu_ctrl1_2a1::Signal_source_Type v_ctrl1_signalsource_;
  Vcu_ctrl1_2a1::Signal_control_Type v_ctrl1_signalenable_;
  double v_ctrl1_tgtdeaccel_;
  double v_ctrl1_brkpercent_;
  bool v_ctrl1_brkmode_;
  double v_ctrl1_tgtangle_;
  Vcu_ctrl1_2a1::Gear_state_targetType v_ctrl1_tgtgear_;
  int v_ctrl1_trqpercent_;
  bool v_ctrl1_drivemode_;
  double v_ctrl1_tgtspd_;
};

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo


