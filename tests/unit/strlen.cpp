// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

unsigned strlen(char *ptr) {
  unsigned count = 0;
  while (*ptr++ != '\0')
    ++count;
  return count;
}

int main() {
  char string[] = {'h', 'e', 'l', 'l', 'o', '\0'};
  return strlen(&string[0]);
}
