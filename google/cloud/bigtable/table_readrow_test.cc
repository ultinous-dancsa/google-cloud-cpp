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

#include "google/cloud/bigtable/table.h"
#include "google/cloud/bigtable/testing/mock_read_rows_reader.h"
#include "google/cloud/bigtable/testing/table_test_fixture.h"
#include "google/cloud/testing_util/status_matchers.h"
#include "absl/memory/memory.h"

namespace google {
namespace cloud {
namespace bigtable {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN
namespace {

namespace btproto = ::google::bigtable::v2;
using ::google::cloud::bigtable::testing::MockReadRowsReader;
using ::google::cloud::testing_util::ValidateMetadataFixture;
using ::testing::Return;

class TableReadRowTest : public bigtable::testing::TableTestFixture {
 protected:
  TableReadRowTest() : TableTestFixture(CompletionQueue{}) {}

  void IsContextMDValid(grpc::ClientContext& context, std::string const& method,
                        google::protobuf::Message const& request) {
    return validate_metadata_fixture_.IsContextMDValid(
        context, method, request, google::cloud::internal::ApiClientHeader());
  }

 private:
  ValidateMetadataFixture validate_metadata_fixture_;
};

TEST_F(TableReadRowTest, ReadRowSimple) {
  auto const response = bigtable::testing::ReadRowsResponseFromString(R"(
      chunks {
        row_key: "r1"
        family_name { value: "fam" }
        qualifier { value: "col" }
        timestamp_micros: 42000
        value: "value"
        commit_row: true
      }
)");

  EXPECT_CALL(*client_, ReadRows)
      .WillOnce([&response, this](grpc::ClientContext* context,
                                  btproto::ReadRowsRequest const& req) {
        auto stream = absl::make_unique<MockReadRowsReader>(
            "google.bigtable.v2.Bigtable.ReadRows");
        EXPECT_CALL(*stream, Read)
            .WillOnce([response](btproto::ReadRowsResponse* r) {
              *r = response;
              return true;
            })
            .WillOnce(Return(false));
        EXPECT_CALL(*stream, Finish).WillOnce(Return(grpc::Status::OK));

        IsContextMDValid(*context, "google.bigtable.v2.Bigtable.ReadRows", req);
        EXPECT_EQ(1, req.rows().row_keys_size());
        EXPECT_EQ("r1", req.rows().row_keys(0));
        EXPECT_EQ(1, req.rows_limit());
        EXPECT_EQ(table_.table_name(), req.table_name());
        return stream;
      });

  auto result = table_.ReadRow("r1", bigtable::Filter::PassAllFilter());
  ASSERT_STATUS_OK(result);
  EXPECT_TRUE(std::get<0>(*result));
  auto row = std::get<1>(*result);
  EXPECT_EQ("r1", row.row_key());
}

TEST_F(TableReadRowTest, ReadRowMissing) {
  EXPECT_CALL(*client_, ReadRows)
      .WillOnce([this](grpc::ClientContext* context,
                       btproto::ReadRowsRequest const& req) {
        auto stream = absl::make_unique<MockReadRowsReader>(
            "google.bigtable.v2.Bigtable.ReadRows");
        EXPECT_CALL(*stream, Read).WillOnce(Return(false));
        EXPECT_CALL(*stream, Finish).WillOnce(Return(grpc::Status::OK));

        IsContextMDValid(*context, "google.bigtable.v2.Bigtable.ReadRows", req);
        EXPECT_EQ(1, req.rows().row_keys_size());
        EXPECT_EQ("r1", req.rows().row_keys(0));
        EXPECT_EQ(1, req.rows_limit());
        EXPECT_EQ(table_.table_name(), req.table_name());
        return stream;
      });

  auto result = table_.ReadRow("r1", bigtable::Filter::PassAllFilter());
  ASSERT_STATUS_OK(result);
  EXPECT_FALSE(std::get<0>(*result));
}

TEST_F(TableReadRowTest, UnrecoverableFailure) {
  EXPECT_CALL(*client_, ReadRows)
      .WillRepeatedly([this](grpc::ClientContext* context,
                             btproto::ReadRowsRequest const& request) {
        auto stream = absl::make_unique<MockReadRowsReader>(
            "google.bigtable.v2.Bigtable.ReadRows");
        EXPECT_CALL(*stream, Read).WillRepeatedly(Return(false));
        EXPECT_CALL(*stream, Finish)
            .WillRepeatedly(Return(
                grpc::Status(grpc::StatusCode::PERMISSION_DENIED, "uh oh")));

        IsContextMDValid(*context, "google.bigtable.v2.Bigtable.ReadRows",
                         request);
        return stream;
      });

  auto row = table_.ReadRow("r1", bigtable::Filter::PassAllFilter());
  EXPECT_FALSE(row);
}

}  // anonymous namespace
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace bigtable
}  // namespace cloud
}  // namespace google
