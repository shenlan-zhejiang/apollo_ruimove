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

#include "modules/canbus/vehicle/ruimove/protocol/vcu_state2_2b2.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ruimove {

using ::apollo::drivers::canbus::Byte;

Vcustate22b2::Vcustate22b2() {}
const int32_t Vcustate22b2::ID = 0x2B2;

void Vcustate22b2::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_autolight(v_state2_autolight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_screen(v_state2_screen(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_statuslight(v_state2_statuslight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_soc(v_state2_soc(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_rightmarkerlight(v_state2_rightmarkerlight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_leftmarkerlight(v_state2_leftmarkerlight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_horn(v_state2_horn(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_headlight(v_state2_headlight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_fronttentacles(v_state2_fronttentacles(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_emergencystop_3(v_state2_emergencystop_3(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_emergencystop_2(v_state2_emergencystop_2(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_emergencystop_1(v_state2_emergencystop_1(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_brakelight(v_state2_brakelight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_batchargeordischarge(v_state2_batchargeordischarge(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_backtentacles(v_state2_backtentacles(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_voice(v_state2_voice(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_rightturnlight(v_state2_rightturnlight(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state2_2b2()->set_v_state2_leftturnlight(v_state2_leftturnlight(bytes, length));
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_autolight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_autolight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 24, 'is_signed_var': False, 'len': 8, 'name': 'v_state2_screen', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate22b2::v_state2_screen(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 4, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_statuslight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_statuslight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 8, 'name': 'v_state2_soc', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate22b2::v_state2_soc(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_rightmarkerlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_rightmarkerlight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_leftmarkerlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_leftmarkerlight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 42, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_horn(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 2, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_headlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_headlight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_fronttentacles', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_fronttentacles(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_emergencystop_3', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_emergencystop_3(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_emergencystop_2', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_emergencystop_2(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_emergencystop_1', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_emergencystop_1(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 3, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_brakelight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_brakelight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 40, 'is_signed_var': False, 'len': 2, 'name': 'v_state2_batchargeordischarge', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate22b2::v_state2_batchargeordischarge(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 12, 'is_signed_var': False, 'len': 1, 'name': 'v_state2_backtentacles', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_backtentacles(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 16, 'description': 'voice(default:0)    0:none; 1:defined1; 2:defined2; 3:defined3', 'is_signed_var': False, 'len': 8, 'name': 'v_state2_voice', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate22b2::v_state2_voice(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 1, 'description': 'right turn-light   0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'v_state2_rightturnlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_rightturnlight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 0, 'description': 'left turn-light    0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'v_state2_leftturnlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate22b2::v_state2_leftturnlight(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}
}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
