// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  int *e = new int[2];
  e[0] = 6;
  e[1] = 7;
  delete[] e;
  return 0;
}
