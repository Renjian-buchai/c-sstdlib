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

#ifndef SSTD_CONVERSION_HPP
#define SSTD_CONVERSION_HPP

#ifndef _PI_
#define _PI_ \
  3.1415926535'8979323846'2643383279'5028841971'6939937510'5820974944'5923078164'0628620899'8628034825'3421170679
#endif

namespace sstd {

/// @brief Converts degrees to radians.
/// @param degree Angle in degrees.
/// @return Angle in radians.
long double dTR(long double degree) { return degree * _PI_ / 180; }

/// @brief Converts degrees to gradians.
/// @param degree Angle in degrees.
/// @return Angle in gradians.
long double dTG(long double degree) { return degree / 360 * 400; }

/// @brief Converts radians to degrees.
/// @param radian Angle in radians.
/// @return Angle in degrees.
long double rTD(long double radian) { return radian * 180 / _PI_; }

/// @brief Converts radians to gradians.
/// @param radian Angle in radians.
/// @return Angle in gradians.
long double rTG(long double radian) { return radian * 200 / _PI_; }

/// @brief Converts gradians to radians.
/// @param gradian Angle in gradians.
/// @return Angle in radians.
long double gTR(long double gradian) { return gradian * _PI_ / 200; }

/// @brief Converts radians to gradians.
/// @param gradian Angle in gradians.
/// @return Angle in radians.
long double gTD(long double gradian) { return gradian * 0.9; }

}  // namespace sstd

#endif