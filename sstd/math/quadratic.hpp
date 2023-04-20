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

#if !defined(SSTD_QUADRATIC_HPP)

#include <array>
#include <cmath>
#include <complex>
#include <exception>

namespace sstd {

/// @brief Solves for real roots of quadratic equation.
/// @tparam T Any float type. Default=double
/// @param a Quadratic coefficient.
/// @param b Linear coefficient.
/// @param c Constant term.
/// @throw Domain error if b * b - 4 * a * c < 0.
/// @return Roots of equation in 2-size std::array. std::array[0] is the minus
/// value, std::array[1] is the plus value.
template <typename T = double>
std::array<T, 2> rqd(T a, T b, T c) {
  T disc = b * b - 4 * a * c;
  if (disc < 0)
    throw new std::invalid_argument("Only defined if b * b - 4ac >= 0");
  return std::array<T, 2>{(-b - std::sqrt(disc)) * 0.5 / a,
                          (-b + std::sqrt(disc)) * 0.5 / a};
}

/// @brief Solves for roots of quadratic equation.
/// @tparam T Any float type. Default=double
/// @param a Quadratic coefficient.
/// @param b Linear coefficient.
/// @param c Constant term.
/// @return Roots of equation in a 2-size std::array of complex numbers.
/// std::array[0] is the minus value, std::array[1] is the plus value.
template <typename T = double>
std::array<std::complex<T>, 2> qd(T a, T b, T c) {
  T disc = b * b - 4 * a * c;
  if (disc < 0)
    return std::array<std::complex<T>, 2>{
        std::complex<T>{-b * 0.5 / a, -sqrt(-disc) * 0.5 / a},
        std::complex<T>{-b * 0.5 / a, sqrt(-disc) * 0.5 / a}};
  return std::array<std::complex<T>, 2>{(-b - std::sqrt(disc)) * 0.5 / a,
                                        (-b + std::sqrt(disc)) * 0.5 / a};
}

}  // namespace sstd

#endif
