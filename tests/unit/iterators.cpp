// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <string>
#include <vector>

int main() {
  std::string x = "hello";

  for (auto &c : x)
    ++c;

  for (auto &c : x)
    printf("%c\n", c);

  for (auto c : x)
    printf("%c\n", c);

  std::vector<int *> v;
  v.push_back(new int(2));
  v.push_back(new int(3));

  for (auto p : v)
    printf("%d\n", *p);

  return 0;
}
