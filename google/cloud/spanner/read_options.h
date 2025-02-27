// Copyright 2019 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_READ_OPTIONS_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_READ_OPTIONS_H

#include "google/cloud/spanner/request_priority.h"
#include "google/cloud/spanner/version.h"
#include "google/cloud/optional.h"
#include "google/cloud/options.h"
#include "absl/types/optional.h"
#include <cstdint>
#include <string>

namespace google {
namespace cloud {
namespace spanner {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/// Options passed to `Client::Read` or `Client::PartitionRead`.
struct ReadOptions {
  /**
   * If non-empty, the name of an index on a database table. This index is
   * used instead of the table primary key when interpreting the `KeySet`
   * and sorting result rows.
   */
  std::string index_name;

  /**
   * Limit on the number of rows to yield, or 0 for no limit.
   * A limit cannot be specified when calling `PartitionRead`.
   */
  std::int64_t limit = 0;

  /**
   * Priority for the read request.
   */
  absl::optional<RequestPriority> request_priority;

  /**
   * Tag for the read request.
   */
  absl::optional<std::string> request_tag;
};

inline bool operator==(ReadOptions const& lhs, ReadOptions const& rhs) {
  return lhs.limit == rhs.limit &&
         lhs.request_priority == rhs.request_priority &&
         lhs.request_tag == rhs.request_tag && lhs.index_name == rhs.index_name;
}

inline bool operator!=(ReadOptions const& lhs, ReadOptions const& rhs) {
  return !(lhs == rhs);
}

/// Converts `ReadOptions` to common `Options`.
Options ToOptions(ReadOptions const&);

/// Converts common `Options` to `ReadOptions`.
ReadOptions ToReadOptions(Options const&);

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace spanner
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_SPANNER_READ_OPTIONS_H
