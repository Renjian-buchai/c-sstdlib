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

#if !defined(SSTD_CONVERSION_HPP)
#define SSTD_CONVERSION_HPP

#include <type_traits>

#if !defined(_PI_)
#define _PI_ \
  3.1415926535'8979323846'2643383279'5028841971'6939937510'5820974944'5923078164'0628620899'8628034825'3421170679
#endif

#define RECIPROCALOF180 \
  0.5555555555'5555555555'5555555555'5555555555'5555555555'5555555555'5555555555'5555555555'5555555555'5555555555
#define RECIPROCALOF200 0.005
#define RECPIROCALOFPI \
  0.3183098861'8379067153'7767526745'0287240689'1929148091'2897495334'6881177935'9526845307'0180227605'5325061719

template <typename Condition, typename T = void>
using enIf = typename std::enable_if<Condition::value, T>::type;

namespace sstd {

/// @brief Converts degrees to radians.
/// @param degree Angle in degrees.
/// @tparam floatType : Any floating point type
/// @return Angle in radians.
template <typename floatType, enIf<std::is_floating_point<floatType>>>
floatType dTR(floatType degree) {
  return degree * _PI_ * RECIPROCALOF180;
}

/// @brief Converts degrees to gradians.
/// @param degree Angle in degrees.
/// @tparam floatType : Any floating point type
/// @return Angle in gradians.
template <typename floatType, enIf<std::is_floating_point<floatType>>>
floatType dTG(floatType degree) {
  return degree * 200 * RECIPROCALOF180;
}

/// @brief Converts radians to degrees.
/// @param radian Angle in radians.
/// @tparam floatType : Any floating point type
/// @return Angle in degrees.
template <typename floatType, enIf<std::is_floating_point<floatType>>>
floatType rTD(floatType radian) {
  return radian * 180 / _PI_;
}

/// @brief Converts radians to gradians.
/// @param radian Angle in radians.
/// @tparam floatType : Any floating point type
/// @return Angle in gradians.
template <typename floatType, enIf<std::is_floating_point<floatType>>>
floatType rTG(floatType radian) {
  return radian * 200 / _PI_;
}

/// @brief Converts gradians to radians.
/// @param gradian Angle in gradians.
/// @tparam floatType : Any floating point type
/// @return Angle in radians
template <typename floatType, enIf<std::is_floating_point<floatType>>>
floatType gTR(floatType gradian) {
  return gradian * _PI_ * RECIPROCALOF200;
}

/// @brief Converts radians to gradians.
/// @param gradian Angle in gradians.
/// @tparam floatType : Any floating point type
/// @return Angle in radians.
template <typename floatType, enIf<std::is_floating_point<floatType>>>
floatType gTD(floatType gradian) {
  return gradian * 0.9;
}

}  // namespace sstd

#undef R180
#undef R200

#endif