/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
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

#ifndef MODULES_DRIVERS_RADAR_RACOBIT_RADAR_PROTOCOL_CLUSTER_GENERAL_INFO_701_H_
#define MODULES_DRIVERS_RADAR_RACOBIT_PROTOCOL_CLUSTER_GENERAL_INFO_701_H_

#include "modules/drivers/canbus/can_comm/protocol_data.h"
#include "modules/drivers/proto/racobit_radar.pb.h"

namespace apollo {
namespace drivers {
namespace racobit_radar {

using apollo::drivers::RacobitRadar;

class ClusterGeneralInfo701
    : public apollo::drivers::canbus::\
    ProtocolData<RacobitRadar> {
 public:
  static const uint32_t ID;
  ClusterGeneralInfo701();
  void Parse(const std::uint8_t* bytes, int32_t length,
             RacobitRadar* racobit_radar) const override;

 private:
  int obstacle_id(const std::uint8_t* bytes, int32_t length) const;

  double longitude_dist(const std::uint8_t* bytes, int32_t length) const;

  double lateral_dist(const std::uint8_t* bytes, int32_t length) const;

  double longitude_vel(const std::uint8_t* bytes, int32_t length) const;

  double lateral_vel(const std::uint8_t* bytes, int32_t length) const;

  double rcs(const std::uint8_t* bytes, int32_t length) const;

  int dynprop(const std::uint8_t* bytes, int32_t length) const;
};

}  // namespace racobit_radar
}  // namespace drivers
}  // namespace apollo
#endif
// MODULES_DRIVERS_RADAR_RACOBIT_RADAR_PROTOCOL_CLUSTER_GENERAL_INFO_701_H
