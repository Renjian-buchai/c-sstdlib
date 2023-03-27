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

#ifndef PRINTCONT_HPP
#define PRINTCONT_HPP

#include <array>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <forward_list>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

namespace sstd {

/// @brief Prints vector.
/// @tparam T : Any type.
/// @param vector Vector to print.
template <typename T>
void printVec(std::vector<T> vector) {
  std::cout << "{ ";
  for (auto it = vector.begin(); it != vector.end(); ++it)
    std::cout << *it << " ";
  std::cout << "}\n";

  return;
}

/// @brief Prints std::array.
/// @tparam T : Any type.
/// @tparam N : Size of array.
/// @param array std::array to print.
template <typename T, std::size_t N>
void printArr(std::array<T, N> array) {
  std::cout << "{ ";
  for (auto it = array.begin(); it != array.end(); ++it)
    std::cout << *it << " ";
  std::cout << "}\n";

  return;
}

/// @brief Prints C-style array.
/// @tparam T : Any type.
/// @param array C-style array to print.
/// @param size Size of array.
template <typename T>
void printArr(T array[], std::size_t size) {
  std::cout << "{ ";
  for (size_t i = 0; i < size; ++i) std::cout << array[i] << " ";
  std::cout << "}\n";

  return;
}

/// @brief Prints forward list.
/// @tparam T : Any type.
/// @param flist Forward list to print.
template <typename T>
void printlist(std::forward_list<T> flist) {
  std::cout << "[ ";
  for (auto it = flist.begin(); it != flist.end(); ++it)
    std::cout << *it << " ";
  std::cout << "]\n";

  return;
}

/// @brief Prints list.
/// @tparam T : Any type.
/// @param list List to print.
template <typename T>
void printlist(std::list<T> list) {
  std::cout << "[ ";
  for (auto it = list.begin(); it != list.end(); ++it) std::cout << *it << " ";
  std::cout << "]\n";

  return;
}

/// @brief Prints queue.
/// @tparam T : Any type.
/// @param queue Queue to print.
template <typename T>
void printQ(std::queue<T> queue) {
  std::cout << "< ";
  for (auto it = queue.begin(); it != queue.end(); ++it)
    std::cout << *it << " ";
  std::cout << ">\n";

  return;
}

/// @brief Prints priority queue.
/// @tparam T : Any type.
/// @param queue Priority queue to print.
template <typename T>
void printQ(std::priority_queue<T> queue) {
  std::cout << "< ";
  for (auto it = queue.begin(); it != queue.end(); ++it)
    std::cout << *it << " ";
  std::cout << ">\n";

  return;
}

/// @brief Prints deque.
/// @tparam T : Any type.
/// @param queue Deque to print.
template <typename T>
void printQ(std::deque<T> queue) {
  std::cout << "< ";
  for (auto it = queue.begin(); it != queue.end(); ++it)
    std::cout << *it << " ";
  std::cout << ">\n";

  return;
}

/// @brief Prints map.
/// @tparam T : Any type.
/// @param map Map to print.
template <typename T>
void printMap(std::map<T, T> map) {
  std::cout << "[ ";
  for (auto it = map.begin(); it != map.end(); ++it) std::cout << *it << " ";
  std::cout << "]\n";

  return;
}

/// @brief Prints multimap.
/// @tparam T : Any type.
/// @param multimap Multimap to print.
template <typename T>
void printMap(std::multimap<T, T> multimap) {
  std::cout << "[ ";
  for (auto it = multimap.begin(); it != multimap.end(); ++it)
    std::cout << *it << " ";
  std::cout << "]\n";

  return;
}

/// @brief Prints set.
/// @tparam T : Any type.
/// @param set Set to print.
template <typename T>
void printSet(std::set<T> set) {
  std::cout << "{ ";
  for (auto it = set.begin(); it != set.end(); ++it) std::cout << *it << " ";
  std::cout << "}\n";

  return;
}

/// @brief Prints multiset.
/// @tparam T : Any type.
/// @param multiset Multiset to print.
template <typename T>
void printSet(std::multiset<T> multiset) {
  std::cout << "{ ";
  for (auto it = multiset.begin(); it != multiset.end(); ++it)
    std::cout << *it << " ";
  std::cout << "}\n";

  return;
}

}  // namespace sstd

#endif