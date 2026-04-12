// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

struct StackArray {
  int *arr[3];
};

void IncrementAll(StackArray &s) {
  for (int i = 0; i < 3; ++i)
    *s.arr[i] += 1;
}

int main() {
  int x = 0;
  StackArray s = {{&x, &x, &x}};
  IncrementAll(s);
  return x;
}
