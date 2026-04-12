// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <vector>

void foo(std::vector<int>::iterator a0) {}

int main() {
  std::vector<int> vec(4);
  std::vector<int>::iterator it = vec.begin();
  foo(it);
  return 0;
}
