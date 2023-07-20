#if !defined(SSTDV2_CONTIFY)
#define SSTDV2_CONTIFY

#include <cmath>

namespace sstd {

/**
 * @brief Converts a range to any container.
 *
 * @tparam OutputCont Container type to output.
 * @tparam Iter Iterator type.
 * @param begin Iterator to the start of rango to convert.
 * @param end Iterator to the end of range to convert.
 * @return The range in the new container type.
 */
template <typename OutputCont, typename Iter>
OutputCont cc(Iter begin, Iter end) {
  OutputCont target;

  // I need chemotherapy for how cancerous this is
  for (size_t i = size_t(end - begin); i--;) {
    target.push_back(*begin);
    std::advance(begin, 1);
  }

  return target;
}

template <typename OutputCont, typename Iter>
OutputCont contify(Iter begin, Iter end) {
  OutputCont target;
  Iter copy = begin;

  // I need chemotherapy for how cancerous this is
  for (size_t i = 0; i < size_t(end - begin); ++i) {
    target.push_back(*copy);
    std::advance(copy, 1);
  }

  return target;
}

}  // namespace sstd

#endif