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

#include "modules/canbus/vehicle/ruimove/protocol/vcu_ctrl2_2a2.h"

#include "modules/drivers/canbus/common/byte.h"

namespace apollo {
namespace canbus {
namespace ruimove {

using ::apollo::drivers::canbus::Byte;

const int32_t Vcuctrl22a2::ID = 0x2A2;

// public
Vcuctrl22a2::Vcuctrl22a2() { Reset(); }

uint32_t Vcuctrl22a2::GetPeriod() const {
  // TODO(All) :  modify every protocol's period manually
  static const uint32_t PERIOD = 20 * 1000;
  return PERIOD;
}

void Vcuctrl22a2::UpdateData(uint8_t* data) {
  set_p_v_ctrl2_autolight(data, v_ctrl2_autolight_);
  set_p_v_ctrl2_rightmarkerlight(data, v_ctrl2_rightmarkerlight_);
  set_p_v_ctrl2_leftmarkerlight(data, v_ctrl2_leftmarkerlight_);
  set_p_v_ctrl2_statuslight(data, v_ctrl2_statuslight_);
  set_p_v_ctrl2_screen(data, v_ctrl2_screen_);
  set_p_v_ctrl2_headlight(data, v_ctrl2_headlight_);
  set_p_v_ctrl2_brakelight(data, v_ctrl2_brakelight_);
  set_p_v_ctrl2_signalsource(data, v_ctrl2_signalsource_);
  set_p_v_ctrl2_signalenable(data, v_ctrl2_signalenable_);
  set_p_v_ctrl2_horn(data, v_ctrl2_horn_);
  set_p_v_ctrl2_voice(data, v_ctrl2_voice_);
  set_p_v_ctrl2_rightturnlight(data, v_ctrl2_rightturnlight_);
  set_p_v_ctrl2_leftturnlight(data, v_ctrl2_leftturnlight_);
  set_p_v_ctrl2_emergencystop(data, v_ctrl2_emergencystop_);
}

void Vcuctrl22a2::Reset() {
  // TODO(All) :  you should check this manually
  v_ctrl2_autolight_ = 0;
  v_ctrl2_rightmarkerlight_ = false;
  v_ctrl2_leftmarkerlight_ = false;
  v_ctrl2_statuslight_ = 0;
  v_ctrl2_screen_ = 0;
  v_ctrl2_headlight_ = false;
  v_ctrl2_brakelight_ = false;
  v_ctrl2_signalsource_ = Vcu_ctrl2_2a2::SIGNAL_SOURCE_FROM_RCU;
  v_ctrl2_signalenable_ = Vcu_ctrl2_2a2::SIGNAL_CONTROL_DISABLE;
  v_ctrl2_horn_ = 0;
  v_ctrl2_voice_ = 0;
  v_ctrl2_rightturnlight_ = false;
  v_ctrl2_leftturnlight_ = false;
  v_ctrl2_emergencystop_ = false;
}

Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_autolight(
    int v_ctrl2_autolight) {
  v_ctrl2_autolight_ = v_ctrl2_autolight;
  return this;
 }

// config detail: {'bit': 32, 'is_signed_var': False, 'len': 4, 'name': 'V_Ctrl2_AutoLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vcuctrl22a2::set_p_v_ctrl2_autolight(uint8_t* data,
    int v_ctrl2_autolight) {
  v_ctrl2_autolight = ProtocolData::BoundedValue(0, 0, v_ctrl2_autolight);
  int x = v_ctrl2_autolight;

  Byte to_set(data + 4);
  to_set.set_value(x, 0, 4);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_rightmarkerlight(
    bool v_ctrl2_rightmarkerlight) {
  v_ctrl2_rightmarkerlight_ = v_ctrl2_rightmarkerlight;
  return this;
 }

// config detail: {'bit': 10, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_RightMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_rightmarkerlight(uint8_t* data,
    bool v_ctrl2_rightmarkerlight) {
  int x = v_ctrl2_rightmarkerlight;

  Byte to_set(data + 1);
  to_set.set_value(x, 2, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_leftmarkerlight(
    bool v_ctrl2_leftmarkerlight) {
  v_ctrl2_leftmarkerlight_ = v_ctrl2_leftmarkerlight;
  return this;
 }

// config detail: {'bit': 9, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_LeftMarkerLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_leftmarkerlight(uint8_t* data,
    bool v_ctrl2_leftmarkerlight) {
  int x = v_ctrl2_leftmarkerlight;

  Byte to_set(data + 1);
  to_set.set_value(x, 1, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_statuslight(
    int v_ctrl2_statuslight) {
  v_ctrl2_statuslight_ = v_ctrl2_statuslight;
  return this;
 }

// config detail: {'bit': 6, 'is_signed_var': False, 'len': 2, 'name': 'V_Ctrl2_StatusLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vcuctrl22a2::set_p_v_ctrl2_statuslight(uint8_t* data,
    int v_ctrl2_statuslight) {
  v_ctrl2_statuslight = ProtocolData::BoundedValue(0, 0, v_ctrl2_statuslight);
  int x = v_ctrl2_statuslight;

  Byte to_set(data + 0);
  to_set.set_value(x, 6, 2);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_screen(
    int v_ctrl2_screen) {
  v_ctrl2_screen_ = v_ctrl2_screen;
  return this;
 }

// config detail: {'bit': 16, 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl2_Screen', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vcuctrl22a2::set_p_v_ctrl2_screen(uint8_t* data,
    int v_ctrl2_screen) {
  v_ctrl2_screen = ProtocolData::BoundedValue(0, 0, v_ctrl2_screen);
  int x = v_ctrl2_screen;

  Byte to_set(data + 2);
  to_set.set_value(x, 0, 8);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_headlight(
    bool v_ctrl2_headlight) {
  v_ctrl2_headlight_ = v_ctrl2_headlight;
  return this;
 }

// config detail: {'bit': 5, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_Headlight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_headlight(uint8_t* data,
    bool v_ctrl2_headlight) {
  int x = v_ctrl2_headlight;

  Byte to_set(data + 0);
  to_set.set_value(x, 5, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_brakelight(
    bool v_ctrl2_brakelight) {
  v_ctrl2_brakelight_ = v_ctrl2_brakelight;
  return this;
 }

// config detail: {'bit': 8, 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_BrakeLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_brakelight(uint8_t* data,
    bool v_ctrl2_brakelight) {
  int x = v_ctrl2_brakelight;

  Byte to_set(data + 1);
  to_set.set_value(x, 0, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_signalsource(
    Vcu_ctrl2_2a2::Signal_source_Type v_ctrl2_signalsource) {
  v_ctrl2_signalsource_ = v_ctrl2_signalsource;
  return this;
 }

// config detail: {'bit': 0, 'description': '0:ACU; 1:RCU', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_SignalSource', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_signalsource(uint8_t* data,
    Vcu_ctrl2_2a2::Signal_source_Type v_ctrl2_signalsource) {
  int x = v_ctrl2_signalsource;

  Byte to_set(data + 0);
  to_set.set_value(x, 0, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_signalenable(
    Vcu_ctrl2_2a2::Signal_control_Type v_ctrl2_signalenable) {
  v_ctrl2_signalenable_ = v_ctrl2_signalenable;
  return this;
 }

// config detail: {'bit': 1, 'description': '0:disabled; 1:enabled', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_SignalEnable', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_signalenable(uint8_t* data,
    Vcu_ctrl2_2a2::Signal_control_Type v_ctrl2_signalenable) {
  int x = v_ctrl2_signalenable;

  Byte to_set(data + 0);
  to_set.set_value(x, 1, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_horn(
    int v_ctrl2_horn) {
  v_ctrl2_horn_ = v_ctrl2_horn;
  return this;
 }

// config detail: {'bit': 11, 'description': 'horn', 'is_signed_var': False, 'len': 4, 'name': 'V_Ctrl2_Horn', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|1]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vcuctrl22a2::set_p_v_ctrl2_horn(uint8_t* data,
    int v_ctrl2_horn) {
  v_ctrl2_horn = ProtocolData::BoundedValue(0, 1, v_ctrl2_horn);
  int x = v_ctrl2_horn;

  Byte to_set(data + 1);
  to_set.set_value(x, 3, 4);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_voice(
    int v_ctrl2_voice) {
  v_ctrl2_voice_ = v_ctrl2_voice;
  return this;
 }

// config detail: {'bit': 24, 'description': 'voice(default:0)    0:none; 1:defined1; 2:defined2; 3:defined3', 'is_signed_var': False, 'len': 8, 'name': 'V_Ctrl2_Voice', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|31]', 'physical_unit': '', 'precision': 1.0, 'type': 'int'}
void Vcuctrl22a2::set_p_v_ctrl2_voice(uint8_t* data,
    int v_ctrl2_voice) {
  v_ctrl2_voice = ProtocolData::BoundedValue(0, 31, v_ctrl2_voice);
  int x = v_ctrl2_voice;

  Byte to_set(data + 3);
  to_set.set_value(x, 0, 8);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_rightturnlight(
    bool v_ctrl2_rightturnlight) {
  v_ctrl2_rightturnlight_ = v_ctrl2_rightturnlight;
  return this;
 }

// config detail: {'bit': 4, 'description': 'right turn-light 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_RightTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_rightturnlight(uint8_t* data,
    bool v_ctrl2_rightturnlight) {
  int x = v_ctrl2_rightturnlight;

  Byte to_set(data + 0);
  to_set.set_value(x, 4, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_leftturnlight(
    bool v_ctrl2_leftturnlight) {
  v_ctrl2_leftturnlight_ = v_ctrl2_leftturnlight;
  return this;
 }

// config detail: {'bit': 3, 'description': 'left turn-light 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_LeftTurnLight', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|0]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_leftturnlight(uint8_t* data,
    bool v_ctrl2_leftturnlight) {
  int x = v_ctrl2_leftturnlight;

  Byte to_set(data + 0);
  to_set.set_value(x, 3, 1);
}


Vcuctrl22a2* Vcuctrl22a2::set_v_ctrl2_emergencystop(
    bool v_ctrl2_emergencystop) {
  v_ctrl2_emergencystop_ = v_ctrl2_emergencystop;
  return this;
 }

// config detail: {'bit': 2, 'description': 'emergency stop 0:close  1:open', 'is_signed_var': False, 'len': 1, 'name': 'V_Ctrl2_EmergencyStop', 'offset': 0.0, 'order': 'intel', 'physical_range': '[0|255]', 'physical_unit': '', 'precision': 1.0, 'type': 'bool'}
void Vcuctrl22a2::set_p_v_ctrl2_emergencystop(uint8_t* data,
    bool v_ctrl2_emergencystop) {
  int x = v_ctrl2_emergencystop;

  Byte to_set(data + 0);
  to_set.set_value(x, 2, 1);
}

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
