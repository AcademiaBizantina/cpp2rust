// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cstdlib>

struct T1 {};

constexpr size_t DUMMY_SIZE = 1;

T1 t1[DUMMY_SIZE][DUMMY_SIZE];
T1 t2[DUMMY_SIZE][DUMMY_SIZE][DUMMY_SIZE];
