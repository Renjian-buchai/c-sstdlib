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

#ifndef SSTD_INVCALL_HH
#define SSTD_INVCALL_HH

#include <exception>
#include <string>

namespace sstd {

/// @brief Exception class for a method call from a bad object.
class invCall : std::exception {
 private:
  const char* message =
      (char*)"InvalidCallException";  // Typecast to remove warning

 public:
  invCall() = default;

  /// @brief Sets the message.
  /// @param _message Exception message. Default="InvalidCallException"
  invCall(std::string _message) { message = _message.c_str(); }

  const char* what() const noexcept override { return message; }
};

}  // namespace sstd

#endif