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
 * This header is focused on 'pure' fractions. This means the following:
 * - No floating point inputs on the quotient,
 * - No arithmetic with floating point numbers, and
 * - Avoid mixed numbers
 *
 * This is a way to increase accuracy of integral calculations on rational
 * numbers. The aim of this header is for precise yet flexible integral
 * calculations.
 *
 * However, since not all calculations can be done on integrals, this does
 * provide the functionality to:
 * - Convert fractions to long doubles.
 *
 * List of utility included:
 * - Character output in fractional (and improper fractional) form,
 * - Character output in mixed form, and
 * - Simplification of fractions.
 *
 * Operations included:
 * - Adding      (fraction to fraction, int to fraction, fraction to int),
 * - Subtracting (fraction from fraction, int from fraction, fraction from int),
 * - Multiplying (fraction by fraction, fraction by int, int by fraction), and
 * - Dividing    (Fraction by fraction, fraction by int, int by fraction).
 * Of the above, fractions are simplified automatically by default.
 *
 * Hopefully to be implemented:
 * TODO - Convert double to fractions.
 * TODO - Optional way to disable fractions
 */

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <cmath>
#include <exception>
#include <iostream>
#include <system_error>

#include "mathutils.hpp"

namespace sstd {

/// @brief Fraction class. Supports both mixed numbers and improper fractions.
/// @note Dependencies:
/// @note mathutils.hpp -> sstd::hcf();
class fraction {
 public:
  long long numerator;
  long long denominator;
  long long quotient;

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

  /// @brief Prints this as a mixed number.
  void printMixed() {
    if (0 == quotient) {
      this->toMixed();
    }

    std::cout << quotient << ", " << numerator << " / " << denominator << "\n";

    return;
  }

  /// @brief Prints this as an improper fraction.
  void printImproper() {
    if (0 != quotient) {
      this->toImproper();
    }

    std::cout << numerator << " / " << denominator << "\n";

    return;
  }

  /// @brief Converts this to an improper fraction.
  void toImproper() {
    if (0 == quotient) {
      return;
    }

    numerator = quotient * denominator + numerator;
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
      this->toImproper();
    }

    return (numerator / denominator);
  }

  /// @brief Simplifies this fraction.
  /// @warning Fraction is implicitly converted to improper fraction.
  /// @note Dependencies:
  /// @note mathutils.hpp -> sstd::hcf();
  void simplify() {
    this->toImproper();
    long long hcf = sstd::hcf(numerator, denominator);
    numerator = numerator / hcf;
    denominator = denominator / hcf;

    return;
  }
};

/// @brief Adds a fraction to another fraction. Commutative.
/// @param f1 Fraction to be added to.
/// @param f2 Fraction to add.
/// @return Sum, in simplest terms.
fraction fractionAdd(fraction f1, fraction f2) {
  f1.toImproper();
  f2.toImproper();

  fraction f3(f1.numerator + f2.numerator, f1.denominator);

  if (f1.denominator != f2.denominator) {
    f3.numerator =
        (f2.denominator * f1.numerator) + (f1.denominator * f2.numerator);
    f3.denominator = f1.denominator * f2.denominator;
    f3.simplify();
  }

  return f3;
}

/// @brief Adds an integer to a fraction. Commutative.
/// @param f1 Fraction to be added to.
/// @param toAdd Integer to be added.
/// @return Sum, in simplest terms.
fraction fractionAdd(fraction f1, long long toAdd) {
  f1.toImproper();

  fraction f3(f1.numerator + toAdd * f1.denominator, f1.denominator);
  f3.simplify();

  return f3;
}

/// @brief Adds an integer to a fraction. Commutative.
/// @param toAdd Integer to be added to.
/// @param f1 Fraction to be added.
/// @return Sum, in simplest terms.
fraction fractionAdd(long long toAdd, fraction f1) {
  f1.toImproper();

  fraction f3(f1.numerator + toAdd * f1.denominator, f1.denominator);
  f3.simplify();

  return f3;
}

/// @brief Subtracts a fraction from another. Not commutative.
/// @param f1 Fraction to subtract from.
/// @param f2 Fraction to be subtracted.
/// @return Difference, in simplest terms.
fraction fractionSub(fraction f1, fraction f2) {
  f1.toImproper();
  f2.toImproper();

  fraction f3(f1.numerator - f2.numerator, f1.denominator);

  if (f1.denominator != f2.denominator) {
    f3.numerator =
        (f2.denominator * f1.numerator) - (f1.denominator * f2.numerator);
    f3.denominator = f1.denominator * f2.denominator;
    f3.simplify();
  }

  return f3;
}

/// @brief Subtracts an integer from a fraction. Not commutative.
/// @param f1 Fraction to subtract from.
/// @param toSub Integer to subtract.
/// @return Difference, in simplest terms.
fraction fractionSub(fraction f1, long long toSub) {
  f1.toImproper();

  fraction f3(f1.numerator - toSub * f1.denominator, f1.denominator);
  f3.simplify();

  return f3;
}

/// @brief Subtracts a fraction from an integer. Not commutative.
/// @param toSub Integer to subtract from.
/// @param f1 Fraction to subtract.
/// @return Difference, in simplest terms.
fraction fractionSub(long long toSub, fraction f1) {
  f1.toImproper();

  fraction f3(toSub * f1.denominator - f1.numerator, f1.denominator);
  f3.simplify();

  return f3;
}

/// @brief Multiplies a fraction by another fraction. Commutative.
/// @param f1 Fraction to be multiplied.
/// @param f2 Fraction to multiply by.
/// @return Product, in simplest terms.
fraction fractionMult(fraction f1, fraction f2) {
  f1.toImproper();
  f2.toImproper();

  fraction f3(f1.numerator * f2.numerator, f1.denominator * f2.denominator);
  f3.simplify();

  return f3;
}

/// @brief Multiplies a fraction by an integer. Commutative.
/// @param f1 Fraction to be multiplied.
/// @param toMult Integer to multiply by.
/// @return Product, in simplest terms.
fraction fractionMult(fraction f1, long long toMult) {
  f1.toImproper();

  fraction f3(f1.numerator * toMult, f1.denominator);
  f3.simplify();

  return f3;
}

/// @brief Multiplies an integer by a fraction. Commutative.
/// @param toMult Integer to be multiplied.
/// @param f1 Fraction to multiply by.
/// @return Product, in simplest terms.
fraction fractionMult(long long toMult, fraction f1) {
  f1.toImproper();

  fraction f3(f1.numerator * toMult, f1.denominator);
  f3.simplify();

  return f3;
}

/// @brief Divides a fraction by another fraction. Not commutative.
/// @param f1 Fraction to be divided.
/// @param f2 Fraction to divide by.
/// @return Division, in simplest terms.
fraction fractionDiv(fraction f1, fraction f2) {
  f1.toImproper();
  f2.toImproper();

  fraction f3(f1.numerator * f2.denominator, f2.denominator * f1.numerator);
  f3.simplify();

  return f3;
}

/// @brief Divides a fraction by an integer. Not commutatitve.
/// @param f1 Fraction to be divided.
/// @param toDiv Integer to divide by.
/// @return Division, in simplest terms.
fraction fractionDiv(fraction f1, long long toDiv) {
  f1.toImproper();

  fraction f3(f1.numerator, f1.denominator * toDiv);
  f3.simplify();

  return f3;
}

/// @brief Divides an integer by a fraction. Not commutative.
/// @param toDiv Integer to be divided.
/// @param f1 Integer to divide by.
/// @return Division, in simplest terms.
fraction fractionDiv(long long toDiv, fraction f1) {
  f1.toImproper();

  fraction f3(toDiv * f1.denominator, f1.numerator);
  f3.simplify();

  return f3;
}

}  // namespace sstd

#endif /* FRACTION_HPP */