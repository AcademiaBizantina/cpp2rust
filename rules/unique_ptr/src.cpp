// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <cstddef>
#include <memory>

struct T1 {};

std::unique_ptr<T1> t1;
std::unique_ptr<T1[]> t2;

template <typename T> std::unique_ptr<T[]> f1(std::size_t n) {
  return std::make_unique<T[]>(n);
}

template std::unique_ptr<T1[]> f1<T1>(std::size_t);
#include <memory>

template <typename T> T *f2(std::unique_ptr<T> &o) { return o.get(); }

template T1 *f2<T1>(std::unique_ptr<T1> &);
#include <memory>

template <typename T> std::unique_ptr<T> f3(T *p) {
  return std::unique_ptr<T>(p);
}

template std::unique_ptr<T1> f3<T1>(T1 *);
#include <memory>

template <typename T> std::unique_ptr<T[]> f4(T *p) {
  return std::unique_ptr<T[]>(p);
}

template std::unique_ptr<T1[]> f4<T1>(T1 *);
#include <memory>

template <typename T> void f5(std::unique_ptr<T> &o, T *p) {
  return o.reset(p);
}

template void f5<T1>(std::unique_ptr<T1> &, T1 *);
#include <memory>

template <typename T> void f6(std::unique_ptr<T[]> &o, T *p) {
  return o.reset(p);
}

template void f6<T1>(std::unique_ptr<T1[]> &, T1 *);
#include <memory>

template <typename T> T *f7(std::unique_ptr<T[]> &o) { return o.get(); }

template T1 *f7<T1>(std::unique_ptr<T1[]> &);

// template <typename T, typename... Args>
// std::unique_ptr<T> f8(Args&&... args) {
//     return std::make_unique<T>(std::forward<Args>(args)...);
// }

// Rust does not have variadic generics. We should consider writing specialized
// versions for make_unique with 1, 2, 3, etc arguments and translate the
// specialized versions.

template <typename T, typename Arg> std::unique_ptr<T> f8(Arg &&arg) {
  return std::make_unique<T>(std::forward<Arg>(arg));
}

template std::unique_ptr<T1> f8<T1>(T1 &&);

template <typename T> void f9(std::unique_ptr<T[]> &o) {
  return o.reset(nullptr);
}

template void f9<T1>(std::unique_ptr<T1[]> &);

template <typename T> std::unique_ptr<T> f10() { return std::unique_ptr<T>(); }

template std::unique_ptr<T1> f10<T1>();

template <typename T> std::unique_ptr<T[]> f11() {
  return std::unique_ptr<T[]>();
}

template std::unique_ptr<T1[]> f11<T1>();
