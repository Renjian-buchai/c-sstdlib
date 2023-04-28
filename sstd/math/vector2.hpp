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

#include <array>
#include <iterator>
#include <stdexcept>

namespace sstd {

template <class T>
class vector2 {
 protected:
  std::array<T, 2> vec{0, 0};

 public:
  vector2() = default;
  template <class Iter>
  vector2(const Iter begin, const Iter end) {
    if (end - begin != 2)
      throw std::invalid_argument("Size of container is wrong");
    for (auto copy = begin, it = vec.begin(); copy != end; ++copy, ++it)
      *it = *copy;
  }

  T get(const size_t index) const {
    if (abs(index) > 2) throw std::invalid_argument("Index not in vector");
    return vec[index];
  }

  void get(const size_t index, const T value) {
    if (abs(index) > 2) throw std::invalid_argument("Index not in vector");
    vec[index] = value;
  }
}

// template <class T, size_t N>
// class vector {
//  protected:
//   std::array<T, N> vec = {0};
//   size_t sz;
//
//  public:
//   vector() {
//     sz = N;
//     for (auto i = 0; i != vec.size(); ++i) vec[i] = 0;
//   };
//   template <class Iter>
//   vector(const Iter begin, const Iter end) {
//     sz = N;
//     if (end - begin != sz)
//       throw std::invalid_argument("Size of container is wrong");
//     for (auto copy = begin, it = vec.begin(); copy != end; ++copy, ++it)
//       *it = *copy;
//   }
//
//   T get(long index) {
//     if (abs(index) > n) throw std::invalid_argument("Index not in vector.");
//   }
//
//   std::iterator begin() { return vec.begin(); }
//   std::iterator end() { return vec.end(); }
// }

}  // namespace sstd