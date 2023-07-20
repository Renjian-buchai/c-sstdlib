#if !defined(SSTDV2_TRIM)
#define SSTDV2_TRIM

#include <algorithm>  /// find_if
#include <string>     /// string

namespace sstd {

/**
 * @brief Trims whitespaces on the left
 *
 * @param in Input string
 * @return Trimmed string
 */
inline std::string triml(std::string in) {
  in.erase(in.begin(), std::find_if(in.begin(), in.end(), [](unsigned char ch) {
             return !std::isspace(ch);
           }));
  return in;
}

/**
 * @brief Trims whitespaces on the right
 *
 * @param in Input string
 * @return Trimmed string
 */
inline std::string trimr(std::string in) {
  in.erase(std::find_if(in.rbegin(), in.rend(),
                        [](unsigned char ch) { return !std::isspace(ch); })
               .base(),
           in.end());
  return in;
}

/**
 * @brief Trims whitespaces on both sides of string
 *
 * @param in Input string
 * @return Trimmed string
 */
inline std::string trim(std::string in) {
  in.erase(std::find_if(in.rbegin(), in.rend(),
                        [](unsigned char ch) { return !std::isspace(ch); })
               .base(),
           in.end());

  in.erase(in.begin(), std::find_if(in.begin(), in.end(), [](unsigned char ch) {
             return !std::isspace(ch);
           }));

  return in;
}

// let me repeat myself kekw
/**
 * @brief Trims whitespaces on the left
 *
 * @param in Reference to input string
 */
inline void rtriml(std::string &in) {
  in.erase(in.begin(), std::find_if(in.begin(), in.end(), [](unsigned char ch) {
             return !std::isspace(ch);
           }));
}

/**
 * @brief Trims whitespaces on the right
 *
 * @param in Reference to input string
 */
inline void rtrimr(std::string &in) {
  in.erase(std::find_if(in.rbegin(), in.rend(),
                        [](unsigned char ch) { return !std::isspace(ch); })
               .base(),
           in.end());
}

/**
 * @brief Trims whitespaces on both sides
 *
 * @param in Reference to input string
 */
inline void rtrim(std::string &in) {
  in.erase(std::find_if(in.rbegin(), in.rend(),
                        [](unsigned char ch) { return !std::isspace(ch); })
               .base(),
           in.end());

  in.erase(in.begin(), std::find_if(in.begin(), in.end(), [](unsigned char ch) {
             return !std::isspace(ch);
           }));
}

}  // namespace sstd

#endif
