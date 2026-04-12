// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <stdio.h>
int main() {
  int a = 1;
  int *p = &a;
  printf("%p %d", p, *p);
  return 0;
}
