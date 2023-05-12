/*
 * This file is a part of the SubStandard C++ library.
 *
 * Developed for my own convenience in the future.
 * This product includes software developed by myself.
 * (Insert website here if I ever decide to make it)
 * See the COPYRIGHT file at the top-level directory of this distribution
 * for details of code security.
 *
 * This program is free software. You can redistribute and/or modify
 * it under the terms of the Creative Commons Attribution-NonCommercial-
 * ShareAlike 4.0 International License as published by Creative Commons,
 * either version 4.0 of the license, or (at your option) any later
 * version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Creative Commons Attribution-NonCommercial-ShareAlike 4.0
 * International License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see
 * <https://creativecommons.org/licenses/by-nc/4.0/>.
 */

#if !defined(SSTD_VECTOR2_HPP)
#define SSTD_VECTOR2_HPP

#include <algorithm>
#include <initializer_list>
#include <iterator>
#include <stdexcept>

namespace sstd {

template <class T, size_t N>
class vector {
 protected:
  T vec[N] = {0};

 public:
  vector() = default;
  template <class Iter>
  vector(const Iter begin, const Iter end) {
    if (end - begin != N) {
      throw std::invalid_argument("Size of range is wrong");
    }
    std::copy(begin, end, std::begin(vec));
  }
  vector(const std::initializer_list<T> init) {
    if (init.size() != N) {
      throw std::invalid_argument("Size of range is wrong");
    }
    std::copy(init.begin(), init.end(), std::begin(vec));
  }

  inline T at(const size_t index) const { return vec[index]; }
  inline void at(const size_t index, const T value) { vec[index] == value; }

  inline T* data() { return vec; }
  inline auto begin() { return std::begin(vec); }
  inline auto end() { return std::end(vec); }
  inline auto cbegin() const { return std::cbegin(vec); }
  inline auto cend() const { return std::cend(vec); }
  inline auto rbegin() { return std::rbegin(vec); }
  inline auto rend() { return std::rend(vec); }
  inline auto crbegin() const { return std::crbegin(vec); }
  inline auto crend() const { return std::crend(vec); }
  inline size_t size() const { return N; }
  inline size_t sizeOf() const { return sizeof(*this); }

  inline T operator[](size_t index) const { return vec[index]; }
  inline T& operator[](size_t index) { return vec[index]; }
  vector<T, N> operator+(const vector<T, N> _vector) const {
    vector<T, N> copy = *this;
    for (size_t i = 0; i < N; ++i) {
      copy[i] += _vector[i];
    }
    return copy;
  }
  vector<T, N> operator-(const vector<T, N> _vector) const {
    vector<T, N> copy = *this;
    for (size_t i = 0; i < N; ++i) {
      copy[i] -= _vector[i];
    }
    return copy;
  }
  template <class A>
  vector<T, N> operator*(const A _num) const {
    vector<T, N> copy = *this;
    for (size_t i = 0; i < N; ++i) {
      copy[i] *= _num;
    }
    return copy;
  }
  vector<T, N> operator+=(const vector<T, N> _vector) {
    for (size_t i = 0; i < N; ++i) {
      vec[i] += _vector[i];
    }
    return *this;
  }
  vector<T, N> operator-=(const vector<T, N> _vector) {
    for (size_t i = 0; i < N; ++i) {
      vec[i] -= _vector[i];
    }
    return *this;
  }
  template <class A>
  vector<T, N> operator*=(const A _num) {
    for (size_t i = 0; i < N; ++i) {
      vec[i] *= _num;
    }
    return *this;
  }
  vector<T, N> operator++() {
    for (size_t i = 0; i < N; ++i) {
      ++vec[i];
    }
    return *this;
  }
  vector<T, N> operator--() {
    for (size_t i = 0; i < N; ++i) {
      --vec[i];
    }
    return *this;
  }
  vector<T, N> operator++(int) {
    vector<T, N> copy = *this;
    for (size_t i = 0; i < N; ++i) {
      ++copy[i];
    }
    return copy;
  }
  vector<T, N> operator--(int) {
    vector<T, N> copy = *this;
    for (size_t i = 0; i < N; ++i) {
      --copy[i];
    }
    return copy;
  }

#if defined(SSTD_PRINTCONT_HPP)
  void print() const { print(cbegin(), cend()); }
#endif
};

template <class T>
class vector<T, 2> {
 protected:
  T vec[2] = {0};

 public:
  vector() = default;
  template <class Iter>
  vector(const Iter begin, const Iter end) {
    if (end - begin != 2) {
      throw std::invalid_argument("Size of range is wrong");
    }
    std::copy(begin, end, std::begin(vec));
  }
  vector(const T first, const T second) {
    vec[0] = first;
    vec[1] = second;
  }

  inline T at(const size_t index) const { return vec[index]; }
  inline void at(const size_t index, const T value) { vec[index] = value; }

  inline T* data() { return vec; }
  inline auto begin() { return std::begin(vec); }
  inline auto end() { return std::end(vec); }
  inline auto cbegin() const { return std::cbegin(vec); }
  inline auto cend() const { return std::cend(vec); }
  inline auto rbegin() { return std::rbegin(vec); }
  inline auto rend() { return std::rend(vec); }
  inline auto crbegin() const { return std::crbegin(vec); }
  inline auto crend() const { return std::crend(vec); }
  inline T first() const { return vec[0]; }
  inline T second() const { return vec[1]; }
  inline size_t size() const { return 2; }
  inline size_t sizeOf() const { return sizeof(*this); }

  inline T operator[](size_t index) const { return vec[index]; }
  inline T& operator[](size_t index) { return vec[index]; }
  vector<T, 2> operator+(const vector<T, 2> _vector) const {
    return vector<T, 2>{vec[0] + _vector[0], vec[1] + _vector[1]};
  }
  vector<T, 2> operator-(const vector<T, 2> _vector) const {
    return vector<T, 2>{vec[0] - _vector[0], vec[1] - _vector[1]};
  }
  template <class A>
  vector<T, 2> operator*(const A _num) const {
    return vector<T, 2>{vec[0] * _num, vec[1] * _num};
  }
  vector<T, 2> operator+=(const vector<T, 2> _vector) {
    vec[0] += _vector[0];
    vec[1] += _vector[1];
    return *this;
  }
  vector<T, 2> operator-=(const vector<T, 2> _vector) {
    vec[0] -= _vector[0];
    vec[1] -= _vector[1];
    return *this;
  }
  template <class A>
  vector<T, 2> operator*=(const A _num) {
    vec[0] *= _num;
    vec[1] *= _num;
    return *this;
  }
  vector<T, 2> operator++() {
    ++vec[0];
    ++vec[1];
    return *this;
  }
  vector<T, 2> operator--() {
    --vec[0];
    --vec[1];
    return *this;
  }
  vector<T, 2> operator++(int) {
    vector<T, 2> copy = *this;
    ++vec[0]++ vec[1];
    return copy;
  }
  vector<T, 2> operator--(int) {
    vector<T, 2> copy = *this;
    --vec[0];
    --vec[1];
    return copy;
  }

#if defined(SSTD_PRINTCONT_HPP)
  void print() const { sstd::print(cbegin(), cend()); }
#endif
};

template <class T>
class vector<T, 3> {
 protected:
  T vec[3] = {0};

 public:
  vector() = default;
  template <class Iter>
  vector(const Iter begin, const Iter end) {
    if (end - begin != 3) {
      throw std::invalid_argument("Size of range is wrong");
    }
    std::copy(begin, end, std::begin(vec));
  }
  vector(const T first, const T second, const T third) {
    vec[0] = first;
    vec[1] = second;
    vec[2] = third;
  }

  inline T at(const size_t index) const { return vec[index]; }
  inline void at(const size_t index, const T value) { vec[index] = value; }

  inline T* data() { return vec; }
  inline auto begin() { return std::begin(vec); }
  inline auto end() { return std::end(vec); }
  inline auto cbegin() const { return std::cbegin(vec); }
  inline auto cend() const { return std::cend(vec); }
  inline auto rbegin() { return std::rbegin(vec); }
  inline auto rend() { return std::rend(vec); }
  inline auto crbegin() const { return std::crbegin(vec); }
  inline auto crend() const { return std::crend(vec); }
  inline T first() const { return vec[0]; }
  inline T second() const { return vec[1]; }
  inline T third() const { return vec[2]; }
  inline size_t size() const { return 3; }
  inline size_t sizeOf() const { return sizeof(*this); }

  inline T operator[](size_t index) const { return vec[index]; }
  inline T& operator[](size_t index) { return vec[index]; }
  vector<T, 3> operator+(const vector<T, 3> _vector) const {
    return std::vector<T, 3>{vec[0] + _vector[0], vec[1] + _vector[1],
                             vec[2] + _vector[2]};
  }
  vector<T, 3> operator-(const vector<T, 3> _vector) const {
    return std::vector<T, 3>{vec[0] - _vector[0], vec[1] - _vector[1],
                             vec[2] - _vector[2]};
  }
  template <class A>
  vector<T, 3> operator*(const A _num) const {
    return std::vector<T, 3>{vec[0] * _num, vec[1] * _num, vec[2] * _num};
  }
  vector<T, 3> operator+=(const vector<T, 3> _vector) {
    vec[0] += _vector[0];
    vec[1] += _vector[1];
    vec[2] += _vector[2];
    return *this;
  }
  vector<T, 3> operator-=(const vector<T, 3> _vector) {
    vec[0] -= _vector[0];
    vec[1] -= _vector[1];
    vec[2] -= _vector[2];
    return *this;
  }
  template <class A>
  vector<T, 3> operator*=(const A _num) {
    vec[0] *= _vector[0];
    vec[1] *= _vector[1];
    vec[2] *= _vector[2];
    return *this;
  }
  vector<T, 3> operator++() {
    ++vec[0];
    ++vec[1];
    ++vec[2];
    return *this;
  }
  vector<T, 3> operator--() {
    --vec[0];
    --vec[1];
    --vec[2];
    return *this;
  }
  vector<T, 3> operator++(int) {
    vector<T, 3> copy = *this;
    ++vec[0];
    ++vec[1];
    ++vec[2];
    return copy;
  }
  vector<T, 3> operator--(int) {
    vector<T, 3> copy = *this;
    --vec[0];
    --vec[1];
    --vec[2];
    return copy;
  }

#if defined(SSTD_PRINTCONT_HPP)
  void print() const;
#endif
};

#if defined(SSTD_PRINTCONT_HPP)
template <typename T, size_t N>
void print(const vector<T, N> _vector) {
  print(_vector.cbegin(), _vector.cend());
}
}
#endif

}  // namespace sstd

#endif