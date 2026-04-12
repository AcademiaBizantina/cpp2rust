// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int function(int y, int z) {
  int x = 5;
  return x + y + z;
}

int main() {
  int y = function(10, 1);
  return y;
}
