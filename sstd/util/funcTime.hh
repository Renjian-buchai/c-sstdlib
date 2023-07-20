#if !defined(SSTDV2_FUNCTIME)
#define SSTDV2_FUNCTIME

#include <chrono>  /// chrono::duration, chrono::_V2::high_resolution_clock,
///                    chrono::_V2::high_resolution_clock::now,
///                    chrono::duration_cast
#include <utility>  /// pair

namespace sstd {

/**
 * @brief Times a function, in miliseconds.
 *
 * @tparam Func Function.
 * @tparam Args Function argument(s).
 * @param iterations Number of iterations to execute the function.
 * @param func Function to time.
 * @param args Arguments taken by `func`.
 * @return std::pair of std::chrono::duration<long double, std::milli> and the
 * result of the function's execution.
 */
template <typename Func, typename... Args>
std::pair<std::chrono::duration<long double, std::milli>,
          typename std::invoke_result_t<Func(Args...)>>
funcTime(const size_t iterations, const Func func, Args... args) {
  typename std::invoke_result_t<Func(Args...)> ret;
  std::chrono::_V2::high_resolution_clock::time_point t0, t1;

  t0 = std::chrono::_V2::high_resolution_clock::now();
  for (size_t i = 0; i < iterations; ++i) {
    ret = func(args...);
  }
  t1 = std::chrono::_V2::high_resolution_clock::now();

  return std::pair<std::chrono::duration<long double, std::milli>,
                   std::invoke_result_t<Func(Args...)>>{
      std::chrono::duration_cast<
          std::chrono::duration<long double, std::milli>>(t1 - t0),
      ret};
}

}  // namespace sstd

#endif