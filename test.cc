#include <chrono>
#include <fstream>
#include <vector>

#include "subStandard.hpp"

int main() {
  // sstd::log::config(0, "suffering.txt");
  // sstd::log::note("I don't know what happened here");
  // std::ofstream output;
  // output.open("./timing.txt");
  // std::vector<int> a = {1, 2, 3, 4, 5};
  // std::cout << std::endl << std::endl;
  // std::chrono::steady_clock::time_point t0 =
  // std::chrono::steady_clock::now(); for (int i = 0; i < 10000; ++i)
  // sstd::printVec(a); std::chrono::steady_clock::time_point t1 =
  // std::chrono::steady_clock::now(); output <<
  // std::chrono::duration_cast<std::chrono::duration<double>>(t1 - t0)
  //               .count()
  //        << std::endl
  //        << std::endl;
  // std::cout << std::endl << std::endl;
  // t0 = std::chrono::steady_clock::now();
  // for (int i = 0; i < 10000; ++i) sstd::oldPrintVec(a);
  // t1 = std::chrono::steady_clock::now();
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1 -
  // t0)
  //               .count()
  //        << std::endl
  //        << std::endl;

  int arr[5] = {1, 2, 3, 4, 5};
  sstd::printArr(arr, 5);

  return 0;
}