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

#if !defined(SSTD_FRACTION_HPP)
#define SSTD_FRACTION_HPP

#include <boost/integer/common_factor.hpp>  // boost::integer::gcd
#include <cctype>
#include <cmath>
#include <exception>
#include <iostream>
#include <memory>
#include <sstd/except/div0.hpp>     // sstd::div0
#include <sstd/except/invCall.hpp>  // sstd::invCall
#include <string>
#include <system_error>

template <typename Condition, typename T = void>
using enIf = typename std::enable_if<Condition::value, T>::type;

namespace sstd {

bool sstd_fraction_simplify = true;

/// @brief Configures fraction data.
/// @param simplify Whether to simplify fractions.
/// true = simplify, false = do not simplify. Default=true
void configureFraction(bool simplify) { sstd_fraction_simplify = simplify; }

/// @brief Class fraction.
/// @tparam T : Only makes sense if you put an integer type. Float types make it
/// less precise.
template <class T = long>
class fraction {
 private:
  T numr = 0;
  T denr = 1;
  T quot = 0;

 public:
  // ANCHOR Constructor

  /// @brief Initialises an empty fraction (Numerator = 0, denominator = 1,
  /// quotient = 0)
  fraction() = default;

  /// @brief Initialises a fraction.
  /// @param numerator Numerator of new fraction.
  /// @param denominator Denominator of new fraction.
  fraction(T numerator, T denominator) {
    if (denr == 0) throw new div0();
    numr = numerator;
    denr = denominator;
  }

  /// @brief Initialises a mixed number.
  /// @param quotient Quotient of new fraction.
  /// @param numerator Numerator of new fraction.
  /// @param denominator Denominator of new fraction.
  /// @throw sstd::div0 if denominator == 0.
  fraction(T quotient, T numerator, T denominator) {
    if (denr == 0) throw new div0();
    quot = quotient;
    numr = numerator;
    denr = denominator;
    return;
  }

  // ANCHOR Output methods

#if defined(SSTD_PRINTCONT_HPP)
  /// @brief Prints fraction as a mixed number. If it cannot be converted into a
  /// mixed number, i.e. numerator + denominator * quotient < denominator, calls
  /// sstd::fraction:::print() instead.
  void printMixed() {
    if (quot == 0) {
      quot = floor(numr / denr);
      numr -= denr * quot;

      // Checks if it is still a fraction.
      if (quot == 0) {
        this->print();
        return;
      }
    }

    if (numr == 0)
      std::cout << quot << "\n";
    else if (denr == 1)
      std::cout << quot + numr << "\n";
    else
      std::cout << quot << ", " << numr << " / " << denr << "\n";

    return;
  }

  /// @brief Prints fraction as an improrper fraction.
  void print() {
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    if (denr == 1)
      std::cout << numr << "\n";
    else
      std::cout << numr << " / " << denr << "\n";

    return;
  }
#endif

  // ANCHOR Conversion methods

  /// @brief Converts a mixed number to a fraction.
  /// @return This as a fraction.
  fraction<T> tofr() {
    if (quot == 0) return *this;
    numr += quot * denr;
    quot = 0;
    return *this;
  }

  /// @brief Converts a fraction to a mixed number.
  /// @return This as a mixed number.
  fraction<T> toMixed() {
    if (quot != 0) return *this;
    quot = floor(numr / denr);
    numr -= denr * quot;
    return *this;
  }

  /// @brief Converts a fraction to a decimal.
  /// @tparam floatType Any floating point type.
  /// @return This as a decimal.
  template <typename floatType, enIf<std::is_floating_point<floatType>>>
  floatType dec() {
    return quot + numr / denr;
  }

  /// @brief Simplifies a fraction.
  /// @return This in simplest form.
  fraction<T> simplify() {
    T highest = boost::integer::gcd(numr, denr);
    numr /= highest;
    denr /= highest;
    return *this;
  }

  // ANCHOR Getter methods

  /// @brief Gets numerator.
  T numerator() { return numr; }

  /// @brief Gets denominator.
  T denominator() { return denr; }

  /// @brief Gets quotient
  T quotient() { return quot; }

  // ANCHOR Arithmetic methods

  /// @brief Adds a fraction to this.
  /// @param _fraction Fraction to be added.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after addition.
  fraction<T> add(fraction<T> _fraction,
                  bool simplify = sstd_fraction_simplify) {
    _fraction.tofr();
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    if (denr == _fraction.denominator())
      numr += _fraction.numerator();
    else {
      numr = _fraction.numerator() * denr + _fraction.denominator() * numr;
      denr *= _fraction.denominator();
    }

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Adds a number to this.
  /// @param toAdd Number to add.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after addition.
  fraction<T> add(T toAdd, bool simplify = sstd_fraction_simplify) {
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    numr += toAdd * denr;

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Subtracts a fraction from this.
  /// @param _fraction Fraction to be subtracted.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after subtraction.
  fraction<T> sub(fraction<T> _fraction,
                  bool simplify = sstd_fraction_simplify) {
    _fraction.tofr();
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    if (denr == _fraction.denominator())
      numr -= _fraction.numerator();
    else {
      numr = numr * _fraction.denominator() - _fraction.numerator() * denr;
      denr *= _fraction.denominator();
    }

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Subtracts a number from this.
  /// @param toSub Number to be subtracted.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after subtraction.
  fraction<T> sub(T toSub, bool simplify = sstd_fraction_simplify) {
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    numr -= toSub * denr;

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Multiplies a fraction to this.
  /// @param _fraction Fraction to be multiplied.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction();
  /// @return This after multiplication.
  fraction<T> mult(fraction<T> _fraction,
                   bool simplify = sstd_fraction_simplify) {
    _fraction.tofr();
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    numr = _fraction.numerator() * numr;
    denr = _fraction.denominator() * denr;

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Multiplies a number to this.
  /// @param toMult Number to be multiplied.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after multiplication.
  fraction<T> mult(T toMult, bool simplify = sstd_fraction_simplify) {
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    numr = numr * toMult;

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Divides this by a fraction.
  /// @param _fraction Fraction to be divided.
  /// @param simplify Whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after division.
  fraction<T> div(fraction<T> _fraction,
                  bool simplify = sstd_fraction_simplify) {
    _fraction.tofr();
    if (quot != 0) {
      numr += quot * denr;
      quot = 0;
    }

    numr *= _fraction.denominator();
    denr *= _fraction.numerator();

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }

  /// @brief Divides this by a number.
  /// @param toDiv Fraction to be divided.
  /// @param simplify whether to be simplified. Default set by
  /// sstd::configurefraction().
  /// @return This after division.
  fraction<T> div(T toDiv, bool simplify = sstd_fraction_simplify) {
    if (quot != 0) {
      numr += quot * numr;
      quot = 0;
    }

    denr *= toDiv;

    if (simplify) {
      T highest = boost::integer::gcd(numr, denr);
      numr /= highest;
      denr /= highest;
    }

    return *this;
  }
};

// ANCHOR Output functions

#if defined(SSTD_PRINTCONT_HPP)

/// @brief Prints a fraction.
/// @param toPrint Fraction to print.
/// @param form Form to print fraction. Fraction='f', mixed number='m'.
/// Default='f'.
template <typename T>
void printf(fraction<T> toPrint, char form = 'f') {
  if (form == 'f') {
    T numr = toPrint.numerator();
    if (toPrint.quotient() != 0) {
      numr += toPrint.quotient() * toPrint.denominator();
    }

    if (toPrint.denominator() == 1)
      std::cout << numr << "\n";
    else
      std::cout << numr << " / " << toPrint.denominator() << "\n";
  } else if (form == 'M') {
    T quot = 0;
    T numr = toPrint.numerator();
    if (toPrint.quotient() == 0) {
      quot = floor(toPrint.numerator() / toPrint.denominator());
      numr -= toPrint.denominator() * toPrint.quotient();
    }

    if (toPrint.numerator() == 0)
      std::cout << quot << "\n";
    else if (toPrint.denominator() == 1)
      std::cout << quot + numr << "\n";
    else
      std::cout << quot << ", " << numr << " / " << toPrint.denominator()
                << "\n";
  } else
    throw std::invalid_argument("Invalid form. Valid forms are: 'f', 'm'");

  return;
}

#endif

template <typename T = long>
fraction<T> add(fraction<T> _base_frac, T toAdd,
                bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();

  return simplify
             ? fraction<T>(
                   _base_frac.numerator() + toAdd * _base_frac.denominator(),
                   _base_frac.denominator())
                   .simplify()
             : fraction<T>(
                   _base_frac.numerator() + toAdd * _base_frac.denominator(),
                   _base_frac.denominator());
}

template <typename T = long>
fraction<T> add(T base_int, fraction<T> _fraction,
                bool simplify = sstd_fraction_simplify) {
  _fraction.tofr();

  return simplify
             ? fraction<T>(
                   _fraction.numerator() + base_int * _fraction.denominator(),
                   _fraction.denominator())
                   .simplify()
             : fraction<T>(
                   _fraction.numerator() + base_int * _fraction.denominator(),
                   _fraction.denominator());
}

template <typename T = long>

fraction<T> add(fraction<T> _base_frac, fraction<T> _fraction,
                bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();
  _fraction.tofr();

  T numr = _base_frac.numerator() + _fraction.numerator;
  T denr = _base_frac.denominator();

  if (_base_frac.denominator() != _fraction.denominator()) {
    numr = _fraction.denominator() * _base_frac.numerator() +
           _base_frac.denominator() * _fraction.numerator();
    denr = _base_frac.denominator() * _fraction.denominator();
  }

  return simplify ? fraction<T>(numr, denr).simplify()
                  : fraction<T>(numr, denr);
}

template <typename T = long>
fraction<T> sub(fraction<T> _base_frac, fraction<T> _fraction,
                bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();
  _fraction.tofr();

  T numr = _base_frac.numerator() - _fraction.denominator();
  T denr = _base_frac.denominator();

  if (_base_frac.denominator() != _fraction.denominator()) {
    numr = _fraction.denominator() * _base_frac.numerator() -
           _fraction.numerator() * _base_frac.denominator();
    denr = _fraction.numerator() * _fraction.denominator();
  }

  return simplify ? fraction<T>(numr, denr).simplify()
                  : fraction<T>(numr, denr);
}

template <typename T = long>
fraction<T> sub(fraction<T> _base_frac, T toSub,
                bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();

  return simplify
             ? fraction<T>(
                   _base_frac.numerator() - toSub * _base_frac.denominator(),
                   _base_frac.denominator())
                   .simplify()
             : fraction<T>(
                   _base_frac.numerator() - toSub * _base_frac.denominator(),
                   _base_frac.denominator());
}

template <typename T = long>
fraction<T> sub(T base_num, fraction<T> _fraction,
                bool simplify = sstd_fraction_simplify) {
  _fraction.tofr;

  return simplify
             ? fraction<T>(
                   base_num * _fraction.denominator() - _fraction.numerator(),
                   _fraction.denominator())
                   .simplify()
             : fraction<T>(
                   base_num * _fraction.denominator() - _fraction.numerator(),
                   _fraction.denominator());
}

template <typename T = long>
fraction<T> mult(fraction<T> _base_frac, fraction<T> _fraction,
                 bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();
  _fraction.tofr();

  return simplify
             ? fraction<T>(_base_frac.numerator() * _fraction.numerator(),
                           _base_frac.denominator() * _fraction.denominator())
                   .simplify()
             : fraction<T>(_base_frac.numerator() * _fraction.numerator(),
                           _base_frac.denominator() * _fraction.denominator());
}

template <typename T = long>
fraction<T> mult(fraction<T> _base_frac, T toMult,
                 bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();

  return simplify ? fraction<T>(_base_frac.numerator() * toMult,
                                _base_frac.denominator())
                        .simplify()
                  : fraction<T>(_base_frac.numerator() * toMult,
                                _base_frac.denominator());
}

template <typename T = long>
fraction<T> mult(T base_num, fraction<T> _fraction,
                 bool simplify = sstd_fraction_simplify) {
  _fraction.tofr();

  return simplify ? fraction<T>(_fraction.numerator() * base_num,
                                _fraction.denominator())
                        .simplify()
                  : fraction<T>(_fraction.numerator() * base_num,
                                _fraction.denominator());
}

template <typename T = long>
fraction<T> div(fraction<T> _base_frac, fraction<T> _fraction,
                bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();
  _fraction.tofr();

  return simplify
             ? fraction<T>(_base_frac.numerator() * _fraction.denominator(),
                           _base_frac.denominator() * _fraction.numerator())
                   .simplify()
             : fraction<T>(_base_frac.numerator() * _fraction.denominator(),
                           _base_frac.denominator() * _fraction.numerator());
}

template <typename T = long>
fraction<T> div(fraction<T> _base_frac, T toDiv,
                bool simplify = sstd_fraction_simplify) {
  _base_frac.tofr();

  return simplify ? fraction<T>(_base_frac.numerator(),
                                _base_frac.denominator() * toDiv)
                        .simplify()
                  : fraction<T>(_base_frac.numerator(),
                                _base_frac.denominator() * toDiv);
}

template <typename T = long>
fraction<T> div(T base_num, fraction<T> _fraction,
                bool simplify = sstd_fraction_simplify) {
  _fraction.tofr();

  return simplify ? fraction<T>(base_num * _fraction.denominator(),
                                _fraction.numerator())
                        .simplify()
                  : fraction<T>(base_num * _fraction.denominator(),
                                _fraction.numerator());
}

}  // namespace sstd

#endif /* FRACTION_HPP */