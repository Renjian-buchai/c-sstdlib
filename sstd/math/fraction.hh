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
 */

/*
 * Header for fraction handling.
 *
 * An implementation similar to std::ratio that is closer to mathematics than
 * std::ratio. Note: Fractions are not mutated when running functions. Frections
 * ARE modified when running methods.
 *
 * NOTE Made decision to compose instead of extract functions like
 * fraction::simplify because something like that is faster.
 * Justification: This is a library, so efficiency is more important than
 * maintainability.
 *
 * Guideline:
 * - When possible, multiply by fractions or integers instead of floats.
 */

#if !defined(SSTD_FRACTION_HH)
#define SSTD_FRACTION_HH

#include <algorithm>
#include <cmath>
#include <exception>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <sstd/except/div0.hh>  // sstd::div0
#include <type_traits>

namespace sstd {

// To determine if fractions are simplified by default
bool sstd_fraction_simplify = true;

// To determine precision of conversions from decimal
size_t sstd_fraction_precision = 5;

template <class T = long>
class fraction {
 protected:
  T numr = 0;
  T denr = 1;

 public:
  /// @brief Configures sstd::fraction class
  /// @param simplify Whether to simplify fraction
  /// @param _precision Precision of fraction after conversion of decimal to
  /// float
  static constexpr void configureFraction(const bool simplify = true,
                                          const size_t _precision = 5) {
    sstd_fraction_simplify = simplify;
    sstd_fraction_precision = _precision;
  }

  fraction() = default;
  fraction(T numerator, T denominator) {
    (void)(denominator == 0 ? throw div0() : (void)(numr = numerator),
           (void)(denr = denominator));
  }
  fraction(std::initializer_list<T> _fraction) {
    (void)(_fraction.size() != 2 ? throw invCall("Number of arguments is wrong")
                                 : (void)0);
    auto it = _fraction.begin();
    numr = *it;
    denr = *(++it);
  }

  ~fraction(){};

#if defined(SSTD_PRINTCONT_HH)
  void print() const {
    (void)(denr == 0
               ? throw div0()
               : (void)(denr == 1 ? std::cout << numr,
                        (void)0   : std::cout << numr << "/" << denr, (void)0));
  }
#endif

  template <typename F>
  inline F dec() const {
    // Throwing is more predictable than returning NaN
    (void)(denr == 0 ? throw div0() : (void)0);

    return numr / denr;
  }
  fraction<T> simplify() {
    (void)(denr == 0 ? throw div0() : (void)0);

    T highest;
    // Short circuit because num == 0
    if (numr == 0) {
      highest = denr;
    } else {
      // HCF algorithm (iterative)
      T ncpy = numr, dcpy = denr;
      while (ncpy != dcpy) {
        (void)(ncpy > dcpy ? (void)(ncpy -= dcpy) : (void)(dcpy -= ncpy));
      }
      highest = ncpy;
    }
    numr /= highest;
    denr /= highest;
    return *this;
  }

  inline T& numer() { return numr; }
  inline T& denom() { return denr; }
  inline T cnumer() const { return numr; }
  inline T cdenom() const { return denr; }

  // Simplify alr returns *this
  fraction<T> operator++() {
    numr += denr;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  fraction<T> operator--() {
    numr -= denr;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  fraction<T> operator++(int) {
    fraction<T> copy = *this;
    numr += denr;
    return sstd_fraction_simplify ? copy.simplify() : copy;
  }
  fraction<T> operator--(int) {
    fraction<T> copy = *this;
    numr -= denr;
    return sstd_fraction_simplify ? copy.simplify() : copy;
  }

  fraction<T> operator+(const fraction<T> _fraction) const {
    // Readability? Who's that lmao
    return sstd_fraction_simplify ? fraction<T>{numr * _fraction.cdenom() +
                                                    _fraction.cnumer() * denr,
                                                denr * _fraction.cdenom()}
                                        .simplify()
                                  : fraction<T>{numr * _fraction.cdenom() +
                                                    _fraction.cnumer() * denr,
                                                denr * _fraction.cdenom()};
  }
  fraction<T> operator-(const fraction<T> _fraction) const {
    return sstd_fraction_simplify ? fraction<T>{numr * _fraction.cdenom() -
                                                    _fraction.cnumer() * denr,
                                                denr * _fraction.cdenom()}
                                        .simplify()
                                  : fraction<T>{numr * _fraction.cdenom() -
                                                    _fraction.cnumer() * denr,
                                                denr * _fraction.cdenom()};
  }
  fraction<T> operator*(const fraction<T> _fraction) const {
    return sstd_fraction_simplify ? fraction<T>{numr * _fraction.cnumer(),
                                                denr * _fraction.cdenom()}
                                        .simplify()
                                  : fraction<T>{numr * _fraction.cnumer(),
                                                denr * _fraction.cdenom()};
  }
  fraction<T> operator/(const fraction<T> _fraction) const {
    return sstd_fraction_simplify ? fraction<T>{numr * _fraction.cdenom(),
                                                denr * _fraction.cnumer()}
                                        .simplify()
                                  : fraction<T>{numr * _fraction.cdenom(),
                                                denr * _fraction.cnumer()};
  }

  fraction<T> operator+=(const fraction<T> _fraction) {
    (numr *= _fraction.cdenom()) += _fraction.cnumer() * denr;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  fraction<T> operator-=(const fraction<T> _fraction) {
    (numr *= _fraction.cdenom()) -= _fraction.cnumer() * denr;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  fraction<T> operator*=(const fraction<T> _fraction) {
    numr *= _fraction.cnumer();
    denr *= _fraction.cdenom();
    return sstd_fraction_simplify ? simplify() : *this;
  }
  fraction<T> operator/=(const fraction<T> _fraction) {
    numr *= _fraction.cdenom();
    denr += _fraction.cnumer();
    return sstd_fraction_simplify ? simplify() : *this;
  }
  template <class A>
  fraction<T> operator+(const A _number) const {
    return sstd_fraction_simplify
               ? fraction<T>{numr + _number * denr, denr}.simplify()
               : fraction<T>{numr + _number * denr, denr};
  };
  template <class A>
  fraction<T> operator-(const A _number) const {
    return sstd_fraction_simplify
               ? fraction<T>{numr - _number * denr, denr}.simplify()
               : fraction<T>{numr - _number * denr, denr};
  }
  template <class A>
  fraction<T> operator*(const A _number) const {
    return sstd_fraction_simplify ? fraction<T>{numr * _number, denr}.simplify()
                                  : fraction<T>{numr * _number, denr};
  }
  template <class A>
  fraction<T> operator/(const A _number) const {
    return sstd_fraction_simplify ? fraction<T>{numr, denr * _number}.simplify()
                                  : fraction<T>{numr, denr * _number};
  }
  template <class A>
  fraction<T> operator+=(const A _number) {
    numr += _number * denr;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  template <class A>
  fraction<T> operator-=(const A _number) {
    numr -= _number * denr;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  template <class A>
  fraction<T> operator*=(const A _number) {
    numr *= _number;
    return sstd_fraction_simplify ? simplify() : *this;
  }
  template <class A>
  fraction<T> operator/=(const A _number) {
    denr *= _number;
    return sstd_fraction_simplify ? simplify() : *this;
  }

  template <class A, class integ = long>
  static fraction<integ> frac(const A _number) {
    if constexpr (std::is_integral<A>::value) {
      return sstd_fraction_simplify ? fraction<integ>{_number, 1}.simplify()
                                    : fraction<integ>{_number, 1};
    } else if (std::is_floating_point<A>::value) {
      long long exp = std::pow(10, sstd_fraction_precision);
      return sstd_fraction_simplify
                 ? fraction<integ>{static_cast<integ>(_number * exp),
                                   static_cast<integ>(exp)}
                       .simplify()
                 : fraction<integ>{static_cast<integ>(_number * exp),
                                   static_cast<integ>(exp)};
    }
  }

  std::string tostr() {
    return sstd_fraction_simplify
               ? denr == 1 ? std::to_string(numr)
                           : std::to_string(numr) + "/" + std::to_string(denr)
               : std::to_string(numr) + "/" + std::to_string(denr);
  }
};

#if defined(SSTD_PRINTCONT_HH)

template <typename T>
void print(fraction<T> _fraction) {
  std::cout << _fraction.cnumer() << "/" << _fraction.cdenom();
}

#endif

}  // namespace sstd

#endif /* FRACTION_HH */
