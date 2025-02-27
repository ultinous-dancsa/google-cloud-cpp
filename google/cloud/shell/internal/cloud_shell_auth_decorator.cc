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

#include "google/cloud/shell/internal/cloud_shell_auth_decorator.h"
#include <google/cloud/shell/v1/cloudshell.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace shell_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

CloudShellServiceAuth::CloudShellServiceAuth(
    std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
    std::shared_ptr<CloudShellServiceStub> child)
    : auth_(std::move(auth)), child_(std::move(child)) {}

StatusOr<google::cloud::shell::v1::Environment>
CloudShellServiceAuth::GetEnvironment(
    grpc::ClientContext& context,
    google::cloud::shell::v1::GetEnvironmentRequest const& request) {
  auto status = auth_->ConfigureContext(context);
  if (!status.ok()) return status;
  return child_->GetEnvironment(context, request);
}

future<StatusOr<google::longrunning::Operation>>
CloudShellServiceAuth::AsyncStartEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::StartEnvironmentRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncStartEnvironment(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudShellServiceAuth::AsyncAuthorizeEnvironment(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::AuthorizeEnvironmentRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncAuthorizeEnvironment(cq, *std::move(context),
                                                request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudShellServiceAuth::AsyncAddPublicKey(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::AddPublicKeyRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncAddPublicKey(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudShellServiceAuth::AsyncRemovePublicKey(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::cloud::shell::v1::RemovePublicKeyRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncRemovePublicKey(cq, *std::move(context), request);
      });
}

future<StatusOr<google::longrunning::Operation>>
CloudShellServiceAuth::AsyncGetOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::GetOperationRequest const& request) {
  using ReturnType = StatusOr<google::longrunning::Operation>;
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) {
          return make_ready_future(ReturnType(std::move(context).status()));
        }
        return child->AsyncGetOperation(cq, *std::move(context), request);
      });
}

future<Status> CloudShellServiceAuth::AsyncCancelOperation(
    google::cloud::CompletionQueue& cq,
    std::unique_ptr<grpc::ClientContext> context,
    google::longrunning::CancelOperationRequest const& request) {
  auto& child = child_;
  return auth_->AsyncConfigureContext(std::move(context))
      .then([cq, child,
             request](future<StatusOr<std::unique_ptr<grpc::ClientContext>>>
                          f) mutable {
        auto context = f.get();
        if (!context) return make_ready_future(std::move(context).status());
        return child->AsyncCancelOperation(cq, *std::move(context), request);
      });
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace shell_internal
}  // namespace cloud
}  // namespace google
