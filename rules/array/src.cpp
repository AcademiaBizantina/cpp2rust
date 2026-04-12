// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <array>

struct T1 {};
constexpr std::size_t DUMMY_SIZE = 0x0b57ac1e;

std::array<T1, DUMMY_SIZE> t1;

template <typename T> const T *f1(const std::array<T, DUMMY_SIZE> &o) {
  return o.data();
}

template const T1 *f1<T1>(const std::array<T1, DUMMY_SIZE> &);

template <typename T> std::size_t f2(const std::array<T, DUMMY_SIZE> &o) {
  return o.size();
}

template std::size_t f2<T1>(const std::array<T1, DUMMY_SIZE> &);

template <typename T> T *f3(std::array<T, DUMMY_SIZE> &o) { return o.data(); }

template T1 *f3<T1>(std::array<T1, DUMMY_SIZE> &);
