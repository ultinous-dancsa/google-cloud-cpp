// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_TESTING_MOCK_DATA_CLIENT_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_TESTING_MOCK_DATA_CLIENT_H

#include "google/cloud/bigtable/table.h"
#include <gmock/gmock.h>
#include <string>
// TODO(#8800) - delete this class when deprecation is complete
#include "google/cloud/internal/disable_deprecation_warnings.inc"

namespace google {
namespace cloud {
namespace bigtable {
namespace testing {

class MockDataClient : public bigtable::DataClient {
 public:
  MockDataClient() = default;

  explicit MockDataClient(Options options) : options_(std::move(options)) {}

  /// @deprecated use constructor that takes `google::cloud::Options`
  explicit MockDataClient(ClientOptions options)
      : options_(internal::MakeOptions(std::move(options))) {}

  MOCK_METHOD(std::string const&, project_id, (), (const, override));
  MOCK_METHOD(std::string const&, instance_id, (), (const, override));
  MOCK_METHOD(std::shared_ptr<grpc::Channel>, Channel, (), (override));
  MOCK_METHOD(void, reset, (), (override));

  MOCK_METHOD(grpc::Status, MutateRow,
              (grpc::ClientContext*,
               google::bigtable::v2::MutateRowRequest const&,
               google::bigtable::v2::MutateRowResponse*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncResponseReaderInterface<
                  google::bigtable::v2::MutateRowResponse>>,
              AsyncMutateRow,
              (grpc::ClientContext*,
               google::bigtable::v2::MutateRowRequest const&,
               grpc::CompletionQueue*),
              (override));
  MOCK_METHOD(grpc::Status, CheckAndMutateRow,
              (grpc::ClientContext*,
               google::bigtable::v2::CheckAndMutateRowRequest const&,
               google::bigtable::v2::CheckAndMutateRowResponse*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncResponseReaderInterface<
                  google::bigtable::v2::CheckAndMutateRowResponse>>,
              AsyncCheckAndMutateRow,
              (grpc::ClientContext*,
               google::bigtable::v2::CheckAndMutateRowRequest const&,
               grpc::CompletionQueue*),
              (override));
  MOCK_METHOD(grpc::Status, ReadModifyWriteRow,
              (grpc::ClientContext*,
               google::bigtable::v2::ReadModifyWriteRowRequest const&,
               google::bigtable::v2::ReadModifyWriteRowResponse*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncResponseReaderInterface<
                  google::bigtable::v2::ReadModifyWriteRowResponse>>,
              AsyncReadModifyWriteRow,
              (grpc::ClientContext*,
               google::bigtable::v2::ReadModifyWriteRowRequest const&,
               grpc::CompletionQueue*),
              (override));
  MOCK_METHOD(
      std::unique_ptr<
          grpc::ClientReaderInterface<google::bigtable::v2::ReadRowsResponse>>,
      ReadRows,
      (grpc::ClientContext*, google::bigtable::v2::ReadRowsRequest const&),
      (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncReaderInterface<
                  google::bigtable::v2::ReadRowsResponse>>,
              AsyncReadRows,
              (grpc::ClientContext*,
               google::bigtable::v2::ReadRowsRequest const&,
               grpc::CompletionQueue*, void*),
              (override));
  MOCK_METHOD(std::unique_ptr<::grpc::ClientAsyncReaderInterface<
                  ::google::bigtable::v2::ReadRowsResponse>>,
              PrepareAsyncReadRows,
              (::grpc::ClientContext*,
               ::google::bigtable::v2::ReadRowsRequest const&,
               ::grpc::CompletionQueue*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientReaderInterface<
                  google::bigtable::v2::SampleRowKeysResponse>>,
              SampleRowKeys,
              (grpc::ClientContext*,
               google::bigtable::v2::SampleRowKeysRequest const&),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncReaderInterface<
                  google::bigtable::v2::SampleRowKeysResponse>>,
              AsyncSampleRowKeys,
              (grpc::ClientContext*,
               google::bigtable::v2::SampleRowKeysRequest const&,
               grpc::CompletionQueue*, void*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncReaderInterface<
                  google::bigtable::v2::SampleRowKeysResponse>>,
              PrepareAsyncSampleRowKeys,
              (grpc::ClientContext*,
               google::bigtable::v2::SampleRowKeysRequest const&,
               grpc::CompletionQueue*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientReaderInterface<
                  google::bigtable::v2::MutateRowsResponse>>,
              MutateRows,
              (grpc::ClientContext*,
               google::bigtable::v2::MutateRowsRequest const&),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncReaderInterface<
                  google::bigtable::v2::MutateRowsResponse>>,
              AsyncMutateRows,
              (grpc::ClientContext*,
               google::bigtable::v2::MutateRowsRequest const&,
               grpc::CompletionQueue*, void*),
              (override));
  MOCK_METHOD(std::unique_ptr<grpc::ClientAsyncReaderInterface<
                  google::bigtable::v2::MutateRowsResponse>>,
              PrepareAsyncMutateRows,
              (grpc::ClientContext*,
               google::bigtable::v2::MutateRowsRequest const&,
               grpc::CompletionQueue*),
              (override));

 private:
  google::cloud::BackgroundThreadsFactory BackgroundThreadsFactory() override {
    return google::cloud::internal::MakeBackgroundThreadsFactory(options_);
  }

  Options options_;
};

}  // namespace testing
}  // namespace bigtable
}  // namespace cloud
}  // namespace google

// TODO(#8800) - delete this class when deprecation is complete
#include "google/cloud/internal/diagnostics_pop.inc"

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_BIGTABLE_TESTING_MOCK_DATA_CLIENT_H
