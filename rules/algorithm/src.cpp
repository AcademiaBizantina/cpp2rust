// Copyright (c) 2022-present INESC-ID.
// Distributed under the MIT license that can be found in the LICENSE file.

#include <algorithm>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

struct T2 {
  friend bool operator<(T2 a, T2 b) { return false; }
};

struct T1 {
  using value_type = T2;
  using difference_type = std::ptrdiff_t;
  using reference = T2 &;
  using pointer = T2 *;
  using iterator_category = std::random_access_iterator_tag;

  pointer p = nullptr;

  T1() = default;

  operator T2() const { return {}; }

  reference operator*() const { return *p; }
  pointer operator->() const { return p; }
  reference operator[](difference_type n) const { return p[n]; }

  T1 &operator++() {
    ++p;
    return *this;
  }
  T1 operator++(int) {
    T1 tmp = *this;
    ++*this;
    return tmp;
  }
  T1 &operator--() {
    --p;
    return *this;
  }
  T1 operator--(int) {
    T1 tmp = *this;
    --*this;
    return tmp;
  }

  T1 &operator+=(difference_type n) {
    p += n;
    return *this;
  }
  T1 &operator-=(difference_type n) {
    p -= n;
    return *this;
  }
  friend T1 operator+(T1 it, difference_type n) {
    it += n;
    return it;
  }
  friend T1 operator+(difference_type n, T1 it) {
    it += n;
    return it;
  }
  friend T1 operator-(T1 it, difference_type n) {
    it -= n;
    return it;
  }
  friend difference_type operator-(T1 a, T1 b) { return a.p - b.p; }

  friend bool operator==(T1 a, T1 b) { return a.p == b.p; }
  friend bool operator!=(T1 a, T1 b) { return a.p != b.p; }
  friend bool operator<(T1 a, T1 b) { return a.p < b.p; }
  friend bool operator>(T1 a, T1 b) { return a.p > b.p; }
  friend bool operator<=(T1 a, T1 b) { return a.p <= b.p; }
  friend bool operator>=(T1 a, T1 b) { return a.p >= b.p; }

  T1 &operator=(const T2 &rhs) { return *this; }
};

template <class RandomIt> void f1(RandomIt first, RandomIt last) {
  return std::sort(first, last);
}

template void f1<T1>(T1, T1);

struct T3 {
  using iterator_category = std::input_iterator_tag;
  using value_type = int;
  using difference_type = std::ptrdiff_t;
  using pointer = const int *;
  using reference = const int &;

  pointer p{};

  T3() = default;
  explicit T3(pointer q) : p(q) {}

  reference operator*() const { return *p; }
  T3 &operator++() {
    ++p;
    return *this;
  }
  T3 operator++(int) {
    T3 tmp(*this);
    ++(*this);
    return tmp;
  }

  friend bool operator==(const T3 &a, const T3 &b) { return a.p == b.p; }
  friend bool operator!=(const T3 &a, const T3 &b) { return !(a == b); }
};

struct T4 {
  using iterator_category = std::output_iterator_tag;
  using value_type = void;
  using difference_type = std::ptrdiff_t;
  using pointer = int *;
  using reference = int &;

  pointer p{};

  T4() = default;
  explicit T4(pointer q) : p(q) {}

  reference operator*() const { return *p; }
  T4 &operator++() {
    ++p;
    return *this;
  }
  T4 operator++(int) {
    T4 tmp(*this);
    ++(*this);
    return tmp;
  }

  friend bool operator==(const T4 &a, const T4 &b) { return a.p == b.p; }
  friend bool operator!=(const T4 &a, const T4 &b) { return !(a == b); }
};

template <class InputIt, class OutputIt>
OutputIt f2(InputIt first, InputIt last, OutputIt d_first) {
  return std::copy(first, last, d_first);
}

template T4 f2<T3, T4>(T3, T3, T4);

struct T6 {
  friend bool operator==(T6 a, T6 b) { return true; }
};

struct T5 {
  using value_type = T6;
  using difference_type = std::ptrdiff_t;
  using reference = T6 &;
  using pointer = T6 *;
  using iterator_category = std::random_access_iterator_tag;

  pointer p = nullptr;

  T5() = default;

  reference operator*() const { return *p; }
  pointer operator->() const { return p; }
  reference operator[](difference_type n) const { return p[n]; }

  T5 &operator++() {
    ++p;
    return *this;
  }
  T5 operator++(int) {
    T5 tmp = *this;
    ++*this;
    return tmp;
  }
  T5 &operator--() {
    --p;
    return *this;
  }
  T5 operator--(int) {
    T5 tmp = *this;
    --*this;
    return tmp;
  }

  T5 &operator+=(difference_type n) {
    p += n;
    return *this;
  }
  T5 &operator-=(difference_type n) {
    p -= n;
    return *this;
  }
  friend T5 operator+(T5 it, difference_type n) {
    it += n;
    return it;
  }
  friend T5 operator+(difference_type n, T5 it) {
    it += n;
    return it;
  }
  friend T5 operator-(T5 it, difference_type n) {
    it -= n;
    return it;
  }
  friend difference_type operator-(T5 a, T5 b) { return a.p - b.p; }

  friend bool operator==(T5 a, T5 b) { return a.p == b.p; }
  friend bool operator!=(T5 a, T5 b) { return a.p != b.p; }
  friend bool operator<(T5 a, T5 b) { return a.p < b.p; }
  friend bool operator>(T5 a, T5 b) { return a.p > b.p; }
  friend bool operator<=(T5 a, T5 b) { return a.p <= b.p; }
  friend bool operator>=(T5 a, T5 b) { return a.p >= b.p; }
};

template <class InputIt, class T>
InputIt f3(InputIt first, InputIt last, const T &value) {
  return std::find(first, last, value);
}

template T5 f3<T5, T6>(T5, T5, const T6 &);

template <class RandomIt, class Compare>
void f6(RandomIt first, RandomIt last, Compare comp) {
  return std::stable_sort(first, last, comp);
}

auto lambda = [](const T2 &a, const T2 &b) { return false; };

template void f6<T1, decltype(lambda)>(T1, T1, decltype(lambda));

template <class RandomIt, class Compare>
void f7(RandomIt first, RandomIt last, Compare comp) {
  return std::stable_sort(first, last, comp);
}

bool f(const T2 &a, const T2 &b) { return false; };

template void f7<T1, decltype(f)>(T1, T1, decltype(f));

template <typename T> T *f8(T *first, T *last) {
  return std::max_element(first, last);
}

template T1 *f8<T1>(T1 *, T1 *);

template <typename T> void f9(T &a0, T &a1) { return std::swap(a0, a1); }

template void f9<T1>(T1 &, T1 &);

template <typename T>
typename std::vector<T>::iterator f10(typename std::vector<T>::iterator a0,
                                      typename std::vector<T>::iterator a1) {
  return std::unique(a0, a1);
}

template std::vector<T1>::iterator f10<T1>(std::vector<T1>::iterator,
                                           std::vector<T1>::iterator);

template <typename T1, typename T2>
void f12(typename std::vector<T1>::iterator a0,
         typename std::vector<T1>::iterator a1, const T2 &a2) {
  return std::fill(a0, a1, a2);
}

template void f12<T1, T2>(std::vector<T1>::iterator, std::vector<T1>::iterator,
                          const T2 &);

std::ostream_iterator<char> f13(std::string::iterator a0,
                                std::string::iterator a1,
                                std::ostream_iterator<char> a2) {
  return std::copy(a0, a1, a2);
}

template <class RandomIt, class Compare>
void f14(RandomIt first, RandomIt last, Compare comp) {
  return std::stable_sort(first, last, comp);
}

auto lambda_nref = [](T2 a, T2 b) { return false; };

template void f14<T1 *, decltype(lambda_nref)>(T1 *, T1 *,
                                               decltype(lambda_nref));

template <class RandomIt, class Compare>
void f15(RandomIt first, RandomIt last, Compare comp) {
  return std::stable_sort(first, last, comp);
}

bool f_nref(T2 a, T2 b) { return false; };

template void f15<T1 *, decltype(f_nref)>(T1 *, T1 *, decltype(f_nref));

template <typename T> const T &f16(const T &a, const T &b) {
  return std::min(a, b);
}

template const T2 &f16<T2>(const T2 &, const T2 &);

template <typename T> const T &f17(const T &a, const T &b) {
  return std::max(a, b);
}

template const T2 &f17<T2>(const T2 &, const T2 &);
