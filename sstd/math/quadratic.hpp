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

namespace sstd {

/// @brief Solves for roots of quadratic equation in the fastest time.
/// @tparam T Any arithmetic type.
/// @param squared x^2 term.
/// @param linear x term.
/// @param constant constant term.
/// @throw Domain error if b * b - 4 * a * c < 0.
/// @return Roots of equation in 2-size std::array. std::array[0] is the minus
/// value, std::array[1] is the plus value.
template <typename T>
std::array<T, 2> qd(T squared, T linear, T constant) {
  return std::array<T, 2>{
    (-linear - std::sqrt(linear * linear - 4 * squared * constant)) * 0.5 /
        squared,
    (-linear + std::sqrt(linear * linear - 4 * squared * constant)) * 0.5 /
        squared)};
}

/// @brief Solves for roots of quadratic equation.
/// @tparam T Any arithmetic type.
/// @param squared x^2 term.
/// @param linear x term.
/// @param constant constant term.
/// @return Roots of equation in 4-size std::array. std::array[0] contains the
/// real component of the minus value, std::array[1] contains the imaginary
/// component of the minus value, std::array[2] contains the real component of
/// the plus value, std::array[3] contains the imaginary component of the plus
/// value.
template <typename T>
std::array<T, 4> quadratic(T squared, T linear, T constant) {
  long double disc = linear * linear - 4 * squared * constant;

  if (disc < 0) {
    return std::array<T, 4>{
        -linear * 0.5 / a, -std::sqrt(std::fabs(disc)) * 0.5 / a,
        -linear * 0.5 / a, std::sqrt(std::fabs(disc)) * 0.5 / a};
  } else {
    return std::array<T, 2>{(-linear - std::sqrt(disc)) * 0.5 / squared, 0,
                            (-linear + std::sqrt(disc)) * 0.5 / squared, 0};
  }
}

}  // namespace sstd

#endif
