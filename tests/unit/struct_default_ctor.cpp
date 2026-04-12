// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <assert.h>
#include <string>

struct WOFF2Params {
  WOFF2Params()
      : extended_metadata(""), brotli_quality(11), allow_transforms(true) {}

  std::string extended_metadata;
  int brotli_quality;
  bool allow_transforms;
};

int main() {
  WOFF2Params params;
  assert(params.extended_metadata.size() == 0);
  assert(params.brotli_quality == 11);
  assert(params.allow_transforms == true);
  return 0;
}
