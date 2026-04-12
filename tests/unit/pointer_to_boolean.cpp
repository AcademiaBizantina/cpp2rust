// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  int *x = nullptr;
  if (x)
    return 1;
  return -1;
}
