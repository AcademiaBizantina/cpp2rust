// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

struct Pair {
  int x, y;
};

int main() {
  Pair *p = new Pair{1, 2};
  int out = p->x + p->y;
  delete p;
  return out;
}
