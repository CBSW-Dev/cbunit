#pragma once
#include <type_traits>

namespace CBUnit
{
  template <typename T> class ExpectIs
  {
  public:
    static constexpr bool boolean = std::is_same<T, bool>::value;
    static constexpr bool integer = std::is_integral<T>::value && !boolean;
    static constexpr bool string = std::is_same<T, std::string>::value;
    static constexpr bool pointer = std::is_pointer<T>::value;
  };
}