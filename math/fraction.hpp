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
 *
 * ============================================================================
 *
 * Header for fraction handling.
 *
 * An implementation similar to std::ratio that is closer to mathematics.
 */

#ifndef SSTD_FRACTION_HPP
#define SSTD_FRACTION_HPP

#include <cmath>
#include <exception>
#include <iostream>
#include <ratio>
#include <system_error>

#include "mathutils.hpp"

using namespace std;

namespace sstd {

/// @brief Fraction class. Supports both mixed numbers and improper fractions.
/// @note Dependencies:
/// @note mathutils.hpp -> sstd::hcf();
class fraction {
 public:
  long long numerator = 0;
  long long denominator = 1;
  long long quotient = 0;

  /// @brief Default
  fraction() {
    numerator = 0;
    denominator = 1;
    quotient = 0;
    return;
  }

  /// @brief Defines an improper fraction.
  /// @param numr Numerator; The top number in a fraction.
  /// @param denr Denominator; The bottom number in a fraction.
  /// @throws std::invalid_argument "DivideBy0Error" when denr is 0
  fraction(long long numr, long long denr) {
    if (denr == 0) {
      throw(std::invalid_argument("DivideBy0Error"));
    }

    denominator = denr;
    numerator = numr;
    quotient = 0;

    return;
  }

  /// @brief Defines a mixed number.
  /// @note Avoid when possible. Forces a conversion before calculations,
  /// decreasing efficiency.
  /// @param quot The whole number on the left of a mixed number.
  /// @param numr The top number in the fraction of the mixed number.
  /// @param denr The bottom number in the fraction of the mixed number.
  fraction(long long quot, long long numr, long long denr) {
    if (denr == 0) {
      throw(std::invalid_argument("DivideBy0Error"));
      return;
    }

    numerator = numr;
    denominator = denr;
    quotient = quot;

    return;
  }

  /// @brief Constructs a fraction from a decimal number. Can only be
  /// applied to empty or 'zero' fractions. Converts to fractional form by
  /// default.
  /// @param decimal Number to be converted to a fraction.
  /// @param precision Precision of fraction. Default is 1e+6.
  /// @param simplify Whether to simplify. Default is true.
  template <typename floatType, enIf<std::is_floating_point<floatType>>>
  void fromDec(floatType decimal, std::size_t precision = 8,
               bool simplify = true) {
    if (quotient == 0 && numerator == 0 && denominator == 1) {
      numerator = (int)(decimal * std::pow(10, precision));
      denominator = std::pow(10, precision);
      quotient = 0;
    }
    if (simplify) this->simplify();

    return;
  }

  /// @brief Prints this as a mixed number.
  void printMixed() {
    if (0 == quotient) {
      this->toMixed();
    }

    std::cout << quotient << ", " << numerator << " / " << denominator << "\n";

    return;
  }

  /// @brief Prints this as an improper fraction.
  void printFraction() {
    if (0 != quotient) {
      this->toFraction();
    }

    std::cout << numerator << " / " << denominator << "\n";

    return;
  }

  /// @brief Converts this to an improper fraction.
  void toFraction() {
    if (0 == quotient) {
      return;
    }

    numerator += quotient * denominator;
    quotient = 0;

    return;
  }

  /// @brief Converts this to a mixed number.
  /// @note Avoid when possible. Forces a conversion before calculations,
  /// decreasing efficiency.
  void toMixed() {
    if (0 != quotient) {
      return;
    }

    quotient = floor(numerator / denominator);
    numerator -= denominator * quotient;

    return;
  }

  /// @brief Converts this to decimal.
  /// @return Returns this as a decimal.
  long double toDec() {
    if (0 != quotient) {
      this->toFraction();
    }

    return (numerator / denominator);
  }

  /// @brief Simplifies this fraction.
  /// @warning Fraction is implicitly converted to improper fraction.
  /// @note Dependencies:
  /// @note mathutils.hpp -> sstd::highest();
  void simplify() {
    this->toFraction();
    long long highest = hcf(numerator, denominator);
    numerator = numerator / highest;
    denominator = denominator / highest;
    if ((numerator == 2) && (denominator == 2) && (quotient == 0)) {
      numerator = 1;
      denominator = 1;
      quotient = 0;
    }

    return;
  }

  /// @brief Adds a fraction to another fraction. Commutative.
  /// @param f1 Fraction to add.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Sum, in simplest terms.
  fraction fractionAdd(fraction f1, bool simplify = true) {
    f1.toFraction();
    this->toFraction();
    fraction f3(f1.numerator + numerator, f1.denominator);
    if (f1.denominator != denominator) {
      f3.numerator =
          (denominator * f1.numerator) + (f1.denominator * numerator);
      f3.denominator = f1.denominator * denominator;
      if (simplify) f3.simplify();
    }
    return f3;
  }

  /// @brief Adds an integer to a fraction. Commutative.
  /// @param toAdd Integer to be added.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Sum, in simplest terms.
  fraction fractionAdd(long long toAdd, bool simplify = true) {
    this->toFraction();
    fraction f3(numerator + toAdd * denominator, denominator);
    if (simplify) f3.simplify();
    return f3;
  }

  /// @brief Subtracts a fraction from another. Not commutative.
  /// @param f1 Fraction to be subtracted.
  /// @return Difference, in simplest terms.
  /// @note If you want to subtract this fraction from another, call this method
  /// from the other.
  fraction fractionSub(fraction f1, bool simplify = true) {
    this->toFraction();
    f1.toFraction();
    fraction f3(numerator - f1.numerator, denominator);
    if (denominator != f1.denominator) {
      f3.numerator =
          (f1.denominator * numerator) - (denominator * f1.numerator);
      f3.denominator = denominator * f1.denominator;
      if (simplify) f3.simplify();
    }
    return f3;
  }

  /// @brief Subtracts an integer from a fraction. Not commutative.
  /// @param toSub Integer to subtract.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Difference, in simplest terms.
  fraction fractionSub(long long toSub, bool simplify = true) {
    this->toFraction();
    fraction f3(numerator - toSub * denominator, denominator);
    if (simplify) f3.simplify();
    return f3;
  }

  /// @brief Subtracts a fraction from an integer. Not commutative.
  /// @param toSub Integer to subtract from.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Difference, in simplest terms.
  fraction subFraction(long long toSub, bool simplify = true) {
    this->toFraction();
    fraction f3(toSub * denominator - numerator, denominator);
    if (simplify) f3.simplify();
    return f3;
  }

  /// @brief Multiplies a fraction by another fraction. Commutative.
  /// @param f1 Fraction to multiply by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Product, in simplest terms.
  fraction fractionMult(fraction f1, bool simplify = true) {
    f1.toFraction();
    this->toFraction();
    fraction f3(f1.numerator * numerator, f1.denominator * denominator);
    if (simplify) f3.simplify();
    return f3;
  }

  /// @brief Multiplies a fraction by an integer. Commutative.
  /// @param toMult Integer to multiply by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Product, in simplest terms.
  fraction fractionMult(long long toMult, bool simplify = true) {
    this->toFraction();
    fraction f3(numerator * toMult, denominator);
    if (simplify) f3.simplify();
    return f3;
  }

  /// @brief Divides a fraction by another fraction. Not commutative.
  /// @param f1 Fraction to divide by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Division, in simplest terms.
  fraction fractionDiv(fraction f1, bool simplify = true) {
    this->toFraction();
    f1.toFraction();

    fraction f3(numerator * f1.denominator, f1.denominator * numerator);
    if (simplify) f3.simplify();

    return f3;
  }

  /// @brief Divides a fraction by an integer. Not commutatitve.
  /// @param f1 Fraction to be divided.
  /// @param toDiv Integer to divide by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Division, in simplest terms.
  fraction fractionDiv(long long toDiv, bool simplify = true) {
    this->toFraction();
    fraction f3(numerator, denominator * toDiv);
    if (simplify) f3.simplify();
    return f3;
  }

  /// @brief Divides an integer by a fraction. Not commutative.
  /// @param toDiv Integer to be divided.
  /// @param f1 Integer to divide by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Division, in simplest terms.
  fraction divFraction(long long toDiv, bool simplify = true) {
    this->toFraction();

    fraction f3(toDiv * denominator, numerator);
    if (simplify) f3.simplify();

    return f3;
  }
};

}  // namespace sstd

#endif /* FRACTION_HPP */