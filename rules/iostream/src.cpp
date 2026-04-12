// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <iostream>

std::ostream t1(std::cout.rdbuf());
std::ostream &t2 = t1;
std::ostream *t3 = &t1;

std::ostream &f1() { return std::cout; }

std::ostream &f2() { return std::cerr; }

std::ostream *f3() { return &std::cout; }

std::ostream *f4() { return &std::cerr; }
