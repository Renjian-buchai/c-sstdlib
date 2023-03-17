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