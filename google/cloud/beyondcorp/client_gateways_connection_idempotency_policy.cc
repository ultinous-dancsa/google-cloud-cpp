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
// source:
// google/cloud/beyondcorp/clientgateways/v1/client_gateways_service.proto

#include "google/cloud/beyondcorp/client_gateways_connection_idempotency_policy.h"
#include "absl/memory/memory.h"
#include <memory>

namespace google {
namespace cloud {
namespace beyondcorp {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

using ::google::cloud::Idempotency;

ClientGatewaysServiceConnectionIdempotencyPolicy::
    ~ClientGatewaysServiceConnectionIdempotencyPolicy() = default;

namespace {
class DefaultClientGatewaysServiceConnectionIdempotencyPolicy
    : public ClientGatewaysServiceConnectionIdempotencyPolicy {
 public:
  ~DefaultClientGatewaysServiceConnectionIdempotencyPolicy() override = default;

  /// Create a new copy of this object.
  std::unique_ptr<ClientGatewaysServiceConnectionIdempotencyPolicy> clone()
      const override {
    return absl::make_unique<
        DefaultClientGatewaysServiceConnectionIdempotencyPolicy>(*this);
  }

  Idempotency ListClientGateways(
      google::cloud::beyondcorp::clientgateways::v1::ListClientGatewaysRequest)
      override {
    return Idempotency::kIdempotent;
  }

  Idempotency GetClientGateway(google::cloud::beyondcorp::clientgateways::v1::
                                   GetClientGatewayRequest const&) override {
    return Idempotency::kIdempotent;
  }

  Idempotency CreateClientGateway(
      google::cloud::beyondcorp::clientgateways::v1::
          CreateClientGatewayRequest const&) override {
    return Idempotency::kNonIdempotent;
  }

  Idempotency DeleteClientGateway(
      google::cloud::beyondcorp::clientgateways::v1::
          DeleteClientGatewayRequest const&) override {
    return Idempotency::kNonIdempotent;
  }
};
}  // namespace

std::unique_ptr<ClientGatewaysServiceConnectionIdempotencyPolicy>
MakeDefaultClientGatewaysServiceConnectionIdempotencyPolicy() {
  return absl::make_unique<
      DefaultClientGatewaysServiceConnectionIdempotencyPolicy>();
}

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace beyondcorp
}  // namespace cloud
}  // namespace google
