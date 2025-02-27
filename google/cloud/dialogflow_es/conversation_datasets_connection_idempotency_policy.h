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
// source: google/cloud/dialogflow/v2/conversation_dataset.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATION_DATASETS_CONNECTION_IDEMPOTENCY_POLICY_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATION_DATASETS_CONNECTION_IDEMPOTENCY_POLICY_H

#include "google/cloud/idempotency.h"
#include "google/cloud/internal/retry_policy.h"
#include "google/cloud/version.h"
#include <google/cloud/dialogflow/v2/conversation_dataset.grpc.pb.h>
#include <memory>

namespace google {
namespace cloud {
namespace dialogflow_es {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

class ConversationDatasetsConnectionIdempotencyPolicy {
 public:
  virtual ~ConversationDatasetsConnectionIdempotencyPolicy() = 0;

  /// Create a new copy of this object.
  virtual std::unique_ptr<ConversationDatasetsConnectionIdempotencyPolicy>
  clone() const = 0;

  virtual google::cloud::Idempotency CreateConversationDataset(
      google::cloud::dialogflow::v2::CreateConversationDatasetRequest const&
          request) = 0;

  virtual google::cloud::Idempotency GetConversationDataset(
      google::cloud::dialogflow::v2::GetConversationDatasetRequest const&
          request) = 0;

  virtual google::cloud::Idempotency ListConversationDatasets(
      google::cloud::dialogflow::v2::ListConversationDatasetsRequest
          request) = 0;

  virtual google::cloud::Idempotency DeleteConversationDataset(
      google::cloud::dialogflow::v2::DeleteConversationDatasetRequest const&
          request) = 0;

  virtual google::cloud::Idempotency ImportConversationData(
      google::cloud::dialogflow::v2::ImportConversationDataRequest const&
          request) = 0;
};

std::unique_ptr<ConversationDatasetsConnectionIdempotencyPolicy>
MakeDefaultConversationDatasetsConnectionIdempotencyPolicy();

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_es
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_ES_CONVERSATION_DATASETS_CONNECTION_IDEMPOTENCY_POLICY_H
