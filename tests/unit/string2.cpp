// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cassert>
#include <string>

int main() {
  std::string arr = "foo";
  arr[1] = 'b';
  const char *p = arr.c_str() + 1;
  assert(*p == 'b');
  assert(arr == "fbo");
  return 0;
}
