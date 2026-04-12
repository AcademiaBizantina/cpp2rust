// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>

int main() {
  std::string str = "Hello, world!\n";
  std::ofstream ofs("test.txt", std::ios::binary);
  std::copy(str.begin(), str.end(), std::ostream_iterator<char>(ofs));
  return 0;
}
