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
// source: google/cloud/channel/v1/service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CHANNEL_INTERNAL_CLOUD_CHANNEL_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CHANNEL_INTERNAL_CLOUD_CHANNEL_AUTH_DECORATOR_H

#include "google/cloud/channel/internal/cloud_channel_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <google/longrunning/operations.grpc.pb.h>
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace channel_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class CloudChannelServiceAuth : public CloudChannelServiceStub {
 public:
  ~CloudChannelServiceAuth() override = default;
  CloudChannelServiceAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<CloudChannelServiceStub> child);

  StatusOr<google::cloud::channel::v1::ListCustomersResponse> ListCustomers(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListCustomersRequest const& request) override;

  StatusOr<google::cloud::channel::v1::Customer> GetCustomer(
      grpc::ClientContext& context,
      google::cloud::channel::v1::GetCustomerRequest const& request) override;

  StatusOr<google::cloud::channel::v1::CheckCloudIdentityAccountsExistResponse>
  CheckCloudIdentityAccountsExist(
      grpc::ClientContext& context,
      google::cloud::channel::v1::CheckCloudIdentityAccountsExistRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::Customer> CreateCustomer(
      grpc::ClientContext& context,
      google::cloud::channel::v1::CreateCustomerRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::Customer> UpdateCustomer(
      grpc::ClientContext& context,
      google::cloud::channel::v1::UpdateCustomerRequest const& request)
      override;

  Status DeleteCustomer(grpc::ClientContext& context,
                        google::cloud::channel::v1::DeleteCustomerRequest const&
                            request) override;

  StatusOr<google::cloud::channel::v1::Customer> ImportCustomer(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ImportCustomerRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncProvisionCloudIdentity(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::ProvisionCloudIdentityRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::ListEntitlementsResponse>
  ListEntitlements(grpc::ClientContext& context,
                   google::cloud::channel::v1::ListEntitlementsRequest const&
                       request) override;

  StatusOr<google::cloud::channel::v1::ListTransferableSkusResponse>
  ListTransferableSkus(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListTransferableSkusRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::ListTransferableOffersResponse>
  ListTransferableOffers(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListTransferableOffersRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::Entitlement> GetEntitlement(
      grpc::ClientContext& context,
      google::cloud::channel::v1::GetEntitlementRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCreateEntitlement(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::CreateEntitlementRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncChangeParameters(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::ChangeParametersRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncChangeRenewalSettings(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::ChangeRenewalSettingsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncChangeOffer(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::ChangeOfferRequest const& request) override;

  future<StatusOr<google::longrunning::Operation>> AsyncStartPaidService(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::StartPaidServiceRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncSuspendEntitlement(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::SuspendEntitlementRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncCancelEntitlement(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::CancelEntitlementRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncActivateEntitlement(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::ActivateEntitlementRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>> AsyncTransferEntitlements(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::TransferEntitlementsRequest const& request)
      override;

  future<StatusOr<google::longrunning::Operation>>
  AsyncTransferEntitlementsToGoogle(
      google::cloud::CompletionQueue& cq,
      std::unique_ptr<grpc::ClientContext> context,
      google::cloud::channel::v1::TransferEntitlementsToGoogleRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::ListChannelPartnerLinksResponse>
  ListChannelPartnerLinks(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListChannelPartnerLinksRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::ChannelPartnerLink>
  GetChannelPartnerLink(
      grpc::ClientContext& context,
      google::cloud::channel::v1::GetChannelPartnerLinkRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::ChannelPartnerLink>
  CreateChannelPartnerLink(
      grpc::ClientContext& context,
      google::cloud::channel::v1::CreateChannelPartnerLinkRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::ChannelPartnerLink>
  UpdateChannelPartnerLink(
      grpc::ClientContext& context,
      google::cloud::channel::v1::UpdateChannelPartnerLinkRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::CustomerRepricingConfig>
  GetCustomerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::GetCustomerRepricingConfigRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::ListCustomerRepricingConfigsResponse>
  ListCustomerRepricingConfigs(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListCustomerRepricingConfigsRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::CustomerRepricingConfig>
  CreateCustomerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::CreateCustomerRepricingConfigRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::CustomerRepricingConfig>
  UpdateCustomerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::UpdateCustomerRepricingConfigRequest const&
          request) override;

  Status DeleteCustomerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::DeleteCustomerRepricingConfigRequest const&
          request) override;

  StatusOr<google::cloud::channel::v1::ChannelPartnerRepricingConfig>
  GetChannelPartnerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::GetChannelPartnerRepricingConfigRequest const&
          request) override;

  StatusOr<
      google::cloud::channel::v1::ListChannelPartnerRepricingConfigsResponse>
  ListChannelPartnerRepricingConfigs(
      grpc::ClientContext& context,
      google::cloud::channel::v1::
          ListChannelPartnerRepricingConfigsRequest const& request) override;

  StatusOr<google::cloud::channel::v1::ChannelPartnerRepricingConfig>
  CreateChannelPartnerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::
          CreateChannelPartnerRepricingConfigRequest const& request) override;

  StatusOr<google::cloud::channel::v1::ChannelPartnerRepricingConfig>
  UpdateChannelPartnerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::
          UpdateChannelPartnerRepricingConfigRequest const& request) override;

  Status DeleteChannelPartnerRepricingConfig(
      grpc::ClientContext& context,
      google::cloud::channel::v1::
          DeleteChannelPartnerRepricingConfigRequest const& request) override;

  StatusOr<google::cloud::channel::v1::Offer> LookupOffer(
      grpc::ClientContext& context,
      google::cloud::channel::v1::LookupOfferRequest const& request) override;

  StatusOr<google::cloud::channel::v1::ListProductsResponse> ListProducts(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListProductsRequest const& request) override;

  StatusOr<google::cloud::channel::v1::ListSkusResponse> ListSkus(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListSkusRequest const& request) override;

  StatusOr<google::cloud::channel::v1::ListOffersResponse> ListOffers(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListOffersRequest const& request) override;

  StatusOr<google::cloud::channel::v1::ListPurchasableSkusResponse>
  ListPurchasableSkus(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListPurchasableSkusRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::ListPurchasableOffersResponse>
  ListPurchasableOffers(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListPurchasableOffersRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::RegisterSubscriberResponse>
  RegisterSubscriber(
      grpc::ClientContext& context,
      google::cloud::channel::v1::RegisterSubscriberRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::UnregisterSubscriberResponse>
  UnregisterSubscriber(
      grpc::ClientContext& context,
      google::cloud::channel::v1::UnregisterSubscriberRequest const& request)
      override;

  StatusOr<google::cloud::channel::v1::ListSubscribersResponse> ListSubscribers(
      grpc::ClientContext& context,
      google::cloud::channel::v1::ListSubscribersRequest const& request)
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
  std::shared_ptr<CloudChannelServiceStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace channel_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CHANNEL_INTERNAL_CLOUD_CHANNEL_AUTH_DECORATOR_H
