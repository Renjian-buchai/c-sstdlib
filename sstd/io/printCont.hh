#if !defined(SSTDV2_PRINTCONT)
#define SSTDV2_PRINTCONT

#include <algorithm>  /// reverse
#include <iostream>   /// cout
#include <string>     /// string, to_string

namespace sstd {

/**
 * @brief Outputs a range
 *
 * @tparam const_iterator A constant_iterator. Not a const iterator
 * @param begin Start of range to output
 * @param end End of range to output
 */
template <typename const_iterator>
void output(const_iterator begin, const_iterator end) {
  std::cout << "[";
  std::advance(end, -1);
  for (; begin != end; ++begin) {
    std::cout << *begin << ", ";
  }
  std::cout << *end << "]";
  return;
}

/**
 * @brief Outputs a range
 *
 * @tparam const_iterator A constant_iterator. Not a const iterator
 * @param begin Start of range to output
 * @param end End of range to output
 * @param reverse Whether to reverse the range
 */
template <typename const_iterator>
void output(const_iterator begin, const_iterator end, bool reverse) {
  if (reverse) {
    std::reverse(begin, end);
  }

  std::cout << "[";
  std::advance(end, -1);
  for (; begin != end; ++begin) {
    std::cout << *begin << ", ";
  }
  std::cout << *end << "]";
  return;
}

/**
 * @brief Converts a range to a string
 *
 * @tparam const_iterator A constant_iterator. Not a const iterator
 * @param begin Start of range to output
 * @param end End of range to output
 * @return The range in a string format. The range is started and terminated by
 * brackets (`[`, `]`) and separated by commas (`,`)
 */
template <typename const_iterator>
std::string toStr(const_iterator begin, const_iterator end) {
  std::string out = "[";
  std::advance(end, -1);
  for (; begin != end - 1; ++begin) {
    out += std::to_string(*begin) + ", ";
  }
  out += std::to_string(*end) + "]";
  return out;
}

/**
 * @brief Converts a range to a string
 *
 * @tparam const_iterator A constant_iterator. Not a const iterator
 * @param begin Start of range to output
 * @param end End of range to output
 * @param reverse Whether to reverse the range
 * @return The range in a string format. The range is started and terminated by
 * brackets (`[`, `]`) and separated by commas (`,`)
 */
template <typename const_iterator>
std::string toStr(const_iterator begin, const_iterator end, bool reverse) {
  if (reverse) {
    std::reverse(begin, end);
  }

  std::string out = "[";
  std::advance(end, -1);
  for (; begin != end - 1; ++begin) {
    out += std::to_string(*begin) + ", ";
  }
  out += std::to_string(*end) + "]";
  return out;
}

}  // namespace sstd

#endif