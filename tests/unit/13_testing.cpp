// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  int a = 1;
  int &r = a;
  int *p = &a;
  r = 2;
  *p = 3;

  int **p2 = &p;
  **p2 = 3;
  return 0;
}
