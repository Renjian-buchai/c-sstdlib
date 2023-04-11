#include <chrono>
#include <fstream>
#include <string>
#include <vector>

#include "include/subStandard.hpp"

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
  // for (int i = 0; i < 10000; ++i) sstd::oldprintVec(a);
  // t1 = std::chrono::steady_clock::now();
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1 -
  // t0)
  //               .count()
  //        << std::endl
  //        << std::endl;
  // std::cout << std::endl << std::endl;
  // t0 = std::chrono::steady_clock::now();
  // for (int i = 0; i < 10000; ++i) sstd::printVec(a, 1);
  // t1 = std::chrono::steady_clock::now();
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1 -
  // t0)
  //               .count()
  //        << std::endl
  //        << std::endl;
  // std::cout << std::endl << std::endl;
  // t0 = std::chrono::steady_clock::now();
  // for (int i = 0; i < 10000; ++i) sstd::oldprintVec(a, 1);
  // t1 = std::chrono::steady_clock::now();
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1 -
  // t0)
  //               .count()
  //        << std::endl
  //        << std::endl;

  // int arr[5] = {1, 2, 3, 4, 5};
  // sstd::printArr(arr, 5);

  // sstd::fraction f1(1, 2);
  // f1.printFraction();
  // sstd::fraction f2(1, 2);
  // f2.printFraction();
  // f1.add(f2).printFraction();

  sstd::binTree<int> tree;

  tree.appendNode(50);
  tree.appendNode(25);
  tree.appendNode(75);
  tree.appendNode(12);
  tree.appendNode(37);
  tree.appendNode(43);
  tree.appendNode(30);

  tree.preOrderTrav(tree.root);
  tree.inOrderTrav(tree.root);
  tree.postOrderTrav(tree.root);
  std::cout << "\n\n";

  tree.delNode(tree.root, 25);
  tree.preOrderTrav(tree.root);
  tree.inOrderTrav(tree.root);
  tree.postOrderTrav(tree.root);
  std::cout << "\n\n";

  std::cout << tree.getMax(tree.root);

  sstd::fraction frac;
  frac.printFraction();

  return 0;
}