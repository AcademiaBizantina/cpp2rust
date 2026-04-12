// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <utility>

struct T1 {};
struct T2 {};
struct T3 {
  operator T1() const { return T1{}; }
};
struct T4 {
  operator T2() const { return T2{}; }
};
struct T5 {
  T5(const T5 &) noexcept(false) {}
};

std::pair<T1, T2> t1;

template <typename T1, typename T2> T2 &f1(std::pair<T1, T2> &o) {
  return o.second;
}

template T2 &f1<T1, T2>(std::pair<T1, T2> &);

template <typename T1, typename T2>
std::pair<T1, T2> f2(const std::pair<T1, T2> &o) {
  return o;
}

template std::pair<T5, T2> f2<T5, T2>(const std::pair<T5, T2> &);

template <typename T1, typename T2>
std::pair<T1, T2> f3(const std::pair<T1, T2> &o) {
  return o;
}

template std::pair<T1, T2> f3<T1, T2>(const std::pair<T1, T2> &);

template <typename T1, typename T2>
std::pair<T1, T2> f4(const T1 &a0, const T2 &a1) {
  return {a0, a1};
}

template std::pair<T1, T2> f4(const T1 &, const T2 &);

template <class T1, class T2, class T3, class T4>
std::pair<T1, T2> f5(T3 &&a, T4 &&b) {
  return std::pair<T1, T2>(std::forward<T3>(a), std::forward<T4>(b));
}

template std::pair<T1, T2> f5<T1, T2, const T3 &, T4 &>(const T3 &, T4 &);
#include <concepts>
#include <utility>

template <class T1, class T2, class T3, class T4>
std::pair<T1, T2> f6(T3 &&a, T4 &&b) {
  return std::pair<T1, T2>(std::forward<T3>(a), std::forward<T4>(b));
}

template std::pair<T1, T2> f6<T1, T2, T3 &, T4 &>(T3 &, T4 &);
#include <concepts>
#include <utility>

template <typename T1, typename T2, typename T3, typename T4>
std::pair<T1, T2> f7(T3 &&a, T4 &&b) {
  return std::pair<T1, T2>(std::move(a), std::move(b));
}

template std::pair<T1, T2> f7<T1, T2, T3, T4>(T3 &&, T4 &&);
#include <utility>

template <class A, class B> auto f9(A &&a, B &&b) {
  return std::make_pair(std::forward<A>(a), std::forward<B>(b));
}

template auto f9<T1, T2 &>(T1 &&, T2 &);
#include <utility>

template <class A, class B> auto f10(A &&a, B &&b) {
  return std::make_pair(std::forward<A>(a), std::forward<B>(b));
}

template auto f10<T1, T2>(T1 &&, T2 &&);
#include <utility>

template <typename T1, typename T2> T1 &f11(std::pair<T1, T2> &o) {
  return o.first;
}

template T1 &f11<T1, T2>(std::pair<T1, T2> &);
