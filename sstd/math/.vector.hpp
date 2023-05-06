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
#include <iterator>
#include <sstd/.io/printCont.hpp>
#include <stdexcept>

namespace sstd {

/// @brief 2-dimensional vector class
template <class T>
class vector2 {
 protected:
  T vec[2] = {0};

 public:
  /// @brief Default constructor. Zero initialises vector
  vector2() = default;

  /// @brief Constructs vector
  /// @param begin Range begin iterator
  /// @param end Range end iterator
  template <class Iter>
  vector2(const Iter begin, const Iter end) {
    if (end - begin != 2) {
      throw std::invalid_argument("Size of container is wrong");
    }
    std::copy(begin, end, std::begin(vec));
  };

  /// @brief Constructs vector
  /// @param first First element of vector
  /// @param second Second element of vector
  vector2(const T first, const T second) noexcept {
    vec[0] = first;
    vec[1] = second;
  }

  /// @brief Gets value from vector
  /// @param index Index of value
  /// @return value
  inline T at(const size_t index) const {
    if (abs(index) > 1) {
      throw std::invalid_argument("Index not in vector");
    }
    return vec[index];
  }

  /// @brief Replaces value in vector
  /// @param index Index of value
  /// @param value Value to be replace with
  inline void at(const size_t index, T value) {
    if (abs(index) > 1) {
      throw std::invalid_argument("Index not in vector");
    }
    vec[index] = value;
  }

  /// @brief Gives access to the underlying array of this
  /// @return Underlying array
  inline T* data() { return vec; }

  /// @brief Gets first value of the vector2
  /// @return First value of the vector2
  inline T cfirst() const { return vec[0]; }

  /// @brief Gets first reference of the vector2
  /// @return First reference of the vector2
  inline T& first() { return vec[0]; }

  /// @brief Gets first value of the vector2
  /// @return First value of the vector2
  inline T csecond() const { return vec[1]; }

  /// @brief Gets second reference of the vector2
  /// @return Second reference of the vector2
  inline T& second() { return vec[1]; }

  /// @brief Gets size of vector2
  /// @return 2
  inline size_t size() { return 2; }

  /// @brief Gets size of vector2 in bytes
  /// @return Size of vector2 in bytes
  inline size_t sizeof() { return sizeof(*this); }

  /// @brief Gets element at specified index
  /// @param index Index of element requested
  /// @return Value of element at specified index
  inline T operator[](size_t index) const { return vec[index]; }

  /// @brief References element at specified index
  /// @param index Index of element requested
  /// @return Reference to element at specified index
  inline T& operator[](size_t index) { return vec[index]; }

  /// @brief Adds a vector to this
  /// @param _vector Vector to be added to this
  /// @return This after addition
  /// @warning <T> will not be typecasted to <R> even if there's a loss of
  /// precision
  template <class R>
  vector2<T> add(vector2<R> _vector) {
    vec[0] += _vector[0];
    vec[1] += _vector[1];
    return *this;
  }

  /// @brief Subtracts a vector from this
  /// @param _vector Vector to be subtracted from this
  /// @return This after subtraction
  /// @warning <T> will not be typecasted to <R> even if there's a loss of
  /// precision
  template <class R>
  vector2<T> sub(vector2<R> _vector) {
    vec[0] -= _vector[0];
    vec[2] -= _vector[1];
    return *this;
  }

  /// @brief Multiplies this by a scalar
  /// @param toMult Scalar to be multiplied to this
  /// @return This after multiplication
  /// @warning <T> will not be typecasted to <R> even if there's a loss of
  /// precision
  template <class R>
  vector2<T> mult(R toMult) {
    vec[0] *= toMult;
    vec[1] *= toMult;
    return *this;
  }

#if defined(SSTD_PRINTCONT_HPP)
  /// @brief Prints this vector
  void print() const { std::cout << vec[0] << "\n" << vec[1]; }
#endif
};

/// @brief 3-dimensional vector class
template <class T>
class vector3 {
 protected:
  T vec[3] = {0};

 public:
  /// @brief Default constructor. Zero initialises vector
  vector3() = default;

  /// @brief Constructrs vector
  /// @param begin Range begin iterator
  /// @param end Range end iterator
  template <class Iter>
  vector3(const Iter begin, const Iter end) {
    if (end - begin != 3) {
      throw std::invalid_argument("Size of container is wrong");
    }
    std::copy(begin, end, std::begin(vec));
  }

  /// @brief Constructs vector
  /// @param first First element of vector
  /// @param second Second element of vector
  /// @param third Third element of vector
  vector3(const T first, const T second, const T third) noexcept {
    vec[0] = first;
    vec[1] = second;
    vec[2] = third;
  }

  /// @brief Gets value from vector
  /// @param index Index of value
  /// @return value
  inline T at(const size_t index) const {
    if (abs(index) > 1) {
      throw std::invalid_argument("Index not in vector");
    }
    return vec[index];
  }

  /// @brief Replaces value in vector
  /// @param index Index of value
  /// @param value Value to be replaced with
  inline void at(const size_t index, T value) {
    if (abs(index) > 1) {
      throw std::invalid_argument("Index not in vector");
    }
    vec[index] = value;
    return;
  }

  /// @brief Gives access to the underlying array of this
  /// @return Underlying array
  inline T* data() { return vec; }

  /// @brief Gets first value of the vector3
  /// @return First value of the vector3
  inline T cfirst() const { return vec[0]; }

  /// @brief Gets first reference of the vector3
  /// @return First reference of the vector3
  inline T& first() { return vec[0]; }

  /// @brief Gets second value of the vector3
  /// @return Second value of the vector3
  inline T csecond() const { return vec[1]; }

  /// @brief Gets second reference of the vector3
  /// @return Second reference of the vector3
  inline T& second() { return vec[1]; }

  /// @brief Gets third value of the vector3
  /// @return Third value of the vector3
  inline T cthird() const { return vec[2]; }

  /// @brief Gets third reference of the vector3
  /// @return Third reference of the vector3
  inline T& third() { return vec[2]; }

  /// @brief Gets size of vector3
  /// @return 3
  inline size_t size() { return 3; }

  /// @brief Gets size of vector3 in bytes
  /// @return Size of vector3 in bytes
  inline size_t sizeof() { return sizeof(*this); }

  /// @brief Gets element at specified index
  /// @param index Index of element requested
  /// @return Value of element at specified index
  inline T operator[](size_t index) const { return vec[index]; }

  /// @brief References element at specified index
  /// @param index Index of element requested
  /// @return Reference to element at specified index
  inline T& operator[](size_t index) { return vec[index]; }

  /// @brief Adds a vector to this
  /// @param _vector Vector to be added to this
  /// @return This after addition
  /// @warning <T> will not be typecasted to <R> even if there's a loss of
  /// precision
  template <class R>
  vector3<T> add(vector3<R> _vector) {
    vec[0] += _vector[0];
    vec[1] += _vector[1];
    vec[2] += _vector[2];
    return *this;
  }

  /// @brief Subtracts a vector from this
  /// @param _vector Vector to be subtracted from this
  /// @return This after subtraction
  /// @warning <T> will not be typecasted to <R> even if there's a loss of
  /// precision
  template <class R>
  vector3<T> sub(vector3<R> _vector) {
    vec[0] -= _vector[0];
    vec[1] -= _vector[1];
    vec[2] -= _vector[2];
    return *this;
  }

  /// @brief Multiplies this by a scalar
  /// @param toMult Scalar to be multiplied to this
  /// @return This after multiplication
  /// @warning <T> will not be typecasted to <R> even if there's a loss of
  /// precision
  template <class R>
  vector3<T> mult(R toMult) {
    vec[0] *= toMult;
    vec[1] *= toMult;
    vec[2] *= toMult;
    return *this;
  }

#if defined(SSTD_PRINTCONT_HPP)
  /// @brief Prints this vector
  void print() const {
    std::cout << vec[0] << "\n" << vec[1] << "\n" << vec[2];
  }
#endif
};

template <typename T, typename R>
vector2<T> add(const vector2<T> base_vec, const vector2<R> _vector) {
  return vector2<T>(base_vec[0] + _vector[0], base_vec[1] + _vector[1]);
}

template <typename T, typename R>
vector2<T> sub(const vector2<T> base_vec, const vector2<R> _vector) {
  return vector2<T>(base_vec[0] - _vector[0], base_vec[1] - _vector[1]);
}

template <typename T, typename R>
vector2<T> mult(const vector2<T> base_vec, const R toMult) {
  return vector2<T>(base_vec[0] * toMult, base_vec[1] * toMult);
}

template <typename T, typename R>
vector2<T> mult(const R toMult, const vector2<T> _vector) {
  return vector2<T>(_vector[0] * toMult, _vector[1] * toMult);
}

#if defined(SSTD_PRINTCONT_HPP)

template <typename T>
void print(vector2<T> base_vec) {
  std::cout << "(" << base_vec[0] << ", " << base_vec[1] << ")";
}

#endif

}  // namespace sstd

#endif