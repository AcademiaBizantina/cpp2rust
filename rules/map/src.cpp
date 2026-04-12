// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <map>
#include <utility>

struct T1 {
  friend bool operator<(const T1 &a, const T1 &b) noexcept { return true; }
};
struct T2 {};

std::map<T1, T2> t1;
std::map<T1, T2>::const_iterator t2;
std::map<T1, T2>::iterator t3;

template <typename K, typename V> V &f1(std::map<K, V> &o, const K &key) {
  return o[key];
}

template T2 &f1<T1, T2>(std::map<T1, T2> &, const T1 &);

template <typename K, typename V> std::size_t f2(const std::map<K, V> &o) {
  return o.size();
}

template std::size_t f2<T1, T2>(const std::map<T1, T2> &);

template <typename K, typename V>
typename std::map<K, V>::iterator f3(std::map<K, V> &o,
                                     typename std::map<K, V>::iterator it) {
  return o.erase(it);
}

template std::map<T1, T2>::iterator f3<T1, T2>(std::map<T1, T2> &,
                                               std::map<T1, T2>::iterator);

template <typename K, typename V> std::map<K, V> f5() {
  return std::map<K, V>();
}

template std::map<T1, T2> f5<T1, T2>();

template <typename K, typename V> std::map<K, V> f6(std::map<K, V> &o) {
  return o;
}

template std::map<T1, T2> f6<T1, T2>(std::map<T1, T2> &);

template <typename K, typename V> V &f7(std::map<K, V> &o, const K &key) {
  return o.at(key);
}

template T2 &f7<T1, T2>(std::map<T1, T2> &, const T1 &);

template <typename K, typename V> V &f8(std::map<K, V> &o, K &&key) {
  return o[std::move(key)];
}

template T2 &f8<T1, T2>(std::map<T1, T2> &, T1 &&);

template <typename K, typename V>
typename std::map<K, V>::const_iterator f9(const std::map<K, V> &o) {
  return o.end();
}

template std::map<T1, T2>::const_iterator f9<T1, T2>(const std::map<T1, T2> &);

template <typename K, typename V>
typename std::map<K, V>::iterator f10(std::map<K, V> &o, const K &key) {
  return o.find(key);
}

template std::map<T1, T2>::iterator f10<T1, T2>(std::map<T1, T2> &, const T1 &);

template <typename K, typename V>
bool f11(typename std::map<K, V>::iterator a,
         typename std::map<K, V>::iterator b) {
  return a != b;
}

template bool f11<T1, T2>(std::map<T1, T2>::iterator,
                          std::map<T1, T2>::iterator);

template <typename K, typename V>
typename std::map<K, V>::iterator f12(std::map<K, V> &o) {
  return o.begin();
}

template std::map<T1, T2>::iterator f12<T1, T2>(std::map<T1, T2> &);

template <typename K, typename V>
bool f13(typename std::map<K, V>::const_iterator a,
         typename std::map<K, V>::const_iterator b) {
  return a == b;
}

template bool f13<T1, T2>(std::map<T1, T2>::const_iterator,
                          std::map<T1, T2>::const_iterator);

template <typename K, typename V>
typename std::map<K, V>::iterator f14(std::map<K, V> &o) {
  return o.end();
}

template std::map<T1, T2>::iterator f14<T1, T2>(std::map<T1, T2> &);

template <typename K, typename V>
const V &f15(const std::map<K, V> &o, const K &key) {
  return o.at(key);
}

template const T2 &f15<T1, T2>(const std::map<T1, T2> &, const T1 &);

template <typename K, typename V>
bool f16(typename std::map<K, V>::iterator a,
         typename std::map<K, V>::iterator b) {
  return a == b;
}

template bool f16<T1, T2>(std::map<T1, T2>::iterator,
                          std::map<T1, T2>::iterator);

template <typename K, typename V>
typename std::map<K, V>::const_iterator f17(const std::map<K, V> &o,
                                            const K &key) {
  return o.find(key);
}

template std::map<T1, T2>::const_iterator f17<T1, T2>(const std::map<T1, T2> &,
                                                      const T1 &);

template <typename K, typename V>
typename std::map<K, V>::const_iterator
f19(typename std::map<K, V>::iterator it) {
  return it;
}

template std::map<T1, T2>::const_iterator
    f19<T1, T2>(std::map<T1, T2>::iterator);

template <typename K, typename V>
const K &f20(typename std::map<K, V>::const_iterator it) {
  return it->first;
}

template const T1 &f20<T1, T2>(std::map<T1, T2>::const_iterator);

template <typename K, typename V>
const V &f21(typename std::map<K, V>::const_iterator it) {
  return it->second;
}

template const T2 &f21<T1, T2>(std::map<T1, T2>::const_iterator);

template <typename K, typename V>
const K &f22(typename std::map<K, V>::iterator it) {
  return it->first;
}

template const T1 &f22<T1, T2>(std::map<T1, T2>::iterator);

template <typename K, typename V> V &f23(typename std::map<K, V>::iterator it) {
  return it->second;
}

template T2 &f23<T1, T2>(std::map<T1, T2>::iterator);
