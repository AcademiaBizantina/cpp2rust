// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

unsigned long long fib(unsigned long long n) {
  return n == 0 || n == 1 ? n : fib(n - 1) + fib(n - 2);
}

int main() { return fib(46); }
