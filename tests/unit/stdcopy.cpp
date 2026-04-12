// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <algorithm>

int main() {
  int input[] = {1, 2, 3};
  int output[3];
  std::copy(input, input + 3, output);
  return 0;
}
