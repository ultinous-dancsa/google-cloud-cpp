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
// source: grafeas/v1/grafeas.proto

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_MOCKS_MOCK_GRAFEAS_CONNECTION_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_MOCKS_MOCK_GRAFEAS_CONNECTION_H

#include "google/cloud/containeranalysis/grafeas_connection.h"
#include <gmock/gmock.h>

namespace google {
namespace cloud {
namespace containeranalysis_mocks {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * A class to mock `GrafeasConnection`.
 *
 * Application developers may want to test their code with simulated responses,
 * including errors, from an object of type `GrafeasClient`. To do so,
 * construct an object of type `GrafeasClient` with an instance of this
 * class. Then use the Google Test framework functions to program the behavior
 * of this mock.
 *
 * @see [This example][bq-mock] for how to test your application with
 * GoogleTest. While the example showcases types from the BigQuery library, the
 * underlying principles apply for any pair of `*Client` and `*Connection`.
 *
 * [bq-mock]: @googleapis_dev_link{bigquery,bigquery-read-mock.html}
 */
class MockGrafeasConnection : public containeranalysis::GrafeasConnection {
 public:
  MOCK_METHOD(Options, options, (), (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Occurrence>, GetOccurrence,
              (grafeas::v1::GetOccurrenceRequest const& request), (override));

  MOCK_METHOD(StreamRange<grafeas::v1::Occurrence>, ListOccurrences,
              (grafeas::v1::ListOccurrencesRequest request), (override));

  MOCK_METHOD(Status, DeleteOccurrence,
              (grafeas::v1::DeleteOccurrenceRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Occurrence>, CreateOccurrence,
              (grafeas::v1::CreateOccurrenceRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<grafeas::v1::BatchCreateOccurrencesResponse>,
              BatchCreateOccurrences,
              (grafeas::v1::BatchCreateOccurrencesRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Occurrence>, UpdateOccurrence,
              (grafeas::v1::UpdateOccurrenceRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Note>, GetOccurrenceNote,
              (grafeas::v1::GetOccurrenceNoteRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Note>, GetNote,
              (grafeas::v1::GetNoteRequest const& request), (override));

  MOCK_METHOD(StreamRange<grafeas::v1::Note>, ListNotes,
              (grafeas::v1::ListNotesRequest request), (override));

  MOCK_METHOD(Status, DeleteNote,
              (grafeas::v1::DeleteNoteRequest const& request), (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Note>, CreateNote,
              (grafeas::v1::CreateNoteRequest const& request), (override));

  MOCK_METHOD(StatusOr<grafeas::v1::BatchCreateNotesResponse>, BatchCreateNotes,
              (grafeas::v1::BatchCreateNotesRequest const& request),
              (override));

  MOCK_METHOD(StatusOr<grafeas::v1::Note>, UpdateNote,
              (grafeas::v1::UpdateNoteRequest const& request), (override));

  MOCK_METHOD(StreamRange<grafeas::v1::Occurrence>, ListNoteOccurrences,
              (grafeas::v1::ListNoteOccurrencesRequest request), (override));
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace containeranalysis_mocks
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_CONTAINERANALYSIS_MOCKS_MOCK_GRAFEAS_CONNECTION_H
