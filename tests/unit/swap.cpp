// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int identity(int x) { return x; }

void swap_by_ptr(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void swap_by_ref(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}

int main() {
  int local = 0;
  int a = 1;
  int b = 2;
  int c = identity(local);
  int *p = &a;
  p = &(b);
  p = &a;
  swap_by_ptr(p, &b);
  swap_by_ref(a, c);
  return c;
}
