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

#include "modules/canbus/vehicle/ruimove/protocol/ehb_errinfo_620.h"

#include "glog/logging.h"

#include "modules/drivers/canbus/common/byte.h"
#include "modules/drivers/canbus/common/canbus_consts.h"

namespace apollo {
namespace canbus {
namespace ruimove {

using ::apollo::drivers::canbus::Byte;

Ehberrinfo620::Ehberrinfo620() {}
const int32_t Ehberrinfo620::ID = 0x620;

void Ehberrinfo620::Parse(const std::uint8_t* bytes, int32_t length,
                         ChassisDetail* chassis) const {
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_errinfo_checksum(ehb_errinfo_checksum(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_errinfo_rollcnt(ehb_errinfo_rollcnt(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_cansignal_vehiclespeed_err(ehb_cansignal_vehiclespeed_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_canmsgctrl_err(ehb_canmsgctrl_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_motoropen_err(ehb_motoropen_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_motorpossensor_err(ehb_motorpossensor_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_overtemp_err(ehb_overtemp_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_chip_err(ehb_chip_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_post_err(ehb_post_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_systeminit_err(ehb_systeminit_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_weeping_err(ehb_weeping_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_pwrswh_err(ehb_pwrswh_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_drvmtr_err(ehb_drvmtr_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_drvbridge_err(ehb_drvbridge_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_ecupowersupply_err(ehb_ecupowersupply_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_powersupply_err(ehb_powersupply_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_can_err(ehb_can_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_brkpresrsenor_alarm(ehb_brkpresrsenor_alarm(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_powersupply_alarm(ehb_powersupply_alarm(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_overtemp_alarm(ehb_overtemp_alarm(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_tempsenor_err(ehb_tempsenor_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_curtsenor_err(ehb_curtsenor_err(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_lowbrkfld_alarm(ehb_lowbrkfld_alarm(bytes, length));
  chassis->mutable_ruimove()->mutable_ehb_errinfo_620()->set_ehb_brkcmdabnormal_err(ehb_brkcmdabnormal_err(bytes, length));
}

// config detail: {'bit': 63, 'description': 'Checksum:Sum(Byte0:Byte6)^0xFF', 'is_signed_var': False, 'len': 8, 'name': 'ehb_errinfo_checksum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Ehberrinfo620::ehb_errinfo_checksum(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 7);
  int32_t x = t0.get_byte(0, 8);

  int ret = x;
  return ret;
}

// config detail: {'bit': 51, 'is_signed_var': False, 'len': 4, 'name': 'ehb_errinfo_rollcnt', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
int Ehberrinfo620::ehb_errinfo_rollcnt(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 6);
  int32_t x = t0.get_byte(0, 4);

  int ret = x;
  return ret;
}

// config detail: {'bit': 21, 'is_signed_var': False, 'len': 1, 'name': 'ehb_cansignal_vehiclespeed_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_cansignal_vehiclespeed_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 19, 'is_signed_var': False, 'len': 1, 'name': 'ehb_canmsgctrl_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_canmsgctrl_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 18, 'is_signed_var': False, 'len': 1, 'name': 'ehb_motoropen_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_motoropen_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 20, 'is_signed_var': False, 'len': 1, 'name': 'ehb_motorpossensor_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_motorpossensor_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 17, 'is_signed_var': False, 'len': 1, 'name': 'ehb_overtemp_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_overtemp_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 1, 'name': 'ehb_chip_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_chip_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 2);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 15, 'is_signed_var': False, 'len': 1, 'name': 'ehb_post_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_post_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 14, 'is_signed_var': False, 'len': 1, 'name': 'ehb_systeminit_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_systeminit_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 13, 'is_signed_var': False, 'len': 1, 'name': 'ehb_weeping_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_weeping_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 12, 'is_signed_var': False, 'len': 1, 'name': 'ehb_pwrswh_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_pwrswh_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'ehb_drvmtr_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_drvmtr_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'ehb_drvbridge_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_drvbridge_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'ehb_ecupowersupply_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_ecupowersupply_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'ehb_powersupply_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_powersupply_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 1);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 7, 'is_signed_var': False, 'len': 1, 'name': 'ehb_can_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_can_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(7, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'ehb_brkpresrsenor_alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_brkpresrsenor_alarm(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(6, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'ehb_powersupply_alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_powersupply_alarm(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(5, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 4, 'is_signed_var': False, 'len': 1, 'name': 'ehb_overtemp_alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_overtemp_alarm(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(4, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 3, 'is_signed_var': False, 'len': 1, 'name': 'ehb_tempsenor_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_tempsenor_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(3, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 2, 'is_signed_var': False, 'len': 1, 'name': 'ehb_curtsenor_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_curtsenor_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(2, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 1, 'description': '0x0: Normal 0x1: Fault', 'is_signed_var': False, 'len': 1, 'name': 'ehb_lowbrkfld_alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_lowbrkfld_alarm(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(1, 1);

  bool ret = x;
  return ret;
}

// config detail: {'bit': 0, 'description': '0x0: Normal 0x1: Fault', 'is_signed_var': False, 'len': 1, 'name': 'ehb_brkcmdabnormal_err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
bool Ehberrinfo620::ehb_brkcmdabnormal_err(const std::uint8_t* bytes, int32_t length) const {
  Byte t0(bytes + 0);
  int32_t x = t0.get_byte(0, 1);

  bool ret = x;
  return ret;
}
}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
