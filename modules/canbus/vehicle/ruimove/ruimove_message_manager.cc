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

#include "modules/canbus/vehicle/ruimove/ruimove_message_manager.h"

#include "modules/canbus/vehicle/ruimove/protocol/vcu_ctrl1_2a1.h"
#include "modules/canbus/vehicle/ruimove/protocol/vcu_ctrl2_2a2.h"

#include "modules/canbus/vehicle/ruimove/protocol/ehb_errinfo_620.h"
#include "modules/canbus/vehicle/ruimove/protocol/vcu_state1_2b1.h"
#include "modules/canbus/vehicle/ruimove/protocol/vcu_state2_2b2.h"

namespace apollo {
namespace canbus {
namespace ruimove {

RuimoveMessageManager::RuimoveMessageManager() {
  // Control Messages
  AddSendProtocolData<Vcuctrl12a1, true>();
  AddSendProtocolData<Vcuctrl22a2, true>();

  // Report Messages
  AddRecvProtocolData<Ehberrinfo620, true>();
  AddRecvProtocolData<Vcustate12b1, true>();
  AddRecvProtocolData<Vcustate22b2, true>();
}

RuimoveMessageManager::~RuimoveMessageManager() {}

}  // namespace ruimove
}  // namespace canbus
}  // namespace apollo
