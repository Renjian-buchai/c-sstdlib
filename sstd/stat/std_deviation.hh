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

#if !defined(SSTD_STD_DEVIATION_HH)
#define SSTD_STD_DEVIATION_HH

#include <cmath>
#include <map>
#include <type_traits>

namespace sstd {

/// @brief Find standard deviation with a container.
/// @tparam FLOAT : Any float type.
/// @tparam Iter : Any iterator.
/// @param begin Start of container.
/// @param end End of container.
/// @return Standard deviation of container values.
template <typename FLOAT, typename Iterator,
          typename Iter = std::enable_if_t<
              std::is_arithmetic_v<typename Iterator::value_type>,
              typename Iterator::value_type> >
FLOAT standardDev(const Iter begin, const Iter end) {
  size_t freq = end - begin;
  Iter focus = begin;
  FLOAT total = 0, totalsq = 0;
  for (; focus != end; ++focus) {
    total += *focus;
    totalsq = *focus * *focus;
  }
  return std::sqrt(totalsq / freq - (total / freq) * (total / freq));
}

/// @brief Find startard deviation with values and frequencies.
/// @tparam FLOAT : Any float type.
/// @param dataSet Set of data, in the form [value, frequency].
/// @return Standard deviation of dataSet.
template <typename FLOAT>
FLOAT standardDev(const std::map<FLOAT, size_t> dataSet) {
  size_t freq = 0;
  FLOAT total = 0, totalsq = 0;
  for (const auto& [key, value] : dataSet) {
    totalsq += key * key * value;
    total += key * value;
    freq += value;
  }
  return std::sqrt(totalsq / freq - (total / freq) * (total / freq));
}

}  // namespace sstd

#endif