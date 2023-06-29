#if !defined(SSTD_TOSTRVEC_HH)
#define SSTD_TOSTRVEC_HH

#include <string>
#include <vector>

namespace sstd {

std::vector<std::string> toStrVec(char** pCharArr, size_t size) {
  std::vector<std::string> result;
  for (size_t i = 0; i < size; ++i) {
    result.push_back(std::string(pCharArr[i]));
  }
  return result;
}

}  // namespace sstd

#endif