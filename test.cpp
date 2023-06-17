#include <algorithm>
#include <chrono>
#include <fstream>
#include <functional>
#include <iterator>
#include <list>
#include <map>
#include <sstd\.io.hh>
#include <sstd\subStandard.hh>
#include <sstd\util\tostrvec.hh>
#include <string>
#include <vector>

template <typename uInt>
uInt iterative_gcd(const uInt x, const uInt y) {
  uInt ycpy = y;
  {
    uInt xcpy = x, temp = xcpy % ycpy;
    while (temp != 0) {
      temp = xcpy % ycpy;
      xcpy = ycpy;
      ycpy = temp;
    }
  }
  return ycpy;
}

int main(int argc, char* argv[]) {
  std::chrono::steady_clock::time_point t0 = std::chrono::steady_clock::now();
  sstd::fraction<>::configureFraction();

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
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1
  // - t0)
  //               .count()
  //        << std::endl
  //        << std::endl;
  // std::cout << std::endl << std::endl;
  // t0 = std::chrono::steady_clock::now();
  // for (int i = 0; i < 10000; ++i) sstd::printVec(a, 1);
  // t1 = std::chrono::steady_clock::now();
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1
  // - t0)
  //               .count()
  //        << std::endl
  //        << std::endl;
  // std::cout << std::endl << std::endl;
  // t0 = std::chrono::steady_clock::now();
  // for (int i = 0; i < 10000; ++i) sstd::oldprintVec(a, 1);
  // t1 = std::chrono::steady_clock::now();
  // output << std::chrono::duration_cast<std::chrono::duration<double>>(t1
  // - t0)
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

  // sstd::binTree<int> tree;
  // tree.appendNode(50);
  // tree.appendNode(25);
  // tree.appendNode(75);
  // tree.appendNode(12);
  // tree.appendNode(37);
  // tree.appendNode(43);
  // tree.appendNode(30);
  // // tree.preOrderTrav(tree.root);
  // tree.inOrderTrav(tree.root);
  // tree.postOrderTrav(tree.root);
  // std::cout << "\n\n";
  // tree.delNode(tree.root, 25);
  // // tree.preOrderTrav(tree.root);
  // tree.inOrderTrav(tree.root);
  // tree.postOrderTrav(tree.root);
  // std::cout << "\n\n";
  // std::cout << tree.getMax(tree.root)
  // sstd::fraction frac;
  // frac.printFraction();

  // std::array<int, 4> a{1, 2, 3, 4};
  // sstd::matrix2<int, 2, 2> mat(a.begin(), a.end());
  // mat.print();
  // sstd::print(mat);

  // sstd::binTree<int> bin(std::array<int, 5>{1, 2, 3, 4, 5});
  // bin.preOrd(bin.root());

  // sstd::fraction<int> a(1, 1, 2);
  // a.print();
  // a.printMixed();
  // std::cout << "\n";
  // sstd::fraction<int> b(5, 2);
  // b.print();
  // b.printMixed();
  // std::cout << "\n";
  // sstd::fraction<int> c(4, 2);
  // c.print();
  // c.printMixed();
  // c.simplify();
  // c.print();
  // c.printMixed();
  // std::cout << "\n";
  // sstd::fraction<int> d(1, 0, 2);
  // d.printMixed();
  // std::cout << "\n";
  // sstd::fraction<int> e(1, 2);
  // e.add(sstd::fraction<int>(1, 2), true).print();
  // std::cout << "\n";
  // (e--).print();

  // std::array<double, 2> a = sstd::rqd(1.0, 2.0, 1.0);
  // std::array<std::complex<double>, 2> b = sstd::qd(1.0, 1.0, 1.0);
  // std::cout << a[0] << a[1];
  // std::cout << b[0] << b[1];

  // std::array<std::string, 5> a{"ax", "2a", "3u", "4e", "5o"};
  // std::vector<double> b{1, 2, 3, 4};
  // std::cout << typeid(b[4]).name();
  // sstd::print(a.begin(), a.end());
  // sstd::print(b.begin(), b.end());

  // std::cout << sstd::median<long double>(b.begin(), b.end(

  // ));

  // std::vector<int> vec{1, 2, 3, 4, 5};
  // std::array<int, 5> arr = sstd::arrify<int, 5>(vec.begin(), vec.end());
  // sstd::print(arr.begin(), arr.end());
  // sstd::vector2<int> vec2(1, 2);
  // std::cout << vec2.first() << vec2.second()++ << vec2.second();

  // sstd::fraction<long> one = sstd::fraction<long>::frac<long, long>(1);
  // sstd::fraction<long> two{2, 1};
  // one += two;
  // one.print();
  // std::cout << "\n";
  // sstd::fraction<>::frac<long double>(_PI_).print();
  // std::cout << one.tostr();

  // sstd::vector<int, 1> vec;
  // sstd::print(vec.cbegin(), vec.cend());

  //   int arr[3] = {0};
  //   std::array<int, 3> arr2 = {1, 2, 3};
  //
  //   for (int i = 0; i < 5'000'000; ++i) {
  //     if (1 == 2) {
  //       continue;
  //     }
  //     std::copy(arr2.begin(), arr2.end(), std::begin(arr));
  //   }
  //   auto ifstatement =
  //       std::chrono::duration_cast<std::chrono::duration<double>>(t11 - t00);
  //
  //   for (int i = 0; i < 5'000'000; ++i) {
  //     arr[0] = arr2[0];
  //     arr[1] = arr[1];
  //     arr[2] = arr[2];
  //   }
  //   auto assign =
  //       std::chrono::duration_cast<std::chrono::duration<double>>(t11 - t00);
  //   std::cout << "Ifstament: " << ifstatement.count()
  //             << "\nAssign: " << assign.count();

  //   std::cout << iterative_gcd(600, 100);
  //
  //   std::array<long, 4> arr{1, 2, 3, 4};
  //   sstd::matrix2<long, 2, 2> matx(arr.begin(), arr.end());
  //   sstd::matrix2<long, 2, 2> matx2(arr.begin(), arr.end());
  //   (matx * matx2).print();

  // std::vector<int> a = {0, 2, 4, 1, 3, 5};
  // std::array<int, 5> neu;
  // neu = sstd::contify<std::array<int, 5>, std::vector<int>>(a, neu);
  // sstd::print(neu.begin(), neu.end());

  // std::cout << sstd::median<std::vector<int>::iterator, double>(a.begin(),
  //                                                               a.end());
  // std::map<int, size_t> b{{0, 1}, {1, 1}, {2, 1}, {3, 1}, {4, 1}, {5, 1}};
  // std::cout << sstd::median(b);

  // std::chrono::steady_clock::time_point t00;
  // std::chrono::steady_clock::time_point t11;
  // long long aaaaaaargh = 0;
  // t00 = std::chrono::steady_clock::now();
  // for (size_t i = 0; i < 10'000'000'000; ++i) {
  //   if (0 == 0) {
  //     ++aaaaaaargh;
  //   }
  // }
  // t11 = std::chrono::steady_clock::now();
  // std::cout << std::setprecision(100) << "0 == 0: "
  //           << std::chrono::duration_cast<std::chrono::duration<double>>(t11
  //           -
  //                                                                        t00)
  //                  .count()
  //           << "\n";
  // t00 = std::chrono::steady_clock::now();
  // for (size_t i = 0; i < 10'000'000'000; ++i) {
  //   if (!0) {
  //     ++aaaaaaargh;
  //   }
  // }
  // t11 = std::chrono::steady_clock::now();
  // std::cout << "!0: "
  //           << std::chrono::duration_cast<std::chrono::duration<double>>(t11
  //           -
  //                                                                        t00)
  //                  .count()
  //           << "\n";

  // char arr[3][4] = {"abc", "def", "ghi"};

  // // Initialize char** manually
  // char* ptr[3];
  // ptr[0] = arr[0];
  // ptr[1] = arr[1];
  // ptr[2] = arr[2];

  // std::vector<std::string> vec = sstd::toStrVec(ptr, 3);
  // sstd::print(vec.begin(), vec.end());

  // sstd::rquadratic(1, 2, 1);

  std::pair<std::chrono::duration<long double, std::milli>, int> x =
      sstd::funcTime(&iterative_gcd<int>, 10, 20, 10);

  auto y = &iterative_gcd<int>;

  std::cout << x.first.count() << "ms, " << x.second << "\n";

  std::cout << "\nDone! Terminated in: "
            << std::chrono::duration_cast<std::chrono::duration<double>>(
                   std::chrono::steady_clock::now() - t0)
                   .count()
            << "s";
  return 0;
}