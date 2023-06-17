#if !defined(SSTD_PAIRPRINT_HH)
#define SSTD_PAIRPRINT_HH

#include <string>
#include <utility>

namespace sstd {

template <typename T1, typename T2>
void print(std::pair<T1, T2> tocout) {
  std::cout << std::string(tocout.first) << ", " << std::string(tocout.second);
}

template <typename T1, typename T2>
std::string toStr(std::pair<T1, T2> tocout) {
  return std::string(tocout.first) + ", " + std::string(tocout.second);
}

}  // namespace sstd

#endif