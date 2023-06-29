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

#if !defined(SSTD_QUADRATIC_HH)
#define SSTD_QUADRATIC_HH

#include <array>
#include <cmath>
#include <complex>
#include <exception>
#include <utility>

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
std::pair<T, T> rquadratic(const T a, const T b, const T c) {
  const T disc = b * b - 4 * a * c;
  (void)(disc < 0 ? throw new std::invalid_argument(
                        "Only defined if b * b - 4ac >= 0")
                  : (void)0);
  return std::pair<T, T>{(-b - std::sqrt(disc)) * 0.5 / a,
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
std::pair<std::complex<T>, std::complex<T>> quadratic(const T a, const T b,
                                                      const T c) {
  const T disc = b * b - 4 * a * c;
  return (disc < 0)
             ? std::pair<std::complex<T>, std::complex<T>>{std::complex<T>{
                                                               -b * 0.5 / a,
                                                               -sqrt(-disc) *
                                                                   0.5 / a},
                                                           std::complex<T>{
                                                               -b * 0.5 / a,
                                                               sqrt(-disc) *
                                                                   0.5 / a}}
             : std::pair<std::complex<T>, std::complex<T>>{
                   std::complex<T>{(-b - std::sqrt(disc)) * 0.5 / a, 0},
                   std::complex<T>{(-b + std::sqrt(disc)) * 0.5 / a, 0}};
}

}  // namespace sstd

#endif
