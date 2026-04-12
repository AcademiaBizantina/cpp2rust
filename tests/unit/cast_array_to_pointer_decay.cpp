// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int deref(int *p) { return *p; }
int strlen(char *s) {
  int c = 0;
  while (*s++)
    ++c;
  return c;
}
int main() {
  int a[2] = {1, 2};
  char s[4] = {'a', 'b', 'c', '\0'};
  return deref(a) + strlen(s);
}
