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

class Vcustate22b2 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Vcustate22b2();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_AutoLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_autolight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 24, 'is_signed_var': False, 'len': 8, 'name': 'V_State2_Screen', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state2_screen(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 4, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_StatusLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_statuslight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'V_State2_SOC', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state2_soc(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_RightMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_rightmarkerlight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_LeftMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_leftmarkerlight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 42, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_Horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_horn(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 2, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_Headlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_headlight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_FrontTentacles', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_fronttentacles(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_EmergencyStop_3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_emergencystop_3(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_EmergencyStop_2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_emergencystop_2(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_EmergencyStop_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_emergencystop_1(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_BrakeLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_brakelight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 40, 'is_signed_var': False, 'len': 2, 'name': 'V_State2_BatChargeOrDisCharge', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state2_batchargeordischarge(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'is_signed_var': False, 'len': 1, 'name': 'V_State2_BackTentacles', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_backtentacles(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'description': 'voice(default:0)    0:none; 1:defined1; 2:defined2; 3:defined3', 'is_signed_var': False, 'len': 8, 'name': 'V_State2_Voice', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int v_state2_voice(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'description': 'right turn-light   0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_State2_RightTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_rightturnlight(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'description': 'left turn-light    0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_State2_LeftTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool v_state2_leftturnlight(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo


