// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <algorithm>
#include <initializer_list>
#include <vector>

struct T1 {
  friend bool operator<(const T1 &a, const T1 &b) noexcept { return true; }
};

struct T2 {
  operator T1() { return {}; }
};

std::vector<T1> t1;
std::vector<T1>::iterator t2;
std::vector<std::vector<T1>> t3;
std::vector<T1>::const_iterator t4;

template <typename T>
typename std::vector<T>::iterator
f1(std::vector<T> &o, typename std::vector<T>::const_iterator it) {
  return o.erase(it);
}

template std::vector<T1>::iterator f1<T1>(std::vector<T1> &,
                                          std::vector<T1>::const_iterator);

template <typename T> std::size_t f2(const std::vector<T> &o) {
  return o.size();
}

template std::size_t f2<T1>(const std::vector<T1> &);

template <typename T> bool f3(const std::vector<T> &o) { return o.empty(); }

template bool f3<T1>(const std::vector<T1> &);

template <typename T> std::vector<T> f4() { return std::vector<T>(); }

template std::vector<T1> f4<T1>();

template <typename T> void f5(std::vector<T> &o) { return o.pop_back(); }

template void f5<T1>(std::vector<T1> &);

template <typename T> T *f6(std::vector<T> &o) { return o.data(); }

template T1 *f6<T1>(std::vector<T1> &);

template <typename T> T &f7(std::vector<T> &o, std::size_t idx) {
  return o.at(idx);
}

template T1 &f7<T1>(std::vector<T1> &, std::size_t);

template <typename T> std::vector<T> f8(std::size_t n) {
  return std::vector<T>(n);
}

template std::vector<T1> f8<T1>(std::size_t);

template <typename T> T &f9(std::vector<T> &o) { return o.front(); }

template T1 &f9<T1>(std::vector<T1> &);

template <typename T> T &f10(std::vector<T> &o) { return o.back(); }

template T1 &f10<T1>(std::vector<T1> &);

template <typename T> std::size_t f11(const std::vector<T> &o) {
  return o.capacity();
}

template std::size_t f11<T1>(const std::vector<T1> &);

template <typename T> void f12(std::vector<T> &o, std::size_t n) {
  return o.reserve(n);
}

template void f12<T1>(std::vector<T1> &, std::size_t);

template <typename T> typename std::vector<T>::iterator f13(std::vector<T> &o) {
  return o.begin();
}

template std::vector<T1>::iterator f13<T1>(std::vector<T1> &);

template <typename T> void f14(std::vector<T> &o, T &&value) {
  return o.push_back(std::move(value));
}

template void f14<T1>(std::vector<T1> &, T1 &&);

template <typename T> void f15(std::vector<T> &o, std::size_t n) {
  return o.resize(n);
}

template void f15<T1>(std::vector<T1> &, std::size_t);

template <typename T> void f16(std::vector<T> &o) { return o.clear(); }

template void f16<T1>(std::vector<T1> &);

template <typename T> typename std::vector<T>::iterator f17(std::vector<T> &o) {
  return o.end();
}

template std::vector<T1>::iterator f17<T1>(std::vector<T1> &);

template <typename T>
typename std::vector<T>::iterator
f18(std::vector<T> &o, typename std::vector<T>::const_iterator it, T &&value) {
  return o.insert(it, std::move(value));
}

template std::vector<T1>::iterator
f18<T1>(std::vector<T1> &, std::vector<T1>::const_iterator, T1 &&);

template <typename T> std::vector<T> f19(std::size_t n, const T &value) {
  return std::vector<T>(n, value);
}

template std::vector<T1> f19<T1>(std::size_t, const T1 &);

template <typename T>
typename std::vector<T>::iterator
f20(std::vector<T> &o, typename std::vector<T>::const_iterator it,
    const T &value) {
  return o.insert(it, value);
}

template std::vector<T1>::iterator
f20<T1>(std::vector<T1> &, std::vector<T1>::const_iterator, const T1 &);

template <typename T> void f21(std::vector<T> &o, const T &value) {
  return o.push_back(value);
}

template void f21<T1>(std::vector<T1> &, const T1 &);

template <typename T>
typename std::vector<T>::reference f22(typename std::vector<T>::iterator it) {
  return *it;
}

template std::vector<T1>::reference f22<T1>(std::vector<T1>::iterator);

template <typename T>
typename std::vector<T>::iterator
f23(const typename std::vector<T>::iterator it) {
  return it;
}

template std::vector<T1>::iterator f23<T1>(std::vector<T1>::iterator);

template <typename T>
typename std::vector<T>::const_iterator
f24(typename std::vector<T>::iterator it) {
  return it;
}

template std::vector<T1>::const_iterator f24<T1>(std::vector<T1>::iterator);

template <typename T>
typename std::vector<T>::iterator f25(typename std::vector<T>::iterator it,
                                      std::size_t n) {
  return it + n;
}

template std::vector<T1>::iterator f25<T1>(std::vector<T1>::iterator,
                                           std::size_t);

template <typename T>
bool f26(const typename std::vector<T>::iterator it1,
         const typename std::vector<T>::iterator it2) {
  return it1 != it2;
}

template bool f26<T1>(const typename std::vector<T1>::iterator,
                      const typename std::vector<T1>::iterator);

template <typename T>
bool f27(const typename std::vector<T>::iterator it1,
         const typename std::vector<T>::iterator it2) {
  return it1 == it2;
}

template bool f27<T1>(const typename std::vector<T1>::iterator,
                      const typename std::vector<T1>::iterator);

template <typename T>
typename std::vector<T>::iterator f28(typename std::vector<T>::iterator it) {
  return it++;
}

template std::vector<T1>::iterator f28<T1>(std::vector<T1>::iterator);

template <typename T>
std::vector<std::vector<T>> f29(std::vector<std::vector<T>> &o) {
  return o;
}

template std::vector<std::vector<T1>> f29<T1>(std::vector<std::vector<T1>> &);

template <typename T> std::vector<std::vector<T>> f30(std::size_t n) {
  return std::vector<std::vector<T>>(n);
}

template std::vector<std::vector<T1>> f30<T1>(std::size_t);

template <typename T>
void f31(std::vector<std::vector<T>> &o, std::vector<T> &&value) {
  return o.push_back(std::move(value));
}

template void f31<T1>(std::vector<std::vector<T1>> &, std::vector<T1> &&);

template <typename T> void f32(std::vector<std::vector<T>> &o, std::size_t n) {
  return o.resize(n);
}

template void f32<T1>(std::vector<std::vector<T1>> &, std::size_t);

template <typename T>
typename std::vector<T>::iterator::difference_type
f33(const typename std::vector<T>::iterator it1,
    const typename std::vector<T>::iterator it2) {
  return it1 - it2;
}

template std::vector<T1>::iterator::difference_type
f33<T1>(const typename std::vector<T1>::iterator,
        const typename std::vector<T1>::iterator);

template <typename T>
typename std::vector<T>::iterator &f34(typename std::vector<T>::iterator &it) {
  return ++it;
}

template std::vector<T1>::iterator &f34<T1>(std::vector<T1>::iterator &);

template <typename T> std::vector<T> f35(const T *first, const T *last) {
  return std::vector<T>(first, last);
}

template std::vector<T1> f35<T1>(const T1 *, const T1 *);

template <typename T> std::vector<T> f36(const std::initializer_list<T> &a0) {
  return std::vector<T>(a0);
}

template std::vector<T1> f36<T1>(const std::initializer_list<T1> &);

template <typename T> std::vector<T> f37(T *first, T *last) {
  return std::vector<T>(first, last);
}

template std::vector<T1> f37<T1>(T1 *, T1 *);

std::vector<bool> f38(std::size_t n, const bool &value) {
  return std::vector<bool>(n, value);
}

std::vector<int> f39(unsigned int *first, unsigned int *last) {
  return std::vector<int>(first, last);
}

template <class T, std::size_t N> const T *f40(T const (&a0)[N]) {
  return std::end(a0);
}

template const T1 *f40(T1 const (&a0)[16]);

template <typename T> const T *f41(const std::vector<T> &o) { return o.data(); }

template const T1 *f41<T1>(const std::vector<T1> &);

template <typename T>
typename std::vector<T>::const_iterator
f42(typename std::vector<T>::const_iterator first,
    typename std::vector<T>::const_iterator last) {
  return std::max_element(first, last);
}

template std::vector<T1>::const_iterator
    f42<T1>(std::vector<T1>::const_iterator, std::vector<T1>::const_iterator);

template <typename T>
typename std::vector<T>::const_iterator f43(const std::vector<T> &o) {
  return o.begin();
}

template std::vector<T1>::const_iterator f43<T1>(const std::vector<T1> &);

template <typename T>
typename std::vector<T>::const_iterator f44(const std::vector<T> &o) {
  return o.end();
}

template std::vector<T1>::const_iterator f44<T1>(const std::vector<T1> &);

bool f47(std::vector<bool> &o) { return o[0]; }

template <typename T> void f48(std::vector<T> &o, std::vector<T> &a0) {
  return o.swap(a0);
}

template void f48<T1>(std::vector<T1> &o, std::vector<T1> &a0);

template <typename T> const T &f50(const std::vector<T> &o, std::size_t idx) {
  return o.at(idx);
}

template const T1 &f50<T1>(const std::vector<T1> &, std::size_t);

template <typename T> const T &f51(const std::vector<T> &o) { return o.back(); }

template const T1 &f51<T1>(const std::vector<T1> &);

template <typename T>
void f52(std::vector<std::vector<T>> &o, const std::vector<T> &value) {
  return o.push_back(value);
}

template void f52<T1>(std::vector<std::vector<T1>> &, const std::vector<T1> &);

template <typename T>
typename std::vector<T>::iterator
f53(std::vector<T> &o, typename std::vector<T>::const_iterator pos,
    const T *first, const T *last) {
  return o.insert(pos, first, last);
}

template std::vector<T1>::iterator f53<T1>(std::vector<T1> &,
                                           std::vector<T1>::const_iterator,
                                           const T1 *, const T1 *);

template <typename T>
void f54(std::vector<T> &o, std::size_t n,
         const typename std::vector<T>::value_type &value) {
  return o.resize(n, value);
}

template void f54<T1>(std::vector<T1> &, std::size_t,
                      const std::vector<T1>::value_type &);

template <typename T>
std::vector<T> &f55(std::vector<T> &dst, std::vector<T> &&src) {
  return dst = std::move(src);
}

template std::vector<T1> &f55<T1>(std::vector<T1> &, std::vector<T1> &&);

template <typename T> std::vector<T> &f56(std::vector<std::vector<T>> &o) {
  return o.back();
}

template std::vector<T1> &f56<T1>(std::vector<std::vector<T1>> &);

template <typename T>
typename std::vector<T>::const_iterator f57(const std::vector<T> &o) {
  return o.cend();
}

template std::vector<T1>::const_iterator f57<T1>(const std::vector<T1> &);

template <typename T>
std::vector<T> &f58(std::vector<T> &dst, const std::vector<T> &src) {
  return dst = src;
}

template std::vector<T1> &f58<T1>(std::vector<T1> &, const std::vector<T1> &);

template <typename T> void f59(std::vector<T> &o) { return o.shrink_to_fit(); }

template void f59<T1>(std::vector<T1> &);
