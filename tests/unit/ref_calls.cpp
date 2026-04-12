// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int bar() { return 1; }
int &foo(int &x) { return x; }
int main() {
  int x = 5;
  int y = foo(x);
  int &z = foo(x);
  return foo(x) + foo(y) + foo(z) + bar();
}
