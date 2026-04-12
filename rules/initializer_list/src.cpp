// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <initializer_list>

struct T1 {};

std::initializer_list<T1> t1;

template <typename T>
typename std::initializer_list<T>::size_type f1(std::initializer_list<T> &o) {
  return o.size();
}

template std::initializer_list<T1>::size_type
f1<T1>(std::initializer_list<T1> &);
