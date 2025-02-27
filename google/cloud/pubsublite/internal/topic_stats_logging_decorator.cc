// Copyright 2022 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Generated by the Codegen C++ plugin.
// If you make any local changes, they will be lost.
// source: google/cloud/pubsublite/v1/topic_stats.proto

#include "google/cloud/pubsublite/internal/topic_stats_logging_decorator.h"
#include "google/cloud/internal/log_wrapper.h"
#include "google/cloud/status_or.h"
#include <google/cloud/pubsublite/v1/topic_stats.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace pubsublite_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

TopicStatsServiceLogging::TopicStatsServiceLogging(
    std::shared_ptr<TopicStatsServiceStub> child,
    TracingOptions tracing_options, std::set<std::string> components)
    : child_(std::move(child)),
      tracing_options_(std::move(tracing_options)),
      components_(std::move(components)) {}

StatusOr<google::cloud::pubsublite::v1::ComputeMessageStatsResponse>
TopicStatsServiceLogging::ComputeMessageStats(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ComputeMessageStatsRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::pubsublite::v1::ComputeMessageStatsRequest const&
                 request) {
        return child_->ComputeMessageStats(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::pubsublite::v1::ComputeHeadCursorResponse>
TopicStatsServiceLogging::ComputeHeadCursor(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ComputeHeadCursorRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::pubsublite::v1::ComputeHeadCursorRequest const&
                 request) {
        return child_->ComputeHeadCursor(context, request);
      },
      context, request, __func__, tracing_options_);
}

StatusOr<google::cloud::pubsublite::v1::ComputeTimeCursorResponse>
TopicStatsServiceLogging::ComputeTimeCursor(
    grpc::ClientContext& context,
    google::cloud::pubsublite::v1::ComputeTimeCursorRequest const& request) {
  return google::cloud::internal::LogWrapper(
      [this](grpc::ClientContext& context,
             google::cloud::pubsublite::v1::ComputeTimeCursorRequest const&
                 request) {
        return child_->ComputeTimeCursor(context, request);
      },
      context, request, __func__, tracing_options_);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace pubsublite_internal
}  // namespace cloud
}  // namespace google
