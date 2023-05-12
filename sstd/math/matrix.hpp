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
 *
 * ============================================================================
 *
 * Header for matrix handling.
 *
 * Note: Matrices are mutated when executing methods but NOT when executing a
 * function.
 * NOTE As it is not possible to resize a matrix, matrix-matrix multiplication
 * is not included as a method.
 *
 */

#if !defined(SSTD_MATRIX_HPP)
#define SSTD_MATRIX_HPP

#include <array>
#include <cassert>
#include <exception>
#include <sstd/except/invCall.hpp>

namespace sstd {

template <class T, size_t sizeX, size_t sizeY>
class matrix2 {
 protected:
  T matx[sizeX][sizeY];

 public:
  // ANCHOR Constructors & destructors
  constexpr matrix2() {
    if (sizeX != sizeY)
      throw invCall("Identity matrix can only be applied to square matrix.");
    for (size_t i = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j) matx[i][j] = (i == j) ? 1 : 0;
  }
  template <class Iter>
  matrix2(const Iter begin, const Iter end) {
    if (end - begin != sizeX * sizeY)
      throw std::invalid_argument(
          "Number of elements in container must be sizeX * sizeY");
    for (size_t i = 0, ii = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j, ++ii) matx[i][j] = *(begin + ii);
  }
  matrix2(std::array<std::array<T, sizeX>, sizeY> _matrix) { matx = _matrix; }

  ~matrix2() {}

// ANCHOR I/O
#ifdef SSTD_PRINTCONT_HPP

  void print() const {
    for (size_t i = 0; i < sizeX; ++i) {
      for (size_t j = 0; j < sizeY; ++j) std::cout << matx[i][j] << " ";
      std::cout << "\n";
    }
  }

#endif

  // ANCHOR Arithmetic methods
  template <typename M>
  matrix2<T, sizeX, sizeY> mult(M toMult) {
    for (size_t i = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j) matx[i][j] *= toMult;
    return *this;
  }

  matrix2<T, sizeX, sizeY> add(matrix2<T, sizeX, sizeY> toAdd) {
    if (toAdd.X() != sizeX)
      throw std::invalid_argument("Width of matrices must be equal");
    if (toAdd.Y() != sizeY)
      throw std::invalid_argument("Height of matrices must be equal");
    for (size_t i = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j) matx[i][j] += toAdd.at(i, j);
    return *this;
  }

  matrix2<T, sizeX, sizeY> sub(matrix2<T, sizeX, sizeY> toAdd) {
    if (toAdd.X() != sizeX)
      throw std::invalid_argument("Width of matrices must be equal");
    if (toAdd.Y() != sizeY)
      throw std::invalid_argument("Height of matrices must be equal");
    for (size_t i = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j) matx[i][j] -= toAdd.at(i, j);
    return *this;
  }

  matrix2<T, sizeX, sizeY> negate() {
    for (size_t i = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j) matx[i][j] = -matx[i][j];
    return *this;
  }

  matrix2<T, sizeX, sizeY> transpose() {
    if (sizeX != sizeY)
      throw invCall("Tronsposition can only be applied on square matrices");
    std::array<std::array<T, sizeY>, sizeX> result;
    for (size_t i = 0; i < sizeX; ++i)
      for (size_t j = 0; j < sizeY; ++j) result[i][j] = matx[j][i];
    matx = result;
    return *this;
  }

  // ANCHOR Getter methods
  constexpr size_t X() const { return sizeX; }
  constexpr size_t Y() const { return sizeY; }
  std::array<std::array<T, sizeX>, sizeY> matrix() const { return matx; }
  T at(size_t _x, size_t _y) const {
    if (_x > sizeX)
      throw std::invalid_argument("_x not in range matrix.size()");
    if (_y > sizeY)
      throw std::invalid_argument("_y not in range matrix[0].size()");
    return matx[_x][_y];
  }
  matrix2<T, sizeX, sizeY> at(size_t _x, size_t _y, T value) {
    if (_x > sizeX)
      throw std::invalid_argument("_x not in range matrix.size()");
    if (_y > sizeY)
      throw std::invalid_argument("_y not in range matrix[0].size()");
    matx[_x][_y] = value;
    return *this;
  }
  inline std::array<T, sizeX> operator[](size_t index) { return matx[index]; }

#ifdef SSTD_VECTOR2_HPP

  // Somehow implement matrix-vector multiplication.

#endif
};

#ifdef SSTD_PRINTCONT_HPP

template <typename T, size_t sizeX, size_t sizeY>
void print(const matrix2<T, sizeX, sizeY> _matrix) {
  for (size_t i = 0; i < _matrix.X(); ++i) {
    for (size_t j = 0; j < _matrix.Y(); ++j)
      std::cout << _matrix.at(i, j) << " ";
    std::cout << "\n";
  }
}

#endif

template <typename T, size_t sizeX, size_t sizeY>
matrix2<T, sizeX, sizeY> add(const matrix2<T, sizeX, sizeY> _matrix,
                             const matrix2<T, sizeX, sizeY> toAdd) {
  if (toAdd.X() != _matrix.X())
    throw std::invalid_argument("Width of matrices must be equal");
  if (toAdd.Y() != _matrix.Y())
    throw std::invalid_argument("Height of matrices must be equal");
  matrix2<T, sizeX, sizeY> result;
  for (int i = 0; i < sizeX; ++i)
    for (int j = 0; j < sizeY; ++j)
      result.at(i, j, _matrix.at(i, j) + toAdd.at(i, j));
  return result;
}

template <typename T, size_t sizeX, size_t sizeY>
matrix2<T, sizeX, sizeY> sub(const matrix2<T, sizeX, sizeY> _matrix,
                             const matrix2<T, sizeX, sizeY> toSub) {
  if (toSub.X() != _matrix.X())
    throw std::invalid_argument("Width of matrices must be equal");
  if (toSub.Y() != _matrix.Y())
    throw std::invalid_argument("Height of matrices must be equal");
  matrix2<T, sizeX, sizeY> result;
  for (int i = 0; i < sizeX; ++i)
    for (int j = 0; j < sizeY; ++j)
      result.at(i, j, _matrix.get[i][j] - toSub.get[i][j]);
  return result;
}

template <typename T, size_t sizeX, size_t sizeY>
matrix2<T, sizeX, sizeY> mult(const matrix2<T, sizeX, sizeY> _matrix,
                              const T toMult) {
  matrix2<T, sizeX, sizeY> result;
  for (size_t i = 0; i < sizeX; ++i)
    for (size_t j = 0; j < sizeY; ++j)
      result.at(i, j, _matrix.at(i, j) * toMult);
  return result;
}

template <typename T, size_t sizeX, size_t temp, size_t sizeY>
matrix2<T, sizeX, sizeY> mult(const matrix2<T, sizeX, temp> _matrix,
                              const matrix2<T, temp, sizeY> toMult) {
  if (_matrix.Y() != toMult.X())
    throw std::invalid_argument(
        "Height of _matrix must equal to width of toMult");
  matrix2<T, sizeX, sizeY> result;
  for (int i = 0; i < sizeY; ++i)
    for (int j = 0; j < sizeX; ++j) {
      T sum = 0;
      for (int ii = 0; ii < temp; ++ii)
        sum += _matrix.at(i, ii) * toMult.at(ii, j);
      result.at(i, j, sum);
    }
  return result;
}

}  // namespace sstd

#endif /* MATRIX_HPP */
