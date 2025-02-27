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
// source: google/devtools/clouddebugger/v2/controller.proto

#include "google/cloud/debugger/internal/controller2_metadata_decorator.h"
#include "google/cloud/common_options.h"
#include "google/cloud/internal/api_client_header.h"
#include "google/cloud/status_or.h"
#include <google/devtools/clouddebugger/v2/controller.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace debugger_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

Controller2Metadata::Controller2Metadata(std::shared_ptr<Controller2Stub> child)
    : child_(std::move(child)),
      api_client_header_(
          google::cloud::internal::ApiClientHeader("generator")) {}

StatusOr<google::devtools::clouddebugger::v2::RegisterDebuggeeResponse>
Controller2Metadata::RegisterDebuggee(
    grpc::ClientContext& context,
    google::devtools::clouddebugger::v2::RegisterDebuggeeRequest const&
        request) {
  SetMetadata(context);
  return child_->RegisterDebuggee(context, request);
}

StatusOr<google::devtools::clouddebugger::v2::ListActiveBreakpointsResponse>
Controller2Metadata::ListActiveBreakpoints(
    grpc::ClientContext& context,
    google::devtools::clouddebugger::v2::ListActiveBreakpointsRequest const&
        request) {
  SetMetadata(context);
  return child_->ListActiveBreakpoints(context, request);
}

StatusOr<google::devtools::clouddebugger::v2::UpdateActiveBreakpointResponse>
Controller2Metadata::UpdateActiveBreakpoint(
    grpc::ClientContext& context,
    google::devtools::clouddebugger::v2::UpdateActiveBreakpointRequest const&
        request) {
  SetMetadata(context);
  return child_->UpdateActiveBreakpoint(context, request);
}

void Controller2Metadata::SetMetadata(grpc::ClientContext& context,
                                      std::string const& request_params) {
  context.AddMetadata("x-goog-request-params", request_params);
  SetMetadata(context);
}

void Controller2Metadata::SetMetadata(grpc::ClientContext& context) {
  context.AddMetadata("x-goog-api-client", api_client_header_);
  auto const& options = internal::CurrentOptions();
  if (options.has<UserProjectOption>()) {
    context.AddMetadata("x-goog-user-project",
                        options.get<UserProjectOption>());
  }
  auto const& authority = options.get<AuthorityOption>();
  if (!authority.empty()) context.set_authority(authority);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace debugger_internal
}  // namespace cloud
}  // namespace google
