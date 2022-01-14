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
// source: google/cloud/shell/v1/cloudshell.proto

#include "google/cloud/shell/internal/cloud_shell_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/shell/v1/cloudshell.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace shell_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudShellServiceStub::~CloudShellServiceStub() = default;

StatusOr<google::cloud::shell::v1::Environment>
DefaultCloudShellServiceStub::GetEnvironment(
    grpc::ClientContext& client_context,
    google::cloud::shell::v1::GetEnvironmentRequest const& request) {
  google::cloud::shell::v1::Environment response;
  auto status = grpc_stub_->GetEnvironment(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudShellServiceStub::AsyncStartEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::StartEnvironmentRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::shell::v1::StartEnvironmentRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncStartEnvironment(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudShellServiceStub::AsyncAuthorizeEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::AuthorizeEnvironmentRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](
          grpc::ClientContext* context,
          google::cloud::shell::v1::AuthorizeEnvironmentRequest const& request,
          grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncAuthorizeEnvironment(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudShellServiceStub::AsyncAddPublicKey(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::AddPublicKeyRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::shell::v1::AddPublicKeyRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncAddPublicKey(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudShellServiceStub::AsyncRemovePublicKey(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::RemovePublicKeyRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::shell::v1::RemovePublicKeyRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncRemovePublicKey(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultCloudShellServiceStub::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::longrunning::GetOperationRequest const& request,
             grpc::CompletionQueue* cq) {
        return operations_->AsyncGetOperation(context, request, cq);
      },
      request, std::move(context));
}

future<Status> DefaultCloudShellServiceStub::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  return cq
      .MakeUnaryRpc(
          [this](grpc::ClientContext* context,
                 google::longrunning::CancelOperationRequest const& request,
                 grpc::CompletionQueue* cq) {
            return operations_->AsyncCancelOperation(context, request, cq);
          },
          request, std::move(context))
      .then([](future<StatusOr<google::protobuf::Empty>> f) {
        return f.get().status();
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace shell_internal
}  // namespace cloud
}  // namespace google
