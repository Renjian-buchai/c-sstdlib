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
 * An implementation similar to std::ratio that is closer to mathematics than
 * std::ratio. Note: Fractions are not mutated when performing operations.
 *
 */

#ifndef SSTD_FRACTION_HPP
#define SSTD_FRACTION_HPP

#include <boost/integer/common_factor.hpp>
#include <cmath>
#include <exception>
#include <iostream>
#include <system_error>

template <typename Condition, typename T = void>
using enIf = typename std::enable_if<Condition::value, T>::type;

using namespace std;

namespace sstd {

/// @brief Fraction class. Supports both mixed numbers and improper fractions.
/// @note Dependencies:
/// @note mathutils.hpp -> sstd::hcf();
class fraction {
 private:
  long long numerator = 0;
  long long denominator = 1;
  long long quotient = 0;

 public:
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
    if (denr == 0) throw(std::invalid_argument("DivideBy0Error"));
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
    if (denr == 0) throw(std::invalid_argument("DivideBy0Error"));
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
    if (quotient == numerator == 0 && denominator == 1) {
      numerator = (int)(decimal * std::pow(10, precision));
      denominator = std::pow(10, precision);
      quotient = 0;
    }
    if (simplify) this->simplify();
    return;
  }

  /// @brief Prints this as a mixed number.
  void printMixed() {
    if (0 == quotient) this->toMixed();
    if (denominator == 1)
      std::cout << quotient << "\n";
    else
      std::cout << quotient << ", " << numerator << " / " << denominator
                << "\n";
    return;
  }

  /// @brief Prints this as an improper fraction.
  void printFraction() {
    if (0 != quotient) this->toFraction();
    if (denominator == 1)
      std::cout << numerator << "\n";
    else
      std::cout << numerator << " / " << denominator << "\n";
    return;
  }

  /// @brief Converts this to an improper fraction.
  void toFraction() {
    if (0 == quotient) return;
    numerator += quotient * denominator;
    quotient = 0;
    return;
  }

  /// @brief Converts this to a mixed number.
  /// @note Avoid when possible. Forces a conversion before calculations,
  /// decreasing efficiency.
  void toMixed() {
    if (0 != quotient) return;
    quotient = floor(numerator / denominator);
    numerator -= denominator * quotient;
    return;
  }

  /// @brief Converts this to decimal.
  /// @return Returns this as a decimal.
  long double toDec() {
    if (0 != quotient) this->toFraction();
    return (numerator / denominator);
  }

  /// @brief Simplifies this fraction.
  /// @warning Fraction is implicitly converted to improper fraction.
  /// @note Dependencies:
  /// @note mathutils.hpp -> sstd::highest();
  void simplify() {
    this->toFraction();
    long long highest = boost::integer::gcd(numerator, denominator);
    numerator = numerator / highest;
    denominator = denominator / highest;
    return;
  }

  /// @brief Adds a fraction to another fraction. Commutative.
  /// @param _fraction Fraction to add.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Sum, in simplest terms.
  fraction add(fraction _fraction, bool simplify = true) {
    _fraction.toFraction();
    this->toFraction();
    fraction _res_frac(_fraction.numerator + numerator, _fraction.denominator);
    if (_fraction.denominator != denominator) {
      _res_frac.numerator = (denominator * _fraction.numerator) +
                            (_fraction.denominator * numerator);
      _res_frac.denominator = _fraction.denominator * denominator;
    }
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Adds an integer to a fraction. Commutative.
  /// @param toAdd Integer to be added.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Sum, in simplest terms.
  fraction add(long long toAdd, bool simplify = true) {
    this->toFraction();
    fraction _res_frac(numerator + toAdd * denominator, denominator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Subtracts a fraction from another. Not commutative.
  /// @param _fraction Fraction to be subtracted.
  /// @return Difference, in simplest terms.
  /// @note If you want to subtract this fraction from another, call this method
  /// from the other.
  fraction sub(fraction _fraction, bool simplify = true) {
    this->toFraction();
    _fraction.toFraction();
    fraction _res_frac(numerator - _fraction.numerator, denominator);
    if (denominator != _fraction.denominator) {
      _res_frac.numerator = (_fraction.denominator * numerator) -
                            (denominator * _fraction.numerator);
      _res_frac.denominator = denominator * _fraction.denominator;
    }
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Subtracts an integer from a fraction. Not commutative.
  /// @param toSub Integer to subtract.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Difference, in simplest terms.
  fraction sub(long long toSub, bool simplify = true) {
    this->toFraction();
    fraction _res_frac(numerator - toSub * denominator, denominator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Subtracts a fraction from an integer. Not commutative.
  /// @param toSub Integer to subtract from.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Difference, in simplest terms.
  fraction subFr(long long toSub, bool simplify = true) {
    this->toFraction();
    fraction _res_frac(toSub * denominator - numerator, denominator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Multiplies a fraction by another fraction. Commutative.
  /// @param _fraction Fraction to multiply by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Product, in simplest terms.
  fraction mult(fraction _fraction, bool simplify = true) {
    _fraction.toFraction();
    this->toFraction();
    fraction _res_frac(_fraction.numerator * numerator,
                       _fraction.denominator * denominator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Multiplies a fraction by an integer. Commutative.
  /// @param toMult Integer to multiply by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Product, in simplest terms.
  fraction mult(long long toMult, bool simplify = true) {
    this->toFraction();
    fraction _res_frac(numerator * toMult, denominator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Divides a fraction by another fraction. Not commutative.
  /// @param _fraction Fraction to divide by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Division, in simplest terms.
  fraction div(fraction _fraction, bool simplify = true) {
    this->toFraction();
    _fraction.toFraction();
    fraction _res_frac(numerator * _fraction.denominator,
                       _fraction.denominator * numerator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Divides a fraction by an integer. Not commutatitve.
  /// @param toDiv Integer to divide by.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Division, in simplest terms.
  fraction div(long long toDiv, bool simplify = true) {
    this->toFraction();
    fraction _res_frac(numerator, denominator * toDiv);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  /// @brief Divides an integer by a fraction. Not commutative.
  /// @param toDiv Integer to be divided.
  /// @param simplify Whether to simplify. Default = true.
  /// @return Division, in simplest terms.
  fraction divBy(long long toDiv, bool simplify = true) {
    this->toFraction();
    fraction _res_frac(toDiv * denominator, numerator);
    if (simplify) _res_frac.simplify();
    return _res_frac;
  }

  long long getNum() { return numerator; }
  long long getDen() { return denominator; }
  long long getQuo() { return quotient; }
};

/// @brief Adds a fraction to an integer. Commutative.
/// @param toAdd Integer to be added to.
/// @param _base_frac Fraction to be added.
/// @param simplify Whether to simplify. Default = true.
/// @return Sum, in simplest terms.
fraction add(fraction _base_frac, long long toAdd, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(_base_frac.getNum() + toAdd * _base_frac.getDen(),
                     _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Adds an integer to a fraction. Commutative.
/// @param _base_frac Fraction to be added to.
/// @param toAdd Integer to be added.
/// @param simplify Whether to simplify. Default = true.
/// @return Sum, in simplest terms.
fraction add(long long toAdd, fraction _base_frac, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(_base_frac.getNum() + toAdd * _base_frac.getDen(),
                     _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Adds a fraction to another fraction. Commutative.
/// @param _base_frac Fraction to be added to.
/// @param _fraction Fraction to be added.
/// @param simplify Whether to simplify. Default = true.
/// @return Sum, in simplest terms.
fraction add(fraction _base_frac, fraction _fraction, bool simplify = true) {
  _base_frac.toFraction();
  _fraction.toFraction();
  long long numerator = _base_frac.getNum() + _fraction.getNum();
  long long denominator = _base_frac.getDen();
  if (_base_frac.getDen() != _fraction.getDen()) {
    numerator = (_fraction.getDen() * _base_frac.getNum()) +
                (_base_frac.getDen() * _fraction.getNum());
    denominator = _base_frac.getDen() * _fraction.getDen();
  }
  fraction _res_frac(numerator, denominator);
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Subtracts a fraction from another. Not commutative.
/// @param _base_frac Fraction to be subtracted from.
/// @param _fraction Fraction to be subtracted.
/// @return Difference, in simplest terms.
/// @note If you want to subtract this fraction from another, call this method
/// from the other.
fraction sub(fraction _base_frac, fraction _fraction, bool simplify = true) {
  _base_frac.toFraction();
  _fraction.toFraction();
  long long numerator = _base_frac.getNum() - _fraction.getNum();
  long long denominator = _base_frac.getDen();
  if (_base_frac.getDen() != _fraction.getDen()) {
    numerator = (_fraction.getDen() * _base_frac.getNum()) -
                (_base_frac.getDen() * _fraction.getNum());
    denominator = _base_frac.getDen() * _fraction.getDen();
  }
  fraction _res_frac(numerator, denominator);
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Subtracts an integer from a fraction. Not commutative.
/// @param _base_frac Fraction to be subtracted from.
/// @param toSub Integer to be subtracted.
/// @param simplify Whether to simplify. Default = true.
/// @return Difference, in simplest terms.
fraction sub(fraction _base_frac, long long toSub, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(_base_frac.getNum() - toSub * _base_frac.getDen(),
                     _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Multiplies a fraction by another fraction. Commutative.
/// @param _base_frac Fraction to be multiplied.
/// @param _fraction Fraction to multiply by.
/// @param simplify Whether to simplify. Default = true.
/// @return Product, in simplest terms.
fraction mult(fraction _base_frac, fraction _fraction, bool simplify = true) {
  _base_frac.toFraction();
  _fraction.toFraction();
  fraction _res_frac(_fraction.getNum() * _base_frac.getNum(),
                     _fraction.getDen() * _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Multiplies a fraction by an integer. Commutative.
/// @param _base_frac Fraction to be multiplied.
/// @param toMult Integer to multiply by.
/// @param simplify Whether to simplify. Default = true.
/// @return Product, in simplest terms.
fraction mult(fraction _base_frac, long long toMult, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(_base_frac.getNum() * toMult, _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Multiplies a fraction by an integer. Commutative.
/// @param toMult Integer to multiply by.
/// @param _base_frac Fraction to be multiplied.
/// @param simplify Whether to simplify. Default = true.
/// @return Product, in simplest terms.
fraction mult(long long toMult, fraction _base_frac, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(_base_frac.getNum() * toMult, _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Divides a fraction by another fraction. Not commutative.
/// @param _base_frac Fraction to be divided.
/// @param _fraction Fraction to divide by.
/// @param simplify Whether to simplify. Default = true.
/// @return Division, in simplest terms.
fraction div(fraction _base_frac, fraction _fraction, bool simplify = true) {
  _base_frac.toFraction();
  _fraction.toFraction();
  fraction _res_frac(_base_frac.getNum() * _fraction.getDen(),
                     _fraction.getNum() * _base_frac.getDen());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Divides a fraction by an integer. Not commutatitve.
/// @param _base_frac Fraction to be divided.
/// @param toDiv Integer to divide by.
/// @param simplify Whether to simplify. Default = true.
/// @return Division, in simplest terms.
fraction div(fraction _base_frac, long long toDiv, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(_base_frac.getNum(), _base_frac.getDen() * toDiv);
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

/// @brief Divides an integer by a fraction. Not commutative.
/// @param toDiv Integer to be divided.
/// @param _base_frac Integer to divide by.
/// @param simplify Whether to simplify. Default = true.
/// @return Division, in simplest terms.
fraction div(long long toDiv, fraction _base_frac, bool simplify = true) {
  _base_frac.toFraction();
  fraction _res_frac(toDiv * _base_frac.getDen(), _base_frac.getNum());
  if (simplify) _res_frac.simplify();
  return _res_frac;
}

}  // namespace sstd

#endif /* FRACTION_HPP */