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

#ifndef SSTD_MATRIX_HPP
#define SSTD_MATRIX_HPP

#include <array>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <type_traits>
#include <vector>

using namespace std;

namespace sstd {

class matrix2 {
 public:
  std::size_t sizeX = 1;
  std::size_t sizeY = 1;
  std::vector<std::vector<long double>> matrix;

  /// @brief Generates matrix of size sizeY * sizeX.
  /// @param _sizeY sizeY
  /// @param _sizeX sizeY
  /// @note Try not to die.
  matrix2(std::size_t _sizeY, std::size_t _sizeX) {
    if (0 == _sizeX) throw std::invalid_argument("NullPointerException: X");
    if (0 == _sizeY) throw std::invalid_argument("NullPointerException: Y");
    if (_sizeY < 0)
      throw std::invalid_argument("NegativeArraySizeException: Y");
    if (_sizeX < 0)
      throw std::invalid_argument("NegativeArraySizeException: X");

    sizeX = _sizeX;
    sizeY = _sizeY;
    matrix.resize(sizeY);

    for (auto it = matrix.begin(); it != matrix.end(); ++it) {
      it->resize(sizeX);
    }
  }

  /// @brief Fills matrix with values.
  /// @tparam arithType : Must be an arithmetic type.
  /// @param valueSet The values to fill matrix with. The vector must be of
  /// size: sizeY * sizeX.
  /// @note Dependenies:
  /// @note mathutils.hpp -> enIf (template arg)
  template <typename arithType, typename = enIf<std::is_arithmetic<arithType>>>
  void fillMatrix(std::vector<arithType> valueSet) {
    auto it = valueSet.begin();
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        matrix[i][j] = *it;
        ++it;
      }
    }

    return;
  }

  /// @brief Fills matrix with values.
  /// @tparam arithType : Must be an arithmetic type.
  /// @param valueSet The values to fill matrix with. The vector must be of
  /// size: sizeX, and the vector vect must be of size: sizeY.
  template <typename arithType, typename = enIf<std::is_arithmetic<arithType>>>
  void fillMatrix(std::vector<std::vector<arithType>> valueSet) {
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[i].size(); ++j) {
        matrix[i][j] = valueSet[i][j];
      }
    }

    return;
  }

  /// @brief Allows user to add matrix values one by one by prompting.
  void cinMatrix() {
    for (size_t i = 0; i < sizeY; ++i) {
      for (size_t j = 0; j < sizeX; ++j) {
        std::cout << "Element " << i + 1 << ", " << j + 1 << ": ";
        std::cin >> matrix[i][j];
      }
    }
    return;
  }

  /// @brief Prints matrix row by row, separated by spaces. Each column is
  /// separated by \\n characters.
  void printMatrix() {
    std::cout << std::endl;
    for (size_t i = 0; i < sizeY; ++i) {
      for (size_t j = 0; j < sizeX; ++j) {
        std::cout << matrix[i][j] << " ";
      }
      std::cout << "\n";
    }

    return;
  }

  /// @brief Adds a matrix to this matrix.
  /// @param m1 Matrix to add.
  /// @return Sum of matrices
  matrix2* add(matrix2 m1) {
    if (sizeX != m1.sizeX || sizeY != m1.sizeY)
      throw std::invalid_argument("NoSolution");

    for (size_t i = 0; i < sizeY; ++i) {
      for (size_t j = 0; j < sizeX; ++j) {
        matrix[i][j] = matrix[i][j] + m1.matrix[i][j];
      }
    }

    return this;
  }

  /// @brief Subtracts a matrix from this matrix.
  /// @param m1 Matrix to subtract.
  /// @return Difference of matrix.
  /// @note If you want to subtract this matrix from something, call the
  /// subtract method from that matrix instead.
  matrix2* subtract(matrix2 m1) {
    if (sizeX != m1.sizeX || sizeY != m1.sizeY) {
      throw std::invalid_argument("NoSolution");
    }

    for (size_t i = 0; i < sizeY; ++i)
      for (size_t j = 0; j < sizeX; ++j)
        matrix[i][j] = matrix[i][j] - m1.matrix[i][j];

    return this;
  }

  template <typename intType, enIf<std::is_integral<intType>>>
  matrix2* multiply(intType integral) {
    for (size_t i = 0; i < sizeY; ++i)
      for (size_t j = 0; j < sizeX; ++j) matrix[i][j] = matrix[i][j] * integral;

    return this;
  }
};

/// @brief Adds two matrices together. Commutative.
/// @param m1 Matrix to be added to.
/// @param m2 Matrix to add.
/// @return Sum.
matrix2 matrixAdd(matrix2 m1, matrix2 m2) {
  if (m1.sizeX != m2.sizeX || m1.sizeY != m2.sizeY)
    throw std::invalid_argument("NoSolution");

  matrix2 m3(m1.sizeX, m1.sizeY);

  for (size_t i = 0; i < m1.sizeY; ++i)
    for (size_t j = 0; j < m1.sizeX; ++j)
      m3.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];

  return m3;
}

/// @brief Subtracts a matrix from another matrix. Not commutative.
/// @param m1 Matrix to subtract from.
/// @param m2 Matrix to be subtracted.
/// @return Difference
matrix2 matrixSub(matrix2 m1, matrix2 m2) {
  if (m1.sizeX != m2.sizeX && m1.sizeY != m2.sizeY)
    throw std::invalid_argument("NoSolution");

  matrix2 m3(m1.sizeX, m1.sizeY);

  for (size_t i = 0; i < m1.sizeY; ++i)
    for (size_t j = 0; j < m1.sizeX; ++j)
      m3.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];

  return m3;
}

/// @brief Multiplies a matrix by a scalar. Commutative.
/// @tparam arithType : Must be an arithmetic type.
/// @param toMult Scalar to multiply matrix with.
/// @param m1 Matrix to be multiplied.
/// @return Product.
template <typename arithType, typename = enIf<std::is_arithmetic<arithType>>>
matrix2 matrixMult(arithType toMult, matrix2 m1) {
  matrix2 m3(m1.sizeY, m1.sizeX);
  for (std::size_t i = 0; i < m1.sizeY; ++i)
    for (std::size_t j = 0; j < m1.sizeX; ++j)
      m3.matrix[j][i] = m1.matrix[j][i] * toMult;

  return m3;
}

/// @brief Multiplies a matrix by a scalar. Commutative.
/// @tparam arithType : Must be an arithmetic type.
/// @param m1 Matrix to be multiplied.
/// @param toMult Scalar to multiply matrix with.
/// @return Product.
template <typename arithType, typename = enIf<std::is_arithmetic<arithType>>>
matrix2 matrixMult(matrix2 m1, arithType toMult) {
  matrix2 m3(m1.sizeY, m1.sizeX);

  for (std::size_t i = 0; i < m1.sizeY; ++i)
    for (std::size_t j = 0; j < m1.sizeX; ++j)
      m3.matrix[j][i] = m1.matrix[j][i] * toMult;

  return m3;
}

matrix2 matrixMult(matrix2 m1, matrix2 m2) {
  if (m1.sizeX != m2.sizeY) {
    throw std::invalid_argument("NoSolution");
  }

  matrix2 m3(m1.sizeY, m2.sizeX);

  for (size_t i = 0; i < m3.sizeY; ++i) {
    for (size_t j = 0; j < m3.sizeX; ++j) {
      m3.matrix[i][j] = 0;
      for (size_t ii = 0; ii < m2.sizeY; ++ii)
        m3.matrix[i][j] += m1.matrix[i][ii] * m2.matrix[ii][j];
    }
  }

  return m3;
}

}  // namespace sstd

#endif /* MATRIX_HPP */
