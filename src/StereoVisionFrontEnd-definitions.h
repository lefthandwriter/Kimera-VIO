/* ----------------------------------------------------------------------------
 * Copyright 2017, Massachusetts Institute of Technology,
 * Cambridge, MA 02139
 * All Rights Reserved
 * Authors: Luca Carlone, et al. (see THANKS for the full author list)
 * See LICENSE for the license information
 * -------------------------------------------------------------------------- */

/**
 * @file   VioBackEnd-definitions.h
 * @brief  Definitions for VioBackEnd
 * @author Antoni Rosinol
 */

#pragma once

#include "common/vio_types.h"
#include "StereoFrame-definitions.h"
#include "ImuFrontEnd.h"
#include "Tracker.h"

namespace VIO {

using StatusSmartStereoMeasurements =
std::pair<TrackerStatusSummary, SmartStereoMeasurements>;

////////////////////////////////////////////////////////////////////////////////
struct StereoFrontEndOutputPayload {
public:
  // Default ctor sets everything to default and it is used to define an
  // invalid output: meaning we still don't have a keyframe.
  // Note that this should be done with a unique_ptr and only push to the output
  // queue once we have a keyframe.
  StereoFrontEndOutputPayload(
      const bool is_keyframe,
      const StatusSmartStereoMeasurements& statusSmartStereoMeasurements,
      const TrackingStatus& tracker_status,
      const gtsam::Pose3& relative_pose_body_stereo,
      const StereoFrame& stereo_frame_lkf,
      const ImuFrontEnd::PreintegratedImuMeasurements& pim)
    : is_keyframe_(is_keyframe),
      statusSmartStereoMeasurements_(statusSmartStereoMeasurements),
      tracker_status_(tracker_status),
      relative_pose_body_stereo_(relative_pose_body_stereo),
      stereo_frame_lkf_(stereo_frame_lkf),
      pim_(pim) {}

public:
  const bool is_keyframe_;
  const StatusSmartStereoMeasurements statusSmartStereoMeasurements_;
  const TrackingStatus tracker_status_;
  const gtsam::Pose3 relative_pose_body_stereo_;
  const StereoFrame stereo_frame_lkf_;
  const ImuFrontEnd::PreintegratedImuMeasurements pim_;
};


} // End of VIO namespace.
