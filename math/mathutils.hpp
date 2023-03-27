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

#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>
#include <type_traits>

/// @brief Template to enable template if Condition evaluates true.
/// @tparam Condition : condition to evaluate.
/// @tparam T : template.
/// @note example: template <typename T, EnableIf<std::is_arithmetic<T>>>
template <typename Condition, typename T = void>
using enIf = typename std::enable_if<Condition::value, T>::type;

namespace sstd {
/// @brief Finds the highest common faction of two positive integers
/// @param x unsigned long long.
/// @param y unsigned long long.
/// @return Highest common factor of x and y.
unsigned long long hcf(unsigned long long x, unsigned long long y) {
  if (x == 0) return y;
  if (y == 0) return x;
  if (x == y) return x;
  if (x > y) return hcf(x - y, y);
  return hcf(x, y - x);
}

/// @brief Finds the lowest common multiple of two positive integers.
/// @param x unsigned long long.
/// @param y unsigned long long.
/// @return Lowest common multiple of x and y.
unsigned long long lcm(unsigned long long x, unsigned long long y) {
  return (x * y) / hcf(x, y);
}

// TODO Test this lmao
unsigned long long randomise(unsigned long lower = 0,
                             unsigned long upper = UINT32_MAX) {
  std::srand(std::time(nullptr));
  return (std::rand() + lower) % upper;
}

/// @brief Quake III quick inverse square root. Single precision.
/// @param x Value to find inverse square root for.
/// @return Inverse square root.
/// @warning Undefined behaviour.
double qisqrt(double x) {
  long long i;
  double x2, y;

  x2 = x * .5;
  y = x;
  i = *(long long*)&y;
  i = 0x5f3759df - (i >> 1);
  y = *(long double*)&i;
  y = y * (1.5 - x2 * y * y);

  return y;
}

/// @brief Quake III quick inverse square root. Double precision.
/// @param x Value to find inverse square root for.
/// @return Inverse square root.
/// @warning Undefined behaviour.
double q_isqrt(double x) {
  long long i;
  double x2, y;

  x2 = x * .5;
  y = x;
  i = *(long long*)&y;
  i = 0x5f3759df - (i >> 1);
  y = *(long double*)&i;
  y = y * (1.5 - x2 * y * y);
  y = y * (1.5 - x2 * y * y);

  return y;
}

/// @brief Quake III quick inverse square root. Variable precision.
/// @param x Value to find inverse square root for.
/// @param precision Precision of estimate.
/// @return Inverse square root.
/// @warning Undefined behaviour.
double qisqrt(double x, unsigned int precision) {
  long long i;
  double x2, y;

  x2 = x * .5;
  y = x;
  i = *(long long*)&y;
  i = 0x5f3759df - (i >> 1);
  y = *(long double*)&i;
  for (int k = 0; k < precision + 3; ++k) {
    y = y * (1.5 - x2 * y * y);
  }

  return y;
}

/// @brief SSE inverse square root.
/// @param x Value to find inverse square root for.
/// @return Inverse square root.
/// @note Faster than qisqrt, but only accepts single-precision floating point
/// values. I don't know how to convert this to accept double-precision floating
/// point values. No undefined behaviour, though.
/// @note F in fisqrt stands for float and fast.
float fisqrt(float x) {
  __m128 _srcReisger = _mm_set1_ps(x);
  __m128 _dstRegister = _mm_rsqrt_ps(_srcReisger);
  float array[4];
  _mm_storeu_ps(array, _dstRegister);
  return array[0];
}

}  // namespace sstd

#endif /* MATHUTILS_HPP */
