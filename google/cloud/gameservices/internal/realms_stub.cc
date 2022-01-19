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
// source: google/cloud/gaming/v1/realms_service.proto

#include "google/cloud/gameservices/internal/realms_stub.h"
#include "google/cloud/grpc_error_delegate.h"
#include "google/cloud/status_or.h"
#include <google/cloud/gaming/v1/realms_service.grpc.pb.h>
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace gameservices_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

RealmsServiceStub::~RealmsServiceStub() = default;

StatusOr<google::cloud::gaming::v1::ListRealmsResponse>
DefaultRealmsServiceStub::ListRealms(
    grpc::ClientContext& client_context,
    google::cloud::gaming::v1::ListRealmsRequest const& request) {
  google::cloud::gaming::v1::ListRealmsResponse response;
  auto status = grpc_stub_->ListRealms(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

StatusOr<google::cloud::gaming::v1::Realm> DefaultRealmsServiceStub::GetRealm(
    grpc::ClientContext& client_context,
    google::cloud::gaming::v1::GetRealmRequest const& request) {
  google::cloud::gaming::v1::Realm response;
  auto status = grpc_stub_->GetRealm(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultRealmsServiceStub::AsyncCreateRealm(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::gaming::v1::CreateRealmRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::gaming::v1::CreateRealmRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncCreateRealm(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultRealmsServiceStub::AsyncDeleteRealm(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::gaming::v1::DeleteRealmRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::gaming::v1::DeleteRealmRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncDeleteRealm(context, request, cq);
      },
      request, std::move(context));
}

future<StatusOr<google::longrunning::Operation>>
DefaultRealmsServiceStub::AsyncUpdateRealm(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::gaming::v1::UpdateRealmRequest const& request) {
  return cq.MakeUnaryRpc(
      [this](grpc::ClientContext* context,
             google::cloud::gaming::v1::UpdateRealmRequest const& request,
             grpc::CompletionQueue* cq) {
        return grpc_stub_->AsyncUpdateRealm(context, request, cq);
      },
      request, std::move(context));
}

StatusOr<google::cloud::gaming::v1::PreviewRealmUpdateResponse>
DefaultRealmsServiceStub::PreviewRealmUpdate(
    grpc::ClientContext& client_context,
    google::cloud::gaming::v1::PreviewRealmUpdateRequest const& request) {
  google::cloud::gaming::v1::PreviewRealmUpdateResponse response;
  auto status =
      grpc_stub_->PreviewRealmUpdate(&client_context, request, &response);
  if (!status.ok()) {
    return google::cloud::MakeStatusFromRpcError(status);
  }
  return response;
}

future<StatusOr<google::longrunning::Operation>>
DefaultRealmsServiceStub::AsyncGetOperation(
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

future<Status> DefaultRealmsServiceStub::AsyncCancelOperation(
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
}  // namespace gameservices_internal
}  // namespace cloud
}  // namespace google
