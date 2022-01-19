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
// source: google/cloud/gaming/v1/game_server_deployments_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_GAMESERVICES_INTERNAL_GAME_SERVER_DEPLOYMENTS_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_GAMESERVICES_INTERNAL_GAME_SERVER_DEPLOYMENTS_AUTH_DECORATOR_H

#include "google/cloud/gameservices/internal/game_server_deployments_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace gameservices_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class GameServerDeploymentsServiceAuth
    : public GameServerDeploymentsServiceStub {
 public:
  ~GameServerDeploymentsServiceAuth() override = default;
  GameServerDeploymentsServiceAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<GameServerDeploymentsServiceStub> child);

  StatusOr<google::cloud::gaming::v1::ListGameServerDeploymentsResponse>
  ListGameServerDeployments(
      grpc::ClientContext& context,
      google::cloud::gaming::v1::ListGameServerDeploymentsRequest const&
          request) override;

  StatusOr<google::cloud::gaming::v1::GameServerDeployment>
  GetGameServerDeployment(
      grpc::ClientContext& context,
      google::cloud::gaming::v1::GetGameServerDeploymentRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncCreateGameServerDeployment(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::gaming::v1::CreateGameServerDeploymentRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncDeleteGameServerDeployment(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::gaming::v1::DeleteGameServerDeploymentRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateGameServerDeployment(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::gaming::v1::UpdateGameServerDeploymentRequest const&
          request) override;

  StatusOr<google::cloud::gaming::v1::GameServerDeploymentRollout>
  GetGameServerDeploymentRollout(
      grpc::ClientContext& context,
      google::cloud::gaming::v1::GetGameServerDeploymentRolloutRequest const&
          request) override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncUpdateGameServerDeploymentRollout(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::gaming::v1::UpdateGameServerDeploymentRolloutRequest const&
          request) override;

  StatusOr<
      google::cloud::gaming::v1::PreviewGameServerDeploymentRolloutResponse>
  PreviewGameServerDeploymentRollout(
      grpc::ClientContext& context,
      google::cloud::gaming::v1::
          PreviewGameServerDeploymentRolloutRequest const& request) override;

  StatusOr<google::cloud::gaming::v1::FetchDeploymentStateResponse>
  FetchDeploymentState(
      grpc::ClientContext& context,
      google::cloud::gaming::v1::FetchDeploymentStateRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncGetOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::GetOperationRequest const& request) override;

  future<Status> AsyncCancelOperation(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::longrunning::CancelOperationRequest const& request) override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<GameServerDeploymentsServiceStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace gameservices_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_GAMESERVICES_INTERNAL_GAME_SERVER_DEPLOYMENTS_AUTH_DECORATOR_H
