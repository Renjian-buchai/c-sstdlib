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

#if !defined(SSTD_PRINTCONT_HH)
#define SSTD_PRINTCONT_HH

#include <algorithm>  /// std::reverse
#include <iostream>   /// std::cout
#include <string>     /// std::string

namespace sstd {

/// @brief Prints a container.
/// @tparam const_iter : Iterator
/// @param begin container.begin()
/// @param end container.end()
template <typename const_iter>
void print(const_iter begin, const_iter end) {
  std::cout << "{";
  for (; begin != end - 1; ++begin) std::cout << *begin << ", ";
  std::cout << *(--end) << "}";
}

template <typename const_iter>
std::string toStr(const_iter begin, const_iter end) {
  std::string result = "{";
  for (; begin != end - 1; ++begin) result += (std::string(*begin) + ", ");
  return result + *(--end) + "}";
}

}  // namespace sstd

#endif