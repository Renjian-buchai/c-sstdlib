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

#if !defined(SSTD_CONVERSION_HH)
#define SSTD_CONVERSION_HH

#include <cmath>
#include <utility>

namespace sstd {

/// @brief Converts degrees to radians.
/// @param degree Angle in degrees.
/// @tparam floatType : Any floating point type
/// @return Angle in radians.
template <typename floatType>
floatType dTR(floatType degree) {
  // pi / 180
  return degree *
         0.0174532925199432957692369076848861271344287188854172545609719144017100911460344944368224156963450948;
}

/// @brief Converts degrees to gradians.
/// @param degree Angle in degrees.
/// @tparam floatType : Any floating point type
/// @return Angle in gradians.
template <typename floatType>
floatType dTG(floatType degree) {
  // 200 / 180
  return degree *
         1.1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111;
}

/// @brief Converts radians to degrees.
/// @param radian Angle in radians.
/// @tparam floatType : Any floating point type
/// @return Angle in degrees.
template <typename floatType>
floatType rTD(floatType radian) {
  // 180 / PI
  return radian *
         57.2957795130823208767981548141051703324054724665643215491602438612028471483215526324409689958511109441;
}

/// @brief Converts radians to gradians.
/// @param radian Angle in radians.
/// @tparam floatType : Any floating point type
/// @return Angle in gradians.
template <typename floatType>
floatType rTG(floatType radian) {
  // 200 / PI
  return radian *
         63.6619772367581343075535053490057448137838582961825794990669376235587190536906140360455211065012343824;
}

/// @brief Converts gradians to radians.
/// @param gradian Angle in gradians.
/// @tparam floatType : Any floating point type
/// @return Angle in radians
template <typename floatType>
floatType gTR(floatType gradian) {
  // PI / 200
  return gradian *
         0.0157079632679489661923132169163975144209858469968755291048747229615390820314310449931401741267105853;
}

/// @brief Converts radians to gradians.
/// @param gradian Angle in gradians.
/// @tparam floatType : Any floating point type
/// @return Angle in radians.
template <typename floatType>
floatType gTD(floatType gradian) {
  // 180 / 200
  return gradian * 0.9;
}

namespace complex {

/// @brief Converts complex numbers from a + ib form to r(cosα + isinα).
/// @tparam T : Any arithmetic type.
/// @param real Real coefficient of complex number.
/// @param imaginary Imaginary coefficient of complex number.
/// @throw Domain error when imaginary & real are both 0.
/// @return Polar representation to complex number in std::pair.
/// First is the r value, and Second is the α value.
template <typename T>
std::pair<T, T> polRep(T real, T imaginary) {
  return std::pair<T, T>{
      std::sqrt(std::fabs(real * real + imaginary * imaginary)),
      std::atan2(imaginary, real)};
}

/// @brief Converts complex rumbers from r(cosα + isinα) form to a + bi.
/// @tparam T : Any arithmetic type.
/// @param r r-value of complex number.
/// @param alpha Alpha-value of complex number.
/// @return Complex representation of complex number in 2-size std::array. First
/// is the real coefficient, and Second is the imaginary coefficient.
template <typename T>
std::pair<T, T> compRep(T r, T alpha) {
  return std::pair<T, T>{r * std::cos(alpha), r * std::sin(alpha)};
}

}  // namespace complex

}  // namespace sstd

#undef SSTD_RECIPROCALOF180_BECAUSEOF_OPTIMISATION_REASONS
#undef SSTD_RECIPROCALOF200_BECAUSEOF_OPTIMISATION_REASONS

#endif