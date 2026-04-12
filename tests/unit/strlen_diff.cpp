// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cstddef>

size_t strlen(const char *s) {
  const char *begin = s;
  while (*s) {
    ++s;
  }
  return s - begin;
}

int main() {
  const char s[] = {'s', 't', 'r', 'i', 'n', 'g', '\0'};
  return strlen(&s[0]);
}
