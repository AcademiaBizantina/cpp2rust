// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <algorithm>
int main() {
  int a = 10, b = 20;
  int *pa = &a, *pb = &b;
  int **ppa = &pa;
  int **ppb = &pb;
  int r1 = std::max(**ppa, **ppb);
  int r2 = std::min(**ppa, **ppb);
  return r1 + r2;
}
