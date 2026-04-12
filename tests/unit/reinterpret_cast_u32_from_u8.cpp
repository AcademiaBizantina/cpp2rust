// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cassert>
#include <cstdint>

// Reinterpret u8 array as u32.
int main() {
  uint8_t arr[8] = {0x78, 0x56, 0x34, 0x12, 0xEF, 0xCD, 0xAB, 0x90};
  uint32_t *dwords = reinterpret_cast<uint32_t *>(arr);

  assert(dwords[0] == 0x12345678);
  assert(dwords[1] == 0x90ABCDEF);

  return 0;
}
