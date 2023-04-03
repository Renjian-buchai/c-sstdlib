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

#ifndef SSTD_PRINTCONT_HPP
#define SSTD_PRINTCONT_HPP

#include <array>
#include <cmath>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <vector>

namespace sstd {

/// @brief Prints vector.
/// @tparam T : Any type.
/// @param vector Vector to print.
/// @param reversed Whether to reverse vector.
template <typename T>
void printVec(std::vector<T> vector, bool reversed = 0) {
  if (reversed) std::reverse(vector.begin(), vector.end());
  std::cout << "{ ";
  for (T x : vector) std::cout << std::to_string(x) << " ";
  std::cout << "}\n";
  return;
}

/// @brief Prints std::array.
/// @tparam T : Any type.
/// @tparam N : Size of array.
/// @param array std::array to print.
/// @param reversed Whether to reverse std::array.
template <typename T, std::size_t N>
void printArr(std::array<T, N> array, bool reversed = 0) {
  if (reversed) std::reverse(array.begin(), array.end());
  std::cout << "{ ";
  for (T x : array) std::cout << std::to_string(x) << " ";
  std::cout << "}\n";
  return;
}

/// @brief Prints C-style array.
/// @tparam T : Any type.
/// @param array C-style array to print.
/// @param size Size of array.
/// @param reversed Whether to reverse C-style array.
template <typename T>
void printArr(T array[], std::size_t size, bool reversed = 0) {
  std::cout << "{ ";
  if (reversed) {
    for (size_t i = size; i > 0; --i) std::cout << array[i] << " ";
  } else {
    for (size_t i = 0; i < size; ++i) std::cout << array[i] << " ";
  }
  std::cout << "}\n";
  return;
}

/// @brief Prints forward list.
/// @tparam T : Any type.
/// @param flist Forward list to print.
/// @param reversed Whether to reverse forward list.
template <typename T>
void printlist(std::forward_list<T> flist, bool reversed = 0) {
  if (reversed) std::reverse(flist.begin(), flist.end());
  std::cout << "[ ";
  for (T x : flist) std::cout << x << " ";
  std::cout << "]\n";
  return;
}

/// @brief Prints list.
/// @tparam T : Any type.
/// @param list List to print.
/// @param reversed Whether to reverse list.
template <typename T>
void printlist(std::list<T> list, bool reversed = 0) {
  if (reversed) std::reverse(list.begin(), list.end());
  std::cout << "[ ";
  for (T x : list) std::cout << x << " ";
  std::cout << "]\n";
  return;
}

/// @brief Prints map.
/// @tparam T : Any type.
/// @param map Map to print.
/// @param reversed Whether to reverse map.
template <typename T>
void printMap(std::map<T, T> map, bool reversed = 0) {
  if (reversed) std::reverse(map.begin(), map.end());
  std::cout << "[ ";
  for (T x : map) std::cout << x << " ";
  std::cout << "]\n";
  return;
}

/// @brief Prints multimap.
/// @tparam T : Any type.
/// @param multimap Multimap to print.
/// @param reversed Whether to reverse multimap.
template <typename T>
void printMap(std::multimap<T, T> multimap, bool reversed = 0) {
  if (reversed) std::reverse(multimap.begin(), multimap.end());
  std::cout << "[ ";
  for (T x : multimap) std::cout << x << " ";
  std::cout << "]\n";
  return;
}

/// @brief Prints set.
/// @tparam T : Any type.
/// @param set Set to print.
/// @param reversed Whether to reverse set.
template <typename T>
void printSet(std::set<T> set, bool reversed = 0) {
  if (reversed) std::reverse(set.begin(), set.end());
  std::cout << "{ ";
  for (T x : set) std::cout << x << " ";
  std::cout << "]\n";
  return;
}

/// @brief Prints multiset.
/// @tparam T : Any type.
/// @param multiset Multiset to print.
/// @param reversed Whether to reverse multiset.
template <typename T>
void printSet(std::multiset<T> multiset, bool reversed = 0) {
  if (reversed) std::reverse(multiset.begin(), multiset.end());
  std::cout << "{ ";
  for (T x : multiset) std::cout << x << " ";
  std::cout << "}\n";
  return;
}

}  // namespace sstd

#endif