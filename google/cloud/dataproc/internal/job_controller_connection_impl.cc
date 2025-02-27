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
// source: google/cloud/dataproc/v1/jobs.proto

#include "google/cloud/dataproc/internal/job_controller_connection_impl.h"
#include "google/cloud/dataproc/internal/job_controller_option_defaults.h"
#include "google/cloud/background_threads.h"
#include "google/cloud/common_options.h"
#include "google/cloud/grpc_options.h"
#include "google/cloud/internal/async_long_running_operation.h"
#include "google/cloud/internal/pagination_range.h"
#include "google/cloud/internal/retry_loop.h"
#include <memory>

namespace google {
namespace cloud {
namespace dataproc_internal {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

JobControllerConnectionImpl::JobControllerConnectionImpl(
    std::unique_ptr<google::cloud::BackgroundThreads> background,
    std::shared_ptr<dataproc_internal::JobControllerStub> stub, Options options)
    : background_(std::move(background)),
      stub_(std::move(stub)),
      options_(internal::MergeOptions(std::move(options),
                                      JobControllerConnection::options())) {}

StatusOr<google::cloud::dataproc::v1::Job>
JobControllerConnectionImpl::SubmitJob(
    google::cloud::dataproc::v1::SubmitJobRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->SubmitJob(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataproc::v1::SubmitJobRequest const& request) {
        return stub_->SubmitJob(context, request);
      },
      request, __func__);
}

future<StatusOr<google::cloud::dataproc::v1::Job>>
JobControllerConnectionImpl::SubmitJobAsOperation(
    google::cloud::dataproc::v1::SubmitJobRequest const& request) {
  auto& stub = stub_;
  return google::cloud::internal::AsyncLongRunningOperation<
      google::cloud::dataproc::v1::Job>(
      background_->cq(), request,
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::cloud::dataproc::v1::SubmitJobRequest const& request) {
        return stub->AsyncSubmitJobAsOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::GetOperationRequest const& request) {
        return stub->AsyncGetOperation(cq, std::move(context), request);
      },
      [stub](google::cloud::CompletionQueue& cq,
             std::unique_ptr<grpc::ClientContext> context,
             google::longrunning::CancelOperationRequest const& request) {
        return stub->AsyncCancelOperation(cq, std::move(context), request);
      },
      &google::cloud::internal::ExtractLongRunningResultResponse<
          google::cloud::dataproc::v1::Job>,
      retry_policy(), backoff_policy(),
      idempotency_policy()->SubmitJobAsOperation(request), polling_policy(),
      __func__);
}

StatusOr<google::cloud::dataproc::v1::Job> JobControllerConnectionImpl::GetJob(
    google::cloud::dataproc::v1::GetJobRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(), idempotency_policy()->GetJob(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataproc::v1::GetJobRequest const& request) {
        return stub_->GetJob(context, request);
      },
      request, __func__);
}

StreamRange<google::cloud::dataproc::v1::Job>
JobControllerConnectionImpl::ListJobs(
    google::cloud::dataproc::v1::ListJobsRequest request) {
  request.clear_page_token();
  auto& stub = stub_;
  auto retry =
      std::shared_ptr<dataproc::JobControllerRetryPolicy const>(retry_policy());
  auto backoff = std::shared_ptr<BackoffPolicy const>(backoff_policy());
  auto idempotency = idempotency_policy()->ListJobs(request);
  char const* function_name = __func__;
  return google::cloud::internal::MakePaginationRange<
      StreamRange<google::cloud::dataproc::v1::Job>>(
      std::move(request),
      [stub, retry, backoff, idempotency,
       function_name](google::cloud::dataproc::v1::ListJobsRequest const& r) {
        return google::cloud::internal::RetryLoop(
            retry->clone(), backoff->clone(), idempotency,
            [stub](
                grpc::ClientContext& context,
                google::cloud::dataproc::v1::ListJobsRequest const& request) {
              return stub->ListJobs(context, request);
            },
            r, function_name);
      },
      [](google::cloud::dataproc::v1::ListJobsResponse r) {
        std::vector<google::cloud::dataproc::v1::Job> result(r.jobs().size());
        auto& messages = *r.mutable_jobs();
        std::move(messages.begin(), messages.end(), result.begin());
        return result;
      });
}

StatusOr<google::cloud::dataproc::v1::Job>
JobControllerConnectionImpl::UpdateJob(
    google::cloud::dataproc::v1::UpdateJobRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->UpdateJob(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataproc::v1::UpdateJobRequest const& request) {
        return stub_->UpdateJob(context, request);
      },
      request, __func__);
}

StatusOr<google::cloud::dataproc::v1::Job>
JobControllerConnectionImpl::CancelJob(
    google::cloud::dataproc::v1::CancelJobRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->CancelJob(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataproc::v1::CancelJobRequest const& request) {
        return stub_->CancelJob(context, request);
      },
      request, __func__);
}

Status JobControllerConnectionImpl::DeleteJob(
    google::cloud::dataproc::v1::DeleteJobRequest const& request) {
  return google::cloud::internal::RetryLoop(
      retry_policy(), backoff_policy(),
      idempotency_policy()->DeleteJob(request),
      [this](grpc::ClientContext& context,
             google::cloud::dataproc::v1::DeleteJobRequest const& request) {
        return stub_->DeleteJob(context, request);
      },
      request, __func__);
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dataproc_internal
}  // namespace cloud
}  // namespace google
