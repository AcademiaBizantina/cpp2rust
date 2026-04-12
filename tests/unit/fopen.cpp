// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <stdio.h>

int main() {
  const char *fname = "testfile.txt";
  const char *mode = "rb";
  FILE *file_ptr = fopen(fname, mode);

  return 0;
}
