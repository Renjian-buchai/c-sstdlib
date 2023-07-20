#if !defined(SSTDV2_TOSTRVEC)
#define SSTDV2_TOSTRVEC

#include <string>
#include <vector>

namespace sstd {

/**
 * @brief Converts char** to an std::vector of std::strings
 *
 * @param charArr cstring array to input
 * @param size Size of cstring array
 * @return std::vector of std::strings
 *
 * @example Input argc and argv into a more convenient way to access arguments
 */
std::vector<std::string> toStrVec(char** charArr, int size) {
  std::vector<std::string> ret;
  for (int i = 0; i < size; ++i) {
    ret.push_back(std::string(charArr[size]));
  }
  return ret;
}

}  // namespace sstd

#endif
