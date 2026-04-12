// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <algorithm>

int main() {
  int arr1[] = {5, 2, 8, 1, 3};
  std::stable_sort(arr1, arr1 + 5, [](int x, int y) { return x < y; });
  return 0;
}
