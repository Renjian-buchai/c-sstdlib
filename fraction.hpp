#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <cmath>
#include <exception>
#include <iostream>
#include <system_error>

#include "math.hpp"

namespace sstd {

class fraction {
 public:
  long long numerator;
  long long denominator;
  long long quotient;
  bool type;

  fraction(long long numr, long long denr) {
    if (denr == 0) {
      throw(std::invalid_argument("DivideBy0Error"));
    }

    denominator = denr;
    numerator = numr;
    quotient = std::floor(numr / denr);
    type = true;

    return;
  }

  fraction(long long quot, long long numr, long long denr) {
    if (denr == 0) {
      throw(std::invalid_argument("DivideBy0Error"));
      return;
    }

    numerator = numr;
    denominator = denr;
    quotient = quot;
    type = false;

    return;
  }

  void printMixed() {
    if (true == type) {
      this->toMixed();
    }

    std::cout << quotient << ", " << numerator << " / " << denominator << "\n";

    return;
  }

  void printImproper() {
    if (false == type) {
      this->toImproper();
    }

    std::cout << numerator << " / " << denominator << "\n";

    return;
  }

  void toImproper() {
    if (true == type) {
      return;
    }

    numerator = quotient * denominator + numerator;
    quotient = 0;

    return;
  }

  void toMixed() {
    if (false == type) {
      return;
    }

    quotient = floor(numerator / denominator);
    numerator -= denominator * quotient;

    return;
  }

  void simplify() {
    this->toImproper();
    long long hcf = sstd::hcf(numerator, denominator);
    numerator = numerator / hcf;
    denominator = denominator / hcf;

    return;
  }
};

fraction addFraction(fraction f1, fraction f2) {
  f1.toImproper();
  f2.toImproper();

  fraction f3(f1.numerator, f1.denominator);

  if (f1.denominator == f2.denominator) {
    f3.numerator = f1.numerator + f2.numerator;
  } else {
    f3.numerator =
        (f2.denominator * f1.numerator) + (f1.denominator * f2.numerator);
    f3.denominator = f1.denominator * f2.denominator;
  }

  f3.simplify();

  return f3;
}

fraction addFraction(fraction f1, long long toAdd) {
  f1.toImproper();

  fraction f3(f1.numerator, f1.denominator);

  f3.numerator = f1.denominator * toAdd + f1.denominator;

  f3.simplify();

  return f3;
}

fraction subFraction(fraction f1, fraction f2) {
  f1.toImproper();
  f2.toImproper();

  fraction f3(f1.numerator, f1.denominator);

  if (f1.denominator == f2.denominator) {
    f3.numerator = f1.numerator - f2.numerator;
  } else {
    f3.numerator =
        (f2.denominator * f1.numerator) - (f1.denominator * f2.numerator);
    f3.denominator = f1.denominator * f2.denominator;
  }

  f3.simplify();

  return f3;
}

fraction subFraction(fraction f1, long long toSub) {
  f1.toImproper();

  fraction f3(f1.numerator, f1.denominator);

  f3.numerator = f1.denominator * toSub - f1.denominator;

  f3.simplify();

  return f3;
}

fraction multFraction(fraction f1, )

}  // namespace sstd

#endif