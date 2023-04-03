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
 * TODO Find a way to make __FILE__ work properly. Till, then, depreciated.
 *
 */

#ifndef SSTD_ASSERT_HPP
#define SSTD_ASSERT_HPP

#include <cassert>
#include <iostream>
#include <string>

namespace sstd {

/// @brief Asserts a boolean expression. Differs from stdlib assert in that it
/// outputs on success. Throws upon failed assertion.
/// @param toEvaluate Boolean expression to evaluate.
/// @return Returns true if assertion succeeded. Throws otherwise.
/// @warning __FILE__ expands to this file, not the file the function is called.
/// __LINE__ works similarly. Therefore, useless.
bool Assert(bool toEvaluate) {
  static unsigned int counter = 1;
  if (toEvaluate)
    std::cout << "Test case " << counter << " succeeded." << std::endl;
  else if (!toEvaluate) {
    std::cout << "Test case " << counter << " failed." << std::endl
              << "Traceback: \n"
                 "Location: \'"
              << __FILE__ << "\', line " << __LINE__ << std::endl;

    ++counter;
    throw "Assertion failed";
  } else {
    std::cout << "Something went wrong. That's all we know." << std::endl;

    ++counter;
    throw std::invalid_argument("Invalid argument");
  }

  ++counter;
  return true;
}

/// @brief Asserts a boolean expression. Differs from stdlib assert in that it
/// outputs on success. Throws upon failed assertion.
/// @param toEvaluate Boolean expression to evaluate.
/// @param comment Optional comment.
/// @return Returns true if assertion succeded. Throws otherwise.
/// @warning __FILE__ expands to this file, not the file the function is called.
/// __LINE__ works similarly. Therefore, useless.
bool Assert(bool toEvaluate, std::string comment) {
  static unsigned int counter = 1;
  if (toEvaluate)
    std::cout << "Test case " << counter
              << " succeeded."
                 "\n Note: "
              << comment << std::endl;
  else if (!toEvaluate) {
    std::cout << "Test case " << counter << " failed." << std::endl
              << "Traceback: \n"
                 "Location: \'"
              << __FILE__ << "\', line " << __LINE__ << "\nNote: " << comment
              << std::endl;

    ++counter;
    throw "Assertion failed";
  } else {
    std::cout << "Something went wrong. That's all we know. \n"
                 "Note: "
              << comment << std::endl;

    ++counter;
    throw std::invalid_argument("Invalid argument");
  }

  ++counter;
  return true;
}

/// @brief Force-asserts a boolean expression. Differs from stdlib assert in
/// that it outputs on success. No-throw guaranteed.
/// @param toEvaluate Boolean expression to evaluate.
/// @return Returns true if assertion succeded. Returns false otherwise.
/// @warning __FILE__ expands to this file, not the file the function is called.
/// __LINE__ works similarly. Therefore, useless.
bool fAssert(bool toEvaluate) {
  static unsigned int counter = 1;
  if (toEvaluate)
    std::cout << "Test case " << counter << " succeeded." << std::endl;
  else if (!toEvaluate) {
    std::cout << "Test case " << counter << " failed." << std::endl
              << "Traceback: \n"
                 "Location: \'"
              << __FILE__ << "\', line " << __LINE__ << std::endl;

    ++counter;
    return false;
  } else {
    std::cout << "Something went wrong. That's all we know." << std::endl;

    ++counter;
    return false;
  }

  ++counter;
  return true;
}

/// @brief Force-asserts a boolean expression. Differs from stdlib assert in
/// that it outputs on success. No-throw guaranteed.
/// @param toEvaluate Boolean expression to evaluate.
/// @param comment Optional comment.
/// @return Returns true if assertion succeded. Returns false otherwise.
/// @warning __FILE__ expands to this file, not the file the function is called.
/// __LINE__ works similarly. Therefore, useless.
bool fAssert(bool toEvaluate, std::string comment) {
  static unsigned int counter = 1;
  if (toEvaluate)
    std::cout << "Test case " << counter
              << " succeeded."
                 "\n Note: "
              << comment << std::endl;
  else if (!toEvaluate) {
    std::cout << "Test case " << counter << " failed." << std::endl
              << "Traceback: \n"
                 "Location: \'"
              << __FILE__ << "\', line " << __LINE__ << "\nNote: " << comment
              << std::endl;

    ++counter;
    return false;
  } else {
    std::cout << "Something went wrong. That's all we know. \n"
                 "Note: "
              << comment << std::endl;

    ++counter;
    return false;
  }

  ++counter;
  return true;
}

}  // namespace sstd

#endif