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

#if !defined(SSTD_MATHUTILS_HH)
#define SSTD_MATHUTILS_HH

#include <array>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <random>
#include <type_traits>
#include <utility>

using namespace std;

namespace sstd {
template <typename uns_int>
uns_int hcf(const uns_int x, const uns_int y) {
  // Fucking cancerous
  // Guard clauses
  if (x == 0) {
    return y;
  } else if (y == 0) {
    return x;
  }

  {
    uns_int xcpy = x, ycpy = y;
    while (xcpy != ycpy) {
      if (xcpy > ycpy) {
        xcpy -= ycpy;
      } else {
        ycpy -= xcpy;
      }
    }

    return xcpy;
  }
}

template <typename uns_int>
uns_int lcm(const uns_int x, const uns_int y) {
  // Using principle lcm = xy/hcf
  uns_int hcf;
  if (x == 0) {
    hcf = y;
    goto lcm00;
  } else if (y == 0) {
    hcf = x;
    goto lcm00;
  }

  {
    uns_int xcpy = x, ycpy = y;
    while (xcpy != ycpy) {
      if (xcpy > ycpy) {
        xcpy -= ycpy;
      } else {
        ycpy -= xcpy;
      }
    }
    hcf = xcpy;
  }
// Technically can use do-while, break, but goto would be faster since no
// conditions need to be evaluated.
// I hate this so much
lcm00:
  return (x * y) / hcf;
}

double qisqrt(double x) {
  // The double is important. Don't replace with template
  double y = x;
  double x2 = y * 0.5;
  std::int64_t i = *(std::int64_t *)&y;
  i = 0x5fe6eb50c7b537a9 - (i >> 1);
  y = *(double *)&i;
  y = y * (1.5 - (x2 * y * y));
  return y;
}

double q_isqrt(double x) {
  double y = x;
  double x2 = y * 0.5;
  std::int64_t i = *(std::int64_t *)&y;
  i = 0x5fe6eb50c7b537a9 - (i >> 1);
  y = *(double *)&i;
  y = y * (1.5 - (x2 * y * y));
  y = y * (1.5 - (x2 * y * y));
  return y;
}

double qisqrt(double x, size_t precision) {
  double y = x;
  double x2 = y * 0.5;
  std::int64_t i = *(std::int64_t *)&y;
  i = 0x5fe6eb50c7b537a9 - (i >> 1);
  y = *(double *)&i;
  for (size_t eax = 0; eax < precision; ++eax) y = y * (1.5 - (x2 * y * y));
  return y;
}

template <typename Int>
std::pair<Int, Int> divmod(Int x, Int y) {
  return std::pair<Int, Int> { std::floor(x / y), x % y }
}

}  // namespace sstd

#endif /* MATHUTILS_HH */
