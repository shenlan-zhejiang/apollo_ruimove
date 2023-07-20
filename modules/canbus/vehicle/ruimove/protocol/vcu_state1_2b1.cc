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

#include "modules/canbus/vehicle/ruimove/protocol/vcu_state1_2b1.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ruimove {

using ::apollo::drivers::canbus::Byte;

Vcustate12b1::Vcustate12b1() {}
const int32_t Vcustate12b1::ID = 0x2B1;

void Vcustate12b1::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curkeystate(v_state1_curkeystate(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curbrkmode(v_state1_curbrkmode(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curemergencystop(v_state1_curemergencystop(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_isready(v_state1_isready(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curbrkpres(v_state1_curbrkpres(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curangle(v_state1_curangle(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curdriverlessmode(v_state1_curdriverlessmode(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curspeed(v_state1_curspeed(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curdrivemode(v_state1_curdrivemode(bytes, length));
  chassis->mutable_ruimove()->mutable_vcu_state1_2b1()->set_v_state1_curgear(v_state1_curgear(bytes, length));
}

// config detail: {'bit': 44, 'description': 'current auto-drive key state', 'is_signed_var': False, 'len': 1, 'name': 'v_state1_curkeystate', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate12b1::v_state1_curkeystate(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 5, 'description': 'current break state    0:break pedal percent; 1:deacceleration', 'is_signed_var': False, 'len': 1, 'name': 'v_state1_curbrkmode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate12b1::v_state1_curbrkmode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 40, 'description': 'current emergency stop state', 'is_signed_var': False, 'len': 2, 'name': 'v_state1_curemergencystop', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate12b1::v_state1_curemergencystop(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 5);
  int32_t x = t0.get_byte(0, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 0, 'description': 'isReady 0:No Ready 1:Ready', 'is_signed_var': False, 'len': 1, 'name': 'v_state1_isready', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Vcustate12b1::v_state1_isready(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 32, 'description': 'VCU current break presure[EHB presure]', 'is_signed_var': False, 'len': 8, 'name': 'v_state1_curbrkpres', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate12b1::v_state1_curbrkpres(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 4);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 20, 'description': 'VCU current steer angle [EPS steer angle]', 'is_signed_var': True, 'len': 12, 'name': 'v_state1_curangle', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-36|36]', 'physical_unit': '', 'precision': 0.02, 'type': 'double'}
double Vcustate12b1::v_state1_curangle(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 3);
  int32_t x = t0.get_byte(0, 8);

  Byte t1(bytes + 2);
  int32_t t = t1.get_byte(4, 4);
  x <<= 4;
  x |= t;

  x <<= 20;
  x >>= 20;

  double ret = x * 0.020000;
  return ret;
}

// config detail: {'bit': 1, 'description': 'current drive mode   0x00:manual; 0x01: auto-drive; 0x02: remote-drive', 'is_signed_var': False, 'len': 2, 'name': 'v_state1_curdriverlessmode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate12b1::v_state1_curdriverlessmode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 8, 'description': 'current speed', 'is_signed_var': True, 'len': 12, 'name': 'v_state1_curspeed', 'offset': 0.0, 'order': 'intel', 'physical_range': '[-102.4|102.35]', 'physical_unit': 'km/h', 'precision': 0.05, 'type': 'double'}
double Vcustate12b1::v_state1_curspeed(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 4);

  Byte t1(bytes + 1);
  int32_t t = t1.get_byte(0, 8);
  x <<= 8;
  x |= t;

  x <<= 20;
  x >>= 20;

  double ret = x * 0.050000;
  return ret;
}

// config detail: {'bit': 3, 'description': 'current drive mode   0: torque percent; 1: speed', 'is_signed_var': False, 'len': 2, 'name': 'v_state1_curdrivemode', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Vcustate12b1::v_state1_curdrivemode(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 2);

  int ret = x;
  return ret;
}

// config detail: {'bit': 6, 'description': 'current gear 0x01R  0x02N  0x03D', 'is_signed_var': False, 'len': 2, 'name': 'v_state1_curgear', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|3]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
Vcu_state1_2b1::Gear_state_actualType Vcustate12b1::v_state1_curgear(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 2);

  Vcu_state1_2b1::Gear_state_actualType ret = static_cast<Vcu_state1_2b1::Gear_state_actualType>(x);
  return ret;
}
}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
