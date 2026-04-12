// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <deque>
#include <vector>

struct T1 {};

std::deque<T1> t1;

template <typename T> T &f1(std::deque<T> &o) { return o.back(); }

template T1 &f1<T1>(std::deque<T1> &);

template <typename T> T &f2(std::deque<T> &o) { return o.front(); }

template T1 &f2<T1>(std::deque<T1> &);

template <typename T> bool f3(const std::deque<T> &o) { return o.empty(); }

template bool f3<T1>(const std::deque<T1> &);

template <typename T> void f4(std::deque<T> &o, T &&value) {
  return o.push_back(std::move(value));
}

template void f4<T1>(std::deque<T1> &, T1 &&);

template <typename T> void f5(std::deque<T> &o) { return o.pop_front(); }

template void f5<T1>(std::deque<T1> &);

template <typename T>
void f7(std::deque<std::vector<T>> &o, const std::vector<T> &value) {
  return o.push_back(value);
}

template void f7(std::deque<std::vector<T1>> &, const std::vector<T1> &);
