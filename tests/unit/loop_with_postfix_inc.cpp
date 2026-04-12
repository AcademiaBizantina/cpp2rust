// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  int x = 0;
  while (x++ < 100 && x != 50) {
    ++x;
  }
  return x;
}
