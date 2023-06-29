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

#include <algorithm>
#include <array>
#include <stdexcept>

namespace sstd {

template <class T, size_t N>
class sorted_array {
 protected:
  std::array<T, N> arr;

 public:
  sorted_array() {
    for (T x : arr) x = 0;
  }
  sorted_array(std::array<T, N> _array) {
    arr = _array;
    std::sort(arr);
  }
  template <class Iter>
  sorted_array(const Iter begin, const Iter end) {
    if (end - begin != N)
      throw std::invalid_argument("Size of container is wrong");
    std::copy(begin, end, arr.begin());
    std::sort(arr);
  }

  inline T operator[](size_t index) const { return arr[index]; }

  inline T at(size_t index) const { return arr[index]; }
  inline void at(size_t index, T value) {
    arr[index] = value;
    std::sort(arr);
  }

  inline std::array<T, 2> data() const { return arr; }

  template <typename Iter>
  inline Iter begin() const {
    return arr.begin();
  }

  template <typename Iter>
  inline Iter end() const {
    return arr.end();
  }

  template <typename Iter>
  inline Iter rend() const {
    return arr.rend();
  }

  template <typename Iter>
  inline Iter rbegin() const {
    return arr.rbegin();
  }

  template <typename Iter>
  inline Iter const cbegin() const {
    return arr.cbegin();
  }

  template <typename Iter>
  inline Iter const cend() const {
    return arr.cend();
  }

  template <typename Iter>
  inline Iter const crbegin() const {
    return arr.cbegin();
  }

  template <typename Iter>
  inline Iter const crend() const {
    return arr.crend();
  }

  inline bool empty() { return arr.empty(); }

  inline short size() const noexcept { return 2; }

  constexpr size_t max_size() const noexcept { return arr.max_size(); }

#if defined(SSTD_PRINTCONT_HH)
  void print() const { print(arr.cbegin(), arr.cend()); }
#endif
};

#if defined(SSTD_PRINTCONT_HH)
template <typename T, size_t N>
void print(sorted_array<T, N> base_array) {
  print(base_array.cbegin(), base_array.cend());
}
#endif

}  // namespace sstd