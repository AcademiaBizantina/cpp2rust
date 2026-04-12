// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int foo() { return 0; }

int main() {
  int x = foo() + 1;
  int y = foo();
  return x + y;
}
