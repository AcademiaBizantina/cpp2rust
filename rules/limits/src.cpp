// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <limits>

struct T1 {};

template <typename T> T f1() { return std::numeric_limits<T>::max(); }

template T1 f1<T1>();

template <typename T> T f2() { return std::numeric_limits<T>::min(); }

template T1 f2<T1>();
