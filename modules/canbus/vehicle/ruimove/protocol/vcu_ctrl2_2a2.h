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

class Vcuctrl22a2 : public ::apollo::drivers::canbus::ProtocolData<
                    ::apollo::canbus::ChassisDetail> {
 public:
  static const int32_t ID;

  Vcuctrl22a2();

  uint32_t GetPeriod() const override;

  void UpdateData(uint8_t* data) override;

  void Reset() override;

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 4, 'name': 'V_Ctrl2_AutoLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcuctrl22a2* set_v_ctrl2_autolight(int v_ctrl2_autolight);

  // config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_RightMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_rightmarkerlight(bool v_ctrl2_rightmarkerlight);

  // config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_LeftMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_leftmarkerlight(bool v_ctrl2_leftmarkerlight);

  // config detail: {'bit': 6, 'is_signed_var': False, 'len': 2, 'name': 'V_Ctrl2_StatusLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcuctrl22a2* set_v_ctrl2_statuslight(int v_ctrl2_statuslight);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl2_Screen', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcuctrl22a2* set_v_ctrl2_screen(int v_ctrl2_screen);

  // config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_Headlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_headlight(bool v_ctrl2_headlight);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_BrakeLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_brakelight(bool v_ctrl2_brakelight);

  // config detail: {'bit': 0, 'description': '0:ACU; 1:RCU', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_SignalSource', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_signalsource(Vcu_ctrl2_2a2::Signal_source_Type v_ctrl2_signalsource);

  // config detail: {'bit': 1, 'description': '0:disabled; 1:enabled', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_SignalEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_signalenable(Vcu_ctrl2_2a2::Signal_control_Type v_ctrl2_signalenable);

  // config detail: {'bit': 11, 'description': 'horn', 'is_signed_var': False, 'len': 4, 'name': 'V_Ctrl2_Horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcuctrl22a2* set_v_ctrl2_horn(int v_ctrl2_horn);

  // config detail: {'bit': 24, 'description': 'voice(default:0)    0:none; 1:defined1; 2:defined2; 3:defined3', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl2_Voice', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|31]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  Vcuctrl22a2* set_v_ctrl2_voice(int v_ctrl2_voice);

  // config detail: {'bit': 4, 'description': 'right turn-light 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_RightTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_rightturnlight(bool v_ctrl2_rightturnlight);

  // config detail: {'bit': 3, 'description': 'left turn-light 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_LeftTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_leftturnlight(bool v_ctrl2_leftturnlight);

  // config detail: {'bit': 2, 'description': 'emergency stop 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_EmergencyStop', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  Vcuctrl22a2* set_v_ctrl2_emergencystop(bool v_ctrl2_emergencystop);

 private:

  // config detail: {'bit': 32, 'is_signed_var': False, 'len': 4, 'name': 'V_Ctrl2_AutoLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl2_autolight(uint8_t* data, int v_ctrl2_autolight);

  // config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_RightMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_rightmarkerlight(uint8_t* data, bool v_ctrl2_rightmarkerlight);

  // config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_LeftMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_leftmarkerlight(uint8_t* data, bool v_ctrl2_leftmarkerlight);

  // config detail: {'bit': 6, 'is_signed_var': False, 'len': 2, 'name': 'V_Ctrl2_StatusLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl2_statuslight(uint8_t* data, int v_ctrl2_statuslight);

  // config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl2_Screen', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl2_screen(uint8_t* data, int v_ctrl2_screen);

  // config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_Headlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_headlight(uint8_t* data, bool v_ctrl2_headlight);

  // config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_BrakeLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_brakelight(uint8_t* data, bool v_ctrl2_brakelight);

  // config detail: {'bit': 0, 'description': '0:ACU; 1:RCU', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_SignalSource', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_signalsource(uint8_t* data, Vcu_ctrl2_2a2::Signal_source_Type v_ctrl2_signalsource);

  // config detail: {'bit': 1, 'description': '0:disabled; 1:enabled', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_SignalEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_signalenable(uint8_t* data, Vcu_ctrl2_2a2::Signal_control_Type v_ctrl2_signalenable);

  // config detail: {'bit': 11, 'description': 'horn', 'is_signed_var': False, 'len': 4, 'name': 'V_Ctrl2_Horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl2_horn(uint8_t* data, int v_ctrl2_horn);

  // config detail: {'bit': 24, 'description': 'voice(default:0)    0:none; 1:defined1; 2:defined2; 3:defined3', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl2_Voice', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|31]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
  void set_p_v_ctrl2_voice(uint8_t* data, int v_ctrl2_voice);

  // config detail: {'bit': 4, 'description': 'right turn-light 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_RightTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_rightturnlight(uint8_t* data, bool v_ctrl2_rightturnlight);

  // config detail: {'bit': 3, 'description': 'left turn-light 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_LeftTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_leftturnlight(uint8_t* data, bool v_ctrl2_leftturnlight);

  // config detail: {'bit': 2, 'description': 'emergency stop 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_EmergencyStop', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
  void set_p_v_ctrl2_emergencystop(uint8_t* data, bool v_ctrl2_emergencystop);

 private:
  int v_ctrl2_autolight_;
  bool v_ctrl2_rightmarkerlight_;
  bool v_ctrl2_leftmarkerlight_;
  int v_ctrl2_statuslight_;
  int v_ctrl2_screen_;
  bool v_ctrl2_headlight_;
  bool v_ctrl2_brakelight_;
  Vcu_ctrl2_2a2::Signal_source_Type v_ctrl2_signalsource_;
  Vcu_ctrl2_2a2::Signal_control_Type v_ctrl2_signalenable_;
  int v_ctrl2_horn_;
  int v_ctrl2_voice_;
  bool v_ctrl2_rightturnlight_;
  bool v_ctrl2_leftturnlight_;
  bool v_ctrl2_emergencystop_;
};

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo


