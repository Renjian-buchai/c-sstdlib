#ifndef MATHUTILS_HPP
#define MATHUTILS_HPP

#include "fraction.hpp"

namespace sstd {

int hcf(long long x, long long y) {
  if (x == 0) return y;
  if (y == 0) return x;
  if (x == y) return x;
  if (x > y) return hcf(x - y, y);
  return hcf(x, y - x);
}

}  // namespace sstd

#endif