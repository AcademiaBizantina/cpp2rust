// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

struct Foo {
  int x1, x2;
};

int main() {
  Foo arr[2] = {{1, 2}, {3, 4}};
  int *p1 = &arr[1].x1;
  int a = *p1;
  Foo *p2 = &arr[0];
  return a + p2->x2;
}
