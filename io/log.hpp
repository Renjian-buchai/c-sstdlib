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

#ifndef SSTD_LOG_HPP
#define SSTD_LOG_HPP

#include <json/json.h>
#include <stdlib.h>

#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <ctime>
#include <fstream>
#include <ios>
#include <iostream>
#include <list>
#include <string>

namespace sstd {
namespace log {

class init {
 public:
  short logLevel = 2;
  std::string* location = nullptr;
  std::ofstream logging;
  std::string format = "";
};

init CONFIG;

void initialise() {
  static bool initialised = false;
  if (!initialised) {
    CONFIG.logging << "Complied at: " << __DATE__ << ", " << __TIME__
                   << "\n/"
                      "*------------------------------*/\n"
                   << std::endl;
    initialised = true;
  }
  return;
}

void config(unsigned short _level = 2, std::string _location = "console") {
  if (_level > 5) {
    throw std::invalid_argument("Invalid level limit. Range: 0 <= level <= 4.");
  }

  CONFIG.logLevel = _level;
  if ("console" == _location) {
    CONFIG.location = nullptr;
  } else {
    CONFIG.location = &_location;
    std::cout << "1\n";
    CONFIG.logging.open(_location, std::ofstream::out);
    if (!CONFIG.logging) {
      CONFIG.logging.open(_location, std::ofstream::trunc | std::ofstream::out);
      CONFIG.logging.close();
      CONFIG.logging.open(_location, std::ofstream::out);
    }
  }

  initialise();
  return;
}

template <typename T>
void note(std::string _message, int count = 0, ...) {
  initialise();
  va_list args;
  va_start(args, count);

  if (0 != CONFIG.logLevel) return;
  if (nullptr == CONFIG.location) {
    std::cout << _message << "\n";
    return;
  }
  auto time = std::chrono::system_clock::now();
  auto time2 = std::chrono::system_clock::to_time_t(time);

  CONFIG.logging << "Note: " << _message << " ";
  for (int i = 0; i < count; ++i) {
    std::cout << va_arg(std::string(args), std::string) << " ";
  }
  std::cout << "Time: " << std::ctime(&time2) << "\n";

  CONFIG.logging << std::flush;
}

}  // namespace log

}  // namespace sstd

#endif