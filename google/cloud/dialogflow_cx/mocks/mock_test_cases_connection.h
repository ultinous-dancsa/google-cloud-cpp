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
// source: google/cloud/dialogflow/cx/v3/test_case.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_MOCKS_MOCK_TEST_CASES_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_MOCKS_MOCK_TEST_CASES_CONNECTION_H

#include "google/cloud/dialogflow_cx/test_cases_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace dialogflow_cx_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `TestCasesConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `TestCasesClient`. To do so,
 * construct an object of type `TestCasesClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with
 * GoogleTest. While the example showcases types from the BigQuery library, the
 * underlying principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @googleapis_dev_link{bigquery,bigquery-read-mock.html}
 */
class MockTestCasesConnection : public dialogflow_cx::TestCasesConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(StreamRange<google::cloud::dialogflow::cx::v3::TestCase>,
              ListTestCases,
              (google::cloud::dialogflow::cx::v3::ListTestCasesRequest request),
              (override));

  MOCK_METHOD(
      Status, BatchDeleteTestCases,
      (google::cloud::dialogflow::cx::v3::BatchDeleteTestCasesRequest const&
           request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::cx::v3::TestCase>, GetTestCase,
      (google::cloud::dialogflow::cx::v3::GetTestCaseRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::cx::v3::TestCase>, CreateTestCase,
      (google::cloud::dialogflow::cx::v3::CreateTestCaseRequest const& request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::cx::v3::TestCase>, UpdateTestCase,
      (google::cloud::dialogflow::cx::v3::UpdateTestCaseRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<google::cloud::dialogflow::cx::v3::RunTestCaseResponse>>,
      RunTestCase,
      (google::cloud::dialogflow::cx::v3::RunTestCaseRequest const& request),
      (override));

  MOCK_METHOD(
      future<StatusOr<
          google::cloud::dialogflow::cx::v3::BatchRunTestCasesResponse>>,
      BatchRunTestCases,
      (google::cloud::dialogflow::cx::v3::BatchRunTestCasesRequest const&
           request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::cx::v3::CalculateCoverageResponse>,
      CalculateCoverage,
      (google::cloud::dialogflow::cx::v3::CalculateCoverageRequest const&
           request),
      (override));

  MOCK_METHOD(
      future<
          StatusOr<google::cloud::dialogflow::cx::v3::ImportTestCasesResponse>>,
      ImportTestCases,
      (google::cloud::dialogflow::cx::v3::ImportTestCasesRequest const&
           request),
      (override));

  MOCK_METHOD(
      future<
          StatusOr<google::cloud::dialogflow::cx::v3::ExportTestCasesResponse>>,
      ExportTestCases,
      (google::cloud::dialogflow::cx::v3::ExportTestCasesRequest const&
           request),
      (override));

  MOCK_METHOD(
      StreamRange<google::cloud::dialogflow::cx::v3::TestCaseResult>,
      ListTestCaseResults,
      (google::cloud::dialogflow::cx::v3::ListTestCaseResultsRequest request),
      (override));

  MOCK_METHOD(
      StatusOr<google::cloud::dialogflow::cx::v3::TestCaseResult>,
      GetTestCaseResult,
      (google::cloud::dialogflow::cx::v3::GetTestCaseResultRequest const&
           request),
      (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace dialogflow_cx_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_DIALOGFLOW_CX_MOCKS_MOCK_TEST_CASES_CONNECTION_H
