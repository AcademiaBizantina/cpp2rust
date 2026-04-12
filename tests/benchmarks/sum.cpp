// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  long N = 25000000000;
  long sum = 0;
  for (long i = 0, j = N; i < j; ++i, --j)
    sum += i + j;
  return sum;
}
