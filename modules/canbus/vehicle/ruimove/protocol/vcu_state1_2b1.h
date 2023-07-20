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

class Vcustate12b1 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vcustate12b1();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 44, 'description': 'current auto-drive key state', 'is_signed_var': False, 'len': 1, 'name': 'V_State1_CurKeyState', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state1_curkeystate(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'description': 'current break state    0:break pedal percent; 1:deacceleration', 'is_signed_var': False, 'len': 1, 'name': 'V_State1_CurBrkMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state1_curbrkmode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'description': 'current emergency stop state', 'is_signed_var': False, 'len': 2, 'name': 'V_State1_CurEmergencyStop', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state1_curemergencystop(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'description': 'isReady 0:No Ready 1:Ready', 'is_signed_var': False, 'len': 1, 'name': 'V_State1_isReady', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state1_isready(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'description': 'VCU current break presure[EHB presure]', 'is_signed_var': False, 'len': 8, 'name': 'V_State1_CurBrkPres', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state1_curbrkpres(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'description': 'VCU current steer angle [EPS steer angle]', 'is_signed_var': True, 'len': 12, 'name': 'V_State1_CurAngle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-36|36]', 'physical_unit': '', 'precision': 0.02, 'type': 'double'}
  double v_state1_curangle(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'description': 'current drive mode   0x00:manual; 0x01: auto-drive; 0x02: remote-drive', 'is_signed_var': False, 'len': 2, 'name': 'V_State1_CurDriverlessMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state1_curdriverlessmode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'description': 'current speed', 'is_signed_var': True, 'len': 12, 'name': 'V_State1_CurSpeed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-102.4|102.35]', 'physical_unit': 'km/h', 'precision': 0.05, 'type': 'double'}
  double v_state1_curspeed(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'description': 'current drive mode   0: torque percent; 1: speed', 'is_signed_var': False, 'len': 2, 'name': 'V_State1_CurDriveMode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state1_curdrivemode(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'description': 'current gear 0x01R  0x02N  0x03D', 'is_signed_var': False, 'len': 2, 'name': 'V_State1_CurGear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcu_state1_2b1::Gear_state_actualType v_state1_curgear(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo


