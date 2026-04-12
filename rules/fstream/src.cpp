// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <fstream>
#include <iostream>
#include <iterator>

struct T1 {};

std::ifstream t1;
std::ofstream t2("");
std::ostream_iterator<char> t3{std::cout};

std::ofstream f1(const char *filename, std::ios_base::openmode mode) {
  return std::ofstream(filename, mode);
}

template <typename T> std::ostream_iterator<T> f2(std::ostream_iterator<T> a0) {
  return a0;
}

template std::ostream_iterator<T1> f2<T1>(std::ostream_iterator<T1>);

template <typename T> std::ostream_iterator<T> f3(std::ostream &a0) {
  return std::ostream_iterator<T>(a0);
}

template std::ostream_iterator<T1> f3<T1>(std::ostream &);

std::filebuf *f4(const std::ifstream &o) { return o.rdbuf(); }

std::ifstream f5(const char *filename, std::ios_base::openmode mode) {
  return std::ifstream(filename, mode);
}

template <typename T> std::istream_iterator<T> f6(std::istream_iterator<T> a0) {
  return a0;
}

template std::istream_iterator<T1> f6<T1>(std::istream_iterator<T1>);

template <typename T>
std::istreambuf_iterator<T> f7(std::istreambuf_iterator<T> a0) {
  return a0;
}

template std::istreambuf_iterator<T1> f7<T1>(std::istreambuf_iterator<T1>);

std::istreambuf_iterator<char> f8(std::basic_streambuf<char> *p) {
  return std::istreambuf_iterator<char>(p);
}
