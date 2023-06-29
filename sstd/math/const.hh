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

#if !defined(SSTD_CONSTANTS_HH)
#define SSTD_CONSTANTS_


#include <cmath>

// Mathematical constants (100 decimal places)
#define _SILV_ \
  2.4142135623'7309504880'1688724209'6980785696'7187537694'8073176679'7379907324'7846210703'8850387534'3276415727
#define _TAU_ \
  6.2831853071'7958647692'5286766559'0057683943'3879875021'1641949889'1846156328'1257241799'7256069650'6842341359
#define _EUL_ \
  2.7182818284'5904523536'0287471352'6624977572'4709369995'9574966967'6277240766'3035354759'4571382178'5251664274
#define _PHI_ \
  1.6180339887'4989484820'4586834365'6381177203'0917980576'2862135448'6227052604'6281890244'9707207204'1893911374
#define _EUC_ \
  0.5772156649'0153286060'6512090082'4024310421'5933593992'3598805767'2348848677'2677766467'0936947063'2917467495
#define _LAP_ \
  0.6627434193'4918158097'4742097109'2529070562'3354911502'2417520392'5349909718'5308651127'7249654802'5989581816
#define _OM_ \
  0.5671432904'0978387299'9968662210'3555497538'1578718651'2508135131'0792230457'9308668456'6693219446'9617522945
#define _PI_ \
  3.1415926535'8979323846'2643383279'5028841971'6939937510'5820974944'5923078164'0628620899'8628034825'3421170679

// Physical constants (SI units, arranged in descending precision. )
// Velocity of light in vacuum.   Precise                (ms-1).
#define _VLT_ 299'792'458
// Rydberg constant.              16 significant figures (m-1).
#define _RYD_ 2.179'872'361'103'542
// Vacuum magnetic permeability.  14 significant figures (NA-1).
#define _MU0_ 1.256'637'062'121'9 * std::pow(10, -6)
// Electron mass.                 13 significant figures (kg).
#define _Me_ 9.109'383'701'528 * std::pow(10, -31)
// 1/File construct constant.     12 significant figures (NULL).
#define _FCC_ 137.035'999'084'21
// Fine construct constant.       12 significant figures (NULL)
#define _fcc_ 0.00729'735'256'286
// Elementary charge.             10 significant figures (C).
#define _ELC_ 1.602'176'634 * std::pow(10, -19)
// Magnetic flux quantum.         10 significant figures (HzV-1).
#define _MFQ_ 2.067'833'848 * std::pow(10, -15)
// Vacuum electric permutivity.   10 significant figures (Fm-1)
#define _EP0_ 8.854'187'812 * std::pow(10, -12)
// Reduced planck constant.       10 significant figures (JHz-1).
#define _HCT_ (_H_ / _PI_) * std::pow(10, -34)
// Planck constant.               10 significant figures (JHz-1).
#define _H_ 6.626'070'150 * std::pow(10, -34)
// Gravitational constant.        8 significant figures  (m3kg-1s-2)
#define _G_ 6.674'301'5 * std::pow(10, -11)

// Pseudoconstants (Not constant, but commonly used.)
// Gravity (Earth).               6 significant figures  (ms-2)
#define _g_ 9.806'65

// Others
// Mole.                          9 significant figures  (NULL)
#define _mol_ 6.022'140'76 * std::pow(10, 23)

#endif