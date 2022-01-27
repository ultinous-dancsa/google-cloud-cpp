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
// source: google/devtools/clouddebugger/v2/debugger.proto

#include "google/cloud/debugger/internal/debugger2_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/devtools/clouddebugger/v2/debugger.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace debugger_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

Debugger2Stub::~Debugger2Stub() = default;

StatusOr<google::devtools::clouddebugger::v2::SetBreakpointResponse>
DefaultDebugger2Stub::SetBreakpoint(
    grpc::ClientContext& client_context,
    google::devtools::clouddebugger::v2::SetBreakpointRequest const& request) {
  google::devtools::clouddebugger::v2::SetBreakpointResponse response;
  auto status = grpc_stub_->SetBreakpoint(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::devtools::clouddebugger::v2::GetBreakpointResponse>
DefaultDebugger2Stub::GetBreakpoint(
    grpc::ClientContext& client_context,
    google::devtools::clouddebugger::v2::GetBreakpointRequest const& request) {
  google::devtools::clouddebugger::v2::GetBreakpointResponse response;
  auto status = grpc_stub_->GetBreakpoint(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultDebugger2Stub::DeleteBreakpoint(
    grpc::ClientContext& client_context,
    google::devtools::clouddebugger::v2::DeleteBreakpointRequest const&
        request) {
  google::protobuf::Empty response;
  auto status =
      grpc_stub_->DeleteBreakpoint(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::devtools::clouddebugger::v2::ListBreakpointsResponse>
DefaultDebugger2Stub::ListBreakpoints(
    grpc::ClientContext& client_context,
    google::devtools::clouddebugger::v2::ListBreakpointsRequest const&
        request) {
  google::devtools::clouddebugger::v2::ListBreakpointsResponse response;
  auto status =
      grpc_stub_->ListBreakpoints(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::devtools::clouddebugger::v2::ListDebuggeesResponse>
DefaultDebugger2Stub::ListDebuggees(
    grpc::ClientContext& client_context,
    google::devtools::clouddebugger::v2::ListDebuggeesRequest const& request) {
  google::devtools::clouddebugger::v2::ListDebuggeesResponse response;
  auto status = grpc_stub_->ListDebuggees(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace debugger_internal
}  // namespace cloud
}  // namespace google
