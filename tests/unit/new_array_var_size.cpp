// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

int main() {
  int N = 5;
  int *A = new int[N];
  delete[] A;
  int &N2 = N;
  int *A2 = new int[N2];
  delete[] A2;
  return 0;
}
