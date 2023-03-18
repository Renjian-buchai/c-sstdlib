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

#ifndef IO_HPP
#define IO_HPP

#include <array>
#include <cmath>
#include <cstdlib>
#include <forward_list>
#include <iostream>
#include <list>
#include <vector>

namespace sstd {

template <typename T>
void printvec(std::vector<T> vxtor) {
  std::cout << "{ ";
  for (auto it = vxtor.begin(); it != vxtor.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "}\n";

  return;
}

template <typename T, std::size_t N>
void printarr(std::array<T, N> arr) {
  std::cout << "{ ";
  for (auto it = arr.begin(); it != arr.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "}\n";

  return;
}

template <typename T>
void printlist(std::forward_list<T> flist) {
  std::cout << "[ ";
  for (auto it = flist.begin(); it != flist.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "]\n";

  return;
}

template <typename T>
void printlist(std::list<T> list) {
  std::cout << "[ ";
  for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << " ";
  }
  std::cout << "]\n";

  return;
}

}  // namespace sstd

#endif /* IO_HPP */