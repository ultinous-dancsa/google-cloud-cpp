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
// source: google/monitoring/v3/alert_service.proto

#include "google/cloud/monitoring/internal/alert_policy_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/monitoring/v3/alert_service.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace monitoring_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

AlertPolicyServiceStub::~AlertPolicyServiceStub() = default;

StatusOr<google::monitoring::v3::ListAlertPoliciesResponse>
DefaultAlertPolicyServiceStub::ListAlertPolicies(
    grpc::ClientContext& client_context,
    google::monitoring::v3::ListAlertPoliciesRequest const& request) {
  google::monitoring::v3::ListAlertPoliciesResponse response;
  auto status =
      grpc_stub_->ListAlertPolicies(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::AlertPolicy>
DefaultAlertPolicyServiceStub::GetAlertPolicy(
    grpc::ClientContext& client_context,
    google::monitoring::v3::GetAlertPolicyRequest const& request) {
  google::monitoring::v3::AlertPolicy response;
  auto status = grpc_stub_->GetAlertPolicy(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::monitoring::v3::AlertPolicy>
DefaultAlertPolicyServiceStub::CreateAlertPolicy(
    grpc::ClientContext& client_context,
    google::monitoring::v3::CreateAlertPolicyRequest const& request) {
  google::monitoring::v3::AlertPolicy response;
  auto status =
      grpc_stub_->CreateAlertPolicy(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

Status DefaultAlertPolicyServiceStub::DeleteAlertPolicy(
    grpc::ClientContext& client_context,
    google::monitoring::v3::DeleteAlertPolicyRequest const& request) {
  google::protobuf::Empty response;
  auto status =
      grpc_stub_->DeleteAlertPolicy(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return google::cloud::Status();
}

StatusOr<google::monitoring::v3::AlertPolicy>
DefaultAlertPolicyServiceStub::UpdateAlertPolicy(
    grpc::ClientContext& client_context,
    google::monitoring::v3::UpdateAlertPolicyRequest const& request) {
  google::monitoring::v3::AlertPolicy response;
  auto status =
      grpc_stub_->UpdateAlertPolicy(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace monitoring_internal
}  // namespace cloud
}  // namespace google
