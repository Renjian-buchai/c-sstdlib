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
#include <cstdlib>
#include <exception>
#include <iostream>
#include <sstd/except/invCall.hpp>
#include <type_traits>
#include <vector>

// TODO Add reason

template <typename Condition, typename T = void>
using enIf = typename std::enable_if<Condition::value, T>::type;

namespace sstd {

/// @brief 2-dimensional matrix class.
/// @tparam T : Any arithmetic type.
/// @tparam dX : Number of columns in matrix.
/// @tparam dY : Number of rows in matrix.
template <class T, size_t dX, size_t dY>
class matrix2 {
 private:
  std::array<std::array<T, dY>, dX> matrix;

 public:
  /// @brief Fills matrix with an array.
  /// @param valueSet Array to fill matrix with. Size of array must equal the
  /// number of elements in matrix.
  matrix2(std::array<T, dX * dY> valueSet) {
    size_t k = 0;
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[i].size(); ++j, ++k) {
        matrix[i][j] = valueSet[k];
      }
    return;
  }

  /// @brief Fills matrix with a 2-dimensional array.
  /// @param valueSet 2-dimensional array to fill matrix with. Size of array
  /// must equal the size of matrix.
  matrix2(std::array<std::array<T, dY>, dX> valueSet) {
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[0].size(); ++j) {
        matrix[i][j] = valueSet[i][j];
      }
    return;
  }

  /// @brief Allows user to input elements into a matrix.
  /// @param x Any integer. Only used to differentiate between
  /// matrix2::matrix2(int) and matrix2::matrix2()
  matrix2(int x) {
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[0].size(); ++j) {
        std::cout << "Element " << i + 1 << ", " << j + 1 << ": ";
        std::cin >> matrix[i][j];
      }
    return;
  }

  /// @brief Creates an identity matrix. An identity matrix is a matrix that
  /// is multiplied to another matrix to return the latter matrix itself. i.e.
  /// matrix * identity matrix = matrix
  /// @note Dependencies:
  /// @note sstd/except/invCall.hpp -> invCall
  matrix2() {
    if (matrix.size() != matrix[0].size())
      throw invCall("Identity matrices must be square");
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[1].size(); ++j) matrix[i][j] = 0;
    for (size_t i = 0; i < matrix.size(); ++i) matrix[i][i] = 1;
  }

#if defined(SSTD_PRINTCONT_HPP)
  /// @brief Prints matrix. Each element is separated by a space.
  void printMatrix() {
    std::cout << std::endl;
    for (size_t i = 0; i < matrix.size(); ++i) {
      for (size_t j = 0; j < matrix[0].size(); ++j)
        std::cout << matrix[i][j] << " ";
      std::cout << "\n";
    }
    return;
  }
#endif

  /// @brief Adds a matrix to this matrix.
  /// @param _matrix Matrix of the same size as this.
  /// @return This.
  matrix2* add(matrix2<T, dX, dY> _matrix) {
    if (matrix.size() != _matrix.getMatrix().size() ||
        matrix[1].size() != _matrix.getMatrix()[1].size())
      throw std::invalid_argument("Matrix must be same sized");
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[0].size(); ++j)
        matrix[i][j] += _matrix.getMatrix()[i][j];
    return this;
  }

  /// @brief Subtracts a matrix from this matrix.
  /// @param _matrix Matrix of the same size as this.
  /// @return This.
  /// @note If you want to subtract this matrix from another, do it from the
  /// other matrix.
  matrix2* sub(matrix2<T, dX, dY> _matrix) {
    if (matrix.size() != _matrix.getMatrix().size() ||
        matrix[1].size() != _matrix.getMatrix()[1].size())
      throw std::invalid_argument("Matrix must be same sized");
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[0].size(); ++j)
        matrix[i][j] += _matrix.getMatrix[i][j];
    return this;
  }

  /// @brief Multiplies a matrix by a scalar.
  /// @tparam arithType : Any arithmetic type.
  /// @param toMult Scalar to multiply this vector by.
  /// @return This.
  template <typename arithType, enIf<std::is_arithmetic<arithType>>>
  matrix2* mult(arithType toMult) {
    for (size_t i = 0; i < matrix.size(); ++i)
      for (size_t j = 0; j < matrix[0].size(); ++j)
        matrix[i][j] = matrix[i][j] * toMult;
    return this;
  }

  /*---------------------------- Getter methods ----------------------------*/

  /// @brief Gets matrix.
  /// @return Matrix.
  matrix2 getMatrix() { return matrix; };
};

/// @brief Adds a matrix to another. Commutative.
/// @tparam T : Any arithmetic type.
/// @tparam dX : Number of columns in a matrix.
/// @tparam dY : Number of rows in a matrix.
/// @param _base_matrix Matrix to be added to.
/// @param _matrix Matrix to be added.
/// @return Summed matrix.
template <typename T, size_t dX, size_t dY>
matrix2<T, dX, dY> add(matrix2<T, dX, dY> _base_matrix,
                       matrix2<T, dX, dY> _matrix) {
  if (_matrix.getMatrix().size() != _base_matrix.getMatrix().size() ||
      _matrix.getMatrix()[1].size() != _base_matrix.getMatrix()[1].size())
    throw std::invalid_argument("Matrix must be same sized");
  std::array<std::array<T, dX>, dY> _res_matrix;
  for (size_t i = 0; i < _matrix.getMatrix().size(); ++i)
    for (size_t j = 0; j < _matrix.getMatrix()[0].size(); ++j)
      _res_matrix[i][j] =
          _base_matrix.getMatrix()[i][j] + _matrix.getMatrix()[i][j];
  return matrix2<T, dX, dY>(_res_matrix);
}

/// @brief Subtracts a matrix from another. Not commutative.
/// @tparam T : Any arithmetic type.
/// @tparam dX : Number of columns in a matrix.
/// @tparam dY : Number of rows in a matrix.
/// @param _base_matrix Matrix to bo subtracted from.
/// @param _matrix Matrix to be subtracted.
/// @return Difference in matrices.
template <typename T, size_t dX, size_t dY>
matrix2<T, dX, dY> sub(matrix2<T, dX, dY> _base_matrix,
                       matrix2<T, dX, dY> _matrix) {
  if (_matrix.getMatrix().size() != _base_matrix.getMatrix().size() ||
      _matrix.getMatrix()[1].size() != _base_matrix.getMatrix()[1].size())
    throw std::invalid_argument("Matrix must be same sized");
  std::array<std::array<T, dX>, dY> _res_matrix;
  for (size_t i = 0; i < _matrix.getMatrix().size(); ++i)
    for (size_t j = 0; j < _matrix.getMatrix()[0].size(); ++j)
      _res_matrix[i][j] =
          _base_matrix.getMatrix()[i][j] - _matrix.getMatrix()[i][j];
  return matrix2<T, dX, dY>(_res_matrix);
}

/// @brief Multiplies 2 matrices. Not commutative.
/// @tparam T : Any arithmetic type.
/// @tparam dX : Number of columns in output matrix.
/// @tparam N : Number to be chained.
/// @tparam dY : Number of rows in output matrix.
/// @param _base_matrix Matrix to be multiplied.
/// @param _matrix Matrix to multiplied.
/// @return Product of matrices.
template <typename T, size_t dX, size_t N, size_t dY>
matrix2<T, dX, dY> mult(matrix2<T, dX, N> _base_matrix,
                        matrix2<T, N, dY> _matrix) {
  if (_base_matrix.getMatrix().size() != _base_matrix.getMatrix()[0].size())
    throw std::invalid_argument("Matrix must be same sized");
  std::array<std::array<T, dX>, dY> _res_matrix;
  for (size_t i = 0; i < _res_matrix.size(); ++i)
    for (size_t j = 0; j < _res_matrix[0].size(); ++j)
      for (size_t ii = 0; ii < _matrix.getMatrix()[0].size(); ++ii)
        _res_matrix[i][j] =
            _base_matrix.getMatrix[i][ii] * _matrix.getMatrix[ii][j];
  return matrix2<T, dX, dY>(_res_matrix);
}

/// @brief Multiplies a matrix by a scalar. Commutative.
/// @tparam T : Any arithmetic type.
/// @tparam dX : Number of columns in matrix.
/// @tparam dY : Number of rows in matrix.
/// @param _base_matrix Matrix to be multiplied.
/// @param toMult scalar to be multiplied.
/// @return Product of matrices.
template <typename T, size_t dX, size_t dY>
matrix2<T, dX, dY> mult(matrix2<T, dX, dY> _base_matrix, T toMult) {
  std::array<std::array<T, dX>, dY> _res_matrix;
  for (size_t i = 0; i < _res_matrix.size(); ++i)
    for (size_t j = 0; j < _res_matrix[0].size(); ++j)
      _res_matrix[i][j] = _base_matrix.getMatrix()[i][j] * toMult;
  return matrix2<T, dX, dY>(_res_matrix);
}

/// @brief Multiplies a matrix by a scalar. Commutative.
/// @tparam T : Any arithmetic type.
/// @tparam dX : Number of columns in matrix.
/// @tparam dY : Number of rows in matrix.
/// @param toMult scalar to be multiplied.
/// @param _base_matrix Matrix to be multiplied.
/// @return Product of matrices.
template <typename T, size_t dX, size_t dY>
matrix2<T, dX, dY> mult(T toMult, matrix2<T, dX, dY> _base_matrix) {
  std::array<std::array<T, dX>, dY> _res_matrix;
  for (size_t i = 0; i < _res_matrix.size(); ++i)
    for (size_t j = 0; j < _res_matrix[0].size(); ++j)
      _res_matrix[i][j] = _base_matrix.getMatrix()[i][j] * toMult;
  return matrix2<T, dX, dY>(_res_matrix);
}

}  // namespace sstd

#endif /* MATRIX_HPP */
