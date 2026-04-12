// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  const int x = 0;
  if (__builtin_constant_p(x)) {
    return __builtin_constant_p(3) + 2;
  } else {
    return -1;
  }
}
