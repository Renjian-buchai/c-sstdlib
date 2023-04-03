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
 *
 * ============================================================================
 *
 * British spelling ftw.
 */

#ifndef SSTD_COLOUR_HPP
#define SSTD_COLOUR_HPP

#include <ostream>

namespace sstd::Colour {

// #ifdef __LINUX__

// enum Code {
//   FG_RED = 31,
//   FG_GREEN = 32,
//   FG_BLUE = 34,
//   FG_DEFAULT = 39,
//   BG_RED = 41,
//   BG_GREEN = 42,
//   BG_BLUE = 44,
//   BG_DEFAULT = 49
// };
//
// class Modifier {
//   Code code;
//
//  public:
//   Modifier(Code pCode) : code(pCode) {}
//   friend std::ostream& operator<<(std::ostream& os, const Modifier& mod) {
//     return os << "\033[" << mod.code << "m";
//   }
// };

// #elif _WIN32 || _WIN64
//
// #include <windows.h>
// enum CODE {
//   BLACK = 0x0,
//   BLUE = 0x1,
//   GREEN = 0x2,
//   AQUA = 0x3,
//   RED = 0x4,
//   PURPLE = 0x5,
//   YELLOW = 0x6,
//   WHITE = 0x7,
//   GREY = 0x8,
//   LIGHT_BLUE = 0x9,
//   LIGHT_GREEN = 0xA,
//   LIGHT_AQUA = 0xB,
//   LIGHT_RED = 0xC,
//   LIGHT_PURPLE = 0xD,
//   LIGHT_YELLOW = 0xE,
//   BRIGHT_WHITE = 0xF
// };
//
// class MODIFIER {
//   CODE code;
//
//  public:
//   MODIFIER(Code _code) : code(_code) {}
// }

// #endif

}  // namespace sstd::Colour

#endif