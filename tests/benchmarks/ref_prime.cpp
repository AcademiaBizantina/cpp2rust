// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

bool is_prime(const int &x) {
  for (int i = 2; i < x; ++i) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}

int largest_prime(const int &n) {
  int max = -1;
  for (int i = 0; i < n; ++i) {
    if (is_prime(i)) {
      max = i;
    }
  }
  return max;
}

int main() {
  int N = 270000;
  return largest_prime(N);
}
