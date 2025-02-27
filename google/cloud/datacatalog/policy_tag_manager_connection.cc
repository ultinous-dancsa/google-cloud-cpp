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
// source: google/cloud/datacatalog/v1/policytagmanager.proto

#include "google/cloud/datacatalog/policy_tag_manager_connection.h"
#include "google/cloud/datacatalog/internal/policy_tag_manager_connection_impl.h"
#include "google/cloud/datacatalog/internal/policy_tag_manager_option_defaults.h"
#include "google/cloud/datacatalog/internal/policy_tag_manager_stub_factory.h"
#include "google/cloud/datacatalog/policy_tag_manager_options.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/credentials.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/pagination_range.h"
#include <memory>

namespace google {
namespace cloud {
namespace datacatalog {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

PolicyTagManagerConnection::~PolicyTagManagerConnection() = default;

StatusOr<google::cloud::datacatalog::v1::Taxonomy>
PolicyTagManagerConnection::CreateTaxonomy(
    google::cloud::datacatalog::v1::CreateTaxonomyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status PolicyTagManagerConnection::DeleteTaxonomy(
    google::cloud::datacatalog::v1::DeleteTaxonomyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::datacatalog::v1::Taxonomy>
PolicyTagManagerConnection::UpdateTaxonomy(
    google::cloud::datacatalog::v1::UpdateTaxonomyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::datacatalog::v1::Taxonomy>
PolicyTagManagerConnection::ListTaxonomies(
    google::cloud::datacatalog::v1::
        ListTaxonomiesRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::datacatalog::v1::Taxonomy>>();
}

StatusOr<google::cloud::datacatalog::v1::Taxonomy>
PolicyTagManagerConnection::GetTaxonomy(
    google::cloud::datacatalog::v1::GetTaxonomyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::datacatalog::v1::PolicyTag>
PolicyTagManagerConnection::CreatePolicyTag(
    google::cloud::datacatalog::v1::CreatePolicyTagRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

Status PolicyTagManagerConnection::DeletePolicyTag(
    google::cloud::datacatalog::v1::DeletePolicyTagRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::cloud::datacatalog::v1::PolicyTag>
PolicyTagManagerConnection::UpdatePolicyTag(
    google::cloud::datacatalog::v1::UpdatePolicyTagRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StreamRange<google::cloud::datacatalog::v1::PolicyTag>
PolicyTagManagerConnection::ListPolicyTags(
    google::cloud::datacatalog::v1::
        ListPolicyTagsRequest) {  // NOLINT(performance-unnecessary-value-param)
  return google::cloud::internal::MakeUnimplementedPaginationRange<
      StreamRange<google::cloud::datacatalog::v1::PolicyTag>>();
}

StatusOr<google::cloud::datacatalog::v1::PolicyTag>
PolicyTagManagerConnection::GetPolicyTag(
    google::cloud::datacatalog::v1::GetPolicyTagRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::iam::v1::Policy> PolicyTagManagerConnection::GetIamPolicy(
    google::iam::v1::GetIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::iam::v1::Policy> PolicyTagManagerConnection::SetIamPolicy(
    google::iam::v1::SetIamPolicyRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

StatusOr<google::iam::v1::TestIamPermissionsResponse>
PolicyTagManagerConnection::TestIamPermissions(
    google::iam::v1::TestIamPermissionsRequest const&) {
  return Status(StatusCode::kUnimplemented, "not implemented");
}

std::shared_ptr<PolicyTagManagerConnection> MakePolicyTagManagerConnection(
    Options options) {
  internal::CheckExpectedOptions<CommonOptionList, GrpcOptionList,
                                 UnifiedCredentialsOptionList,
                                 PolicyTagManagerPolicyOptionList>(options,
                                                                   __func__);
  options =
      datacatalog_internal::PolicyTagManagerDefaultOptions(std::move(options));
  auto background = internal::MakeBackgroundThreadsFactory(options)();
  auto stub = datacatalog_internal::CreateDefaultPolicyTagManagerStub(
      background->cq(), options);
  return std::make_shared<datacatalog_internal::PolicyTagManagerConnectionImpl>(
      std::move(background), std::move(stub), std::move(options));
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace datacatalog
}  // namespace cloud
}  // namespace google
