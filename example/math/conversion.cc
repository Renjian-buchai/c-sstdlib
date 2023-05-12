#include <complex>   // std::complex
#include <iomanip>   // std::setprecision
#include <iostream>  // std::cout
#include <sstd/math/conversion.hpp>

int main() {
  std::cout << "  pi radians in degrees: " << sstd::rTD(_PI_) << "\n";
  std::cout << " pi radians in gradians: " << sstd::rTG(_PI_) << "\n";
  std::cout << "  45 degrees in radians: " << sstd::dTR(45.0) << "\n";
  std::cout << "180 degrees to gradians: " << sstd::dTG(180.0) << "\n";
  std::cout << "200 gradians to degrees: " << sstd::gTD(200.0) << "\n";
  std::cout << "400 gradians to radians: " << sstd::gTR(300.0) << "\n";
  std::cout << "                 3 + 2i: " << sstd::complex::polRep(3, 2).first
            << "(cos(" << sstd::complex::polRep(3.0, 2.0).second << ") + isin("
            << sstd::complex::polRep(3.0, 2.0).second << "))\n";
  std::cout << "        5(cos2 + isin2): "
            << sstd::complex::compRep(5.0, 2.0).first << " + "
            << sstd::complex::compRep(5.0, 2.0).second << "i\n";

  return 0;
}
