// Copyright 2021 Google LLC
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

#ifndef GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OBJECT_READ_STREAM_H
#define GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OBJECT_READ_STREAM_H

#include "google/cloud/storage/headers_map.h"
#include "google/cloud/storage/internal/object_read_streambuf.h"
#include "google/cloud/storage/version.h"
#include <istream>
#include <memory>
#include <string>

namespace google {
namespace cloud {
namespace storage {
GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_BEGIN

/**
 * Defines a `std::basic_istream<char>` to read from a GCS Object.
 */
class ObjectReadStream : public std::basic_istream<char> {
 public:
  /**
   * Creates a stream not associated with any buffer.
   *
   * Attempts to use this stream will result in failures.
   */
  ObjectReadStream();

  /**
   * Creates a stream associated with the given `streambuf`.
   */
  explicit ObjectReadStream(std::unique_ptr<internal::ObjectReadStreambuf> buf)
      : std::basic_istream<char>(nullptr), buf_(std::move(buf)) {
    // Initialize the basic_ios<> class
    init(buf_.get());
  }

  ObjectReadStream(ObjectReadStream&& rhs) noexcept;

  ObjectReadStream& operator=(ObjectReadStream&& rhs) noexcept {
    ObjectReadStream tmp(std::move(rhs));
    swap(tmp);
    return *this;
  }

  void swap(ObjectReadStream& rhs) {
    std::basic_istream<char>::swap(rhs);
    std::swap(buf_, rhs.buf_);
    rhs.set_rdbuf(rhs.buf_.get());
    set_rdbuf(buf_.get());
  }

  ObjectReadStream(ObjectReadStream const&) = delete;
  ObjectReadStream& operator=(ObjectReadStream const&) = delete;

  /// Closes the stream (if necessary).
  ~ObjectReadStream() override;

  bool IsOpen() const { return static_cast<bool>(buf_) && buf_->IsOpen(); }

  /**
   * Terminate the download, possibly before completing it.
   */
  void Close();

  /**
   * Report any download errors.
   *
   * Note that errors may go undetected until the download completes.
   */
  Status const& status() const& { return buf_->status(); }

  /**
   * The received CRC32C checksum and the MD5 hash values as reported by GCS.
   *
   * When the download is finalized (via `Close()` or the end of file) the GCS
   * server reports the CRC32C checksum and, except for composite objects, the
   * MD5 hash of the data. This class compares the locally computed and received
   * hashes so applications can detect data download errors.
   *
   * The values are reported as comma separated `tag=value` pairs, e.g.
   * `crc32c=AAAAAA==,md5=1B2M2Y8AsgTpgAmY7PhCfg==`. The format of this string
   * is subject to change without notice, they are provided for informational
   * purposes only.
   *
   * @see https://cloud.google.com/storage/docs/hashes-etags for more
   *     information on checksums and hashes in GCS.
   */
  std::string const& received_hash() const { return buf_->received_hash(); }

  /**
   * The locally computed checksum and hashes, as a string.
   *
   * This object computes the CRC32C checksum and MD5 hash of the downloaded
   * data. Note that there are several cases where these values may be empty or
   * irrelevant, for example:
   *   - When reading only a portion of a blob the hash of that portion is
   *     irrelevant, note that GCS only reports the hashes for the full blob.
   *   - The application may disable the CRC32C and/or the MD5 hash computation.
   *
   * The string has the same format as the value returned by `received_hash()`.
   * Note that the format of this string is also subject to change without
   * notice.
   *
   * @see https://cloud.google.com/storage/docs/hashes-etags for more
   *     information on checksums and hashes in GCS.
   */
  std::string const& computed_hash() const { return buf_->computed_hash(); }

  /**
   * The headers (if any) returned by the service. For debugging only.
   *
   * @warning The contents of these headers may change without notice. Unless
   *     documented in the API, headers may be removed or added by the service.
   *     Also note that the client library uses both the XML and JSON API,
   *     choosing between them based on the feature set (some functionality is
   *     only available through the JSON API), and performance.  Consequently,
   *     the headers may be different on requests using different features.
   *     Likewise, the headers may change from one version of the library to the
   *     next, as we find more (or different) opportunities for optimization.
   */
  HeadersMap const& headers() const { return buf_->headers(); }

  //@{
  /**
   * @name Object metadata information.
   *
   * When downloading an object a limited amount of information about the
   * object's metadata is returned as part of the download. Some of this
   * information is important for applications performing multiple downloads
   * (maybe of different ranges) of the same object.  Such applications may
   * want to use the generation number to guarantee all the downloads are
   * actually referencing the same object.  One could do this by first querying
   * the metadata before the first download, but this is less efficient as it
   * requires one additional server round trip.
   *
   * Note that all these attributes are `absl::optional<>`, as the attributes
   * may not be known (or exist) if there is an error during the download. If
   * the attribute is needed for the application's correctness the application
   * should fetch the object metadata when the attribute is not available.
   */
  /// The object's generation at the time of the download, if known.
  absl::optional<std::int64_t> const& generation() const {
    return buf_->generation();
  }

  /// The object's metageneration at the time of the download, if known.
  absl::optional<std::int64_t> const& metageneration() const {
    return buf_->metageneration();
  }

  /// The object's storage class at the time of the download, if known.
  absl::optional<std::string> const& storage_class() const {
    return buf_->storage_class();
  }

  /**
   * The object's size at the time of the download, if known.
   *
   * If you are using [object transcoding] this represents the stored size of
   * the object, the number of downloaded bytes (after decompression) may be
   * larger.
   *
   * [object transcoding]: https://cloud.google.com/storage/docs/transcoding
   */
  absl::optional<std::uint64_t> const& size() const { return buf_->size(); }
  //@}

 private:
  std::unique_ptr<internal::ObjectReadStreambuf> buf_;
};

GOOGLE_CLOUD_CPP_INLINE_NAMESPACE_END
}  // namespace storage
}  // namespace cloud
}  // namespace google

#endif  // GOOGLE_CLOUD_CPP_GOOGLE_CLOUD_STORAGE_OBJECT_READ_STREAM_H
