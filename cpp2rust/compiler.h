#pragma once

// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cassert>

#ifndef NDEBUG
#define ENSURE(x) assert(x)
#else
#define ENSURE(x) (void)(x)
#endif
