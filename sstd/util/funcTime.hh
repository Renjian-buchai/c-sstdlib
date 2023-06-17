#if !defined(SSTD_FUNCTIME_HH)
#define SSTD_FUNCTIME_HH

#include <chrono>  /// std::chrono::V2::high_resolution_clock::..., std::chrono::duration_cast, std::chrono::duration, std::milli
#include <utility>  /// std::pair

namespace sstd {

/// @brief Times a function over a number of iterations
/// @tparam Func Function type. Can be std::function, or a function pointer
/// @tparam ...Args Function arguments
/// @param func Function to time
/// @param iterations Number of iterations to time the function
/// @param ...args Arguments to func
/// @return A pair. First = time in long double milliseconds; Second = return
/// value of func in the last iteration.
template <typename Func, typename... Args>
std::pair<std::chrono::duration<long double, std::milli>,
          typename std::result_of<Func(Args...)>::type>
funcTime(Func func, size_t iterations, Args... args) {
  using ReturnType = typename std::result_of<Func(Args...)>::type;
  ReturnType result;
  std::chrono::_V2::high_resolution_clock::time_point t0, t1;
  size_t i = 0;

  t0 = std::chrono::high_resolution_clock::now();
  for (; i < iterations; ++i) {
    result = func(args...);
  }
  t1 = std::chrono::high_resolution_clock::now();

  return std::pair{std::chrono::duration_cast<
                       std::chrono::duration<long double, std::milli>>(t1 - t0),
                   result};
}

}  // namespace sstd

#endif