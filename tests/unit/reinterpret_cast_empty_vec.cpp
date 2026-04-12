// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cstdint>
#include <vector>

// Reinterpret an empty vector's data pointer.
int main() {
  std::vector<uint32_t> v;
  auto bytes = reinterpret_cast<uint16_t *>(v.data());
  return 0;
}
