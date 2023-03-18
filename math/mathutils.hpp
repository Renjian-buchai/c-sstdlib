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

#include <type_traits>

template <typename Condition, typename T = void>
/// @brief Template to enable template if Condition evaluates true.
/// @tparam Condition : condition to evaluate.
/// @tparam T : template.
/// @note example: template <typename T, EnableIf<std::is_arithmetic<T>>>
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

}  // namespace sstd

#endif /* MATHUTILS_HPP */