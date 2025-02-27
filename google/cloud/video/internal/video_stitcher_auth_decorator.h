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
// source: google/cloud/video/stitcher/v1/video_stitcher_service.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VIDEO_INTERNAL_VIDEO_STITCHER_AUTH_DECORATOR_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VIDEO_INTERNAL_VIDEO_STITCHER_AUTH_DECORATOR_H

#include "google/cloud/video/internal/video_stitcher_stub.h"
#include "google/cloud/internal/unified_grpc_credentials.h"
#include "google/cloud/version.h"
#include <memory>
#include <set>
#include <string>

namespace google {
namespace cloud {
namespace video_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class VideoStitcherServiceAuth : public VideoStitcherServiceStub {
 public:
  ~VideoStitcherServiceAuth() override = default;
  VideoStitcherServiceAuth(
      std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth,
      std::shared_ptr<VideoStitcherServiceStub> child);

  StatusOr<google::cloud::video::stitcher::v1::CdnKey> CreateCdnKey(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::CreateCdnKeyRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::ListCdnKeysResponse> ListCdnKeys(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::ListCdnKeysRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::CdnKey> GetCdnKey(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetCdnKeyRequest const& request)
      override;

  Status DeleteCdnKey(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::DeleteCdnKeyRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::CdnKey> UpdateCdnKey(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::UpdateCdnKeyRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::VodSession> CreateVodSession(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::CreateVodSessionRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::VodSession> GetVodSession(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetVodSessionRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::ListVodStitchDetailsResponse>
  ListVodStitchDetails(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::ListVodStitchDetailsRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::VodStitchDetail>
  GetVodStitchDetail(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetVodStitchDetailRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::ListVodAdTagDetailsResponse>
  ListVodAdTagDetails(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::ListVodAdTagDetailsRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::VodAdTagDetail>
  GetVodAdTagDetail(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetVodAdTagDetailRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::ListLiveAdTagDetailsResponse>
  ListLiveAdTagDetails(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::ListLiveAdTagDetailsRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::LiveAdTagDetail>
  GetLiveAdTagDetail(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetLiveAdTagDetailRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::Slate> CreateSlate(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::CreateSlateRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::ListSlatesResponse> ListSlates(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::ListSlatesRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::Slate> GetSlate(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetSlateRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::Slate> UpdateSlate(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::UpdateSlateRequest const& request)
      override;

  Status DeleteSlate(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::DeleteSlateRequest const& request)
      override;

  StatusOr<google::cloud::video::stitcher::v1::LiveSession> CreateLiveSession(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::CreateLiveSessionRequest const&
          request) override;

  StatusOr<google::cloud::video::stitcher::v1::LiveSession> GetLiveSession(
      grpc::ClientContext& context,
      google::cloud::video::stitcher::v1::GetLiveSessionRequest const& request)
      override;

 private:
  std::shared_ptr<google::cloud::internal::GrpcAuthenticationStrategy> auth_;
  std::shared_ptr<VideoStitcherServiceStub> child_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace video_internal
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_VIDEO_INTERNAL_VIDEO_STITCHER_AUTH_DECORATOR_H
