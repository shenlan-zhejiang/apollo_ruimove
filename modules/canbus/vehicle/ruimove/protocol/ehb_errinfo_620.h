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

class Ehberrinfo620 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;
  Ehberrinfo620();
  void Parse(const std::uint8_t* bytes, int32_t length,
                     ChassisDetail* chassis) const override;

 private:

  // config detail: {'bit': 63, 'description': 'Checksum:Sum(Byte0:Byte6)^0xFF', 'is_signed_var': False, 'len': 8, 'name': 'EHB_ErrInfo_CheckSum', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int ehb_errinfo_checksum(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 51, 'is_signed_var': False, 'len': 4, 'name': 'EHB_ErrInfo_RollCnt', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|15]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  int ehb_errinfo_rollcnt(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 21, 'is_signed_var': False, 'len': 1, 'name': 'EHB_CANSignal_VehicleSpeed_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_cansignal_vehiclespeed_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 19, 'is_signed_var': False, 'len': 1, 'name': 'EHB_CANMsgCtrl_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_canmsgctrl_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 18, 'is_signed_var': False, 'len': 1, 'name': 'EHB_MotorOpen_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_motoropen_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 20, 'is_signed_var': False, 'len': 1, 'name': 'EHB_MotorPosSensor_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_motorpossensor_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 17, 'is_signed_var': False, 'len': 1, 'name': 'EHB_OverTemp_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_overtemp_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 1, 'name': 'EHB_Chip_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_chip_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 15, 'is_signed_var': False, 'len': 1, 'name': 'EHB_Post_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_post_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 14, 'is_signed_var': False, 'len': 1, 'name': 'EHB_SystemInit_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_systeminit_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 13, 'is_signed_var': False, 'len': 1, 'name': 'EHB_Weeping_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_weeping_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 12, 'is_signed_var': False, 'len': 1, 'name': 'EHB_PwrSwh_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_pwrswh_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 11, 'is_signed_var': False, 'len': 1, 'name': 'EHB_DrvMtr_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_drvmtr_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'EHB_DrvBridge_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_drvbridge_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'EHB_ECUPowerSupply_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_ecupowersupply_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'EHB_PowerSupply_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_powersupply_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 7, 'is_signed_var': False, 'len': 1, 'name': 'EHB_CAN_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_can_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 6, 'is_signed_var': False, 'len': 1, 'name': 'EHB_BrkPresrSenor_Alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_brkpresrsenor_alarm(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'EHB_PowerSupply_Alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_powersupply_alarm(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 4, 'is_signed_var': False, 'len': 1, 'name': 'EHB_OverTemp_Alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_overtemp_alarm(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 3, 'is_signed_var': False, 'len': 1, 'name': 'EHB_TempSenor_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_tempsenor_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 2, 'is_signed_var': False, 'len': 1, 'name': 'EHB_CurtSenor_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_curtsenor_err(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 1, 'description': '0x0: Normal 0x1: Fault', 'is_signed_var': False, 'len': 1, 'name': 'EHB_LowBrkFld_Alarm', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_lowbrkfld_alarm(const std::uint8_t* bytes, const int32_t length) const;

  // config detail: {'bit': 0, 'description': '0x0: Normal 0x1: Fault', 'is_signed_var': False, 'len': 1, 'name': 'EHB_BrkCmdAbnormal_Err', 'offset': 0.0, 'order': 'motorola', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  bool ehb_brkcmdabnormal_err(const std::uint8_t* bytes, const int32_t length) const;
};

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo


