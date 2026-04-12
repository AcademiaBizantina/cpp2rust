// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  int *d = new int(0);
  *d = 5;
  delete d;
  return 0;
}
