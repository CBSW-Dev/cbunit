#pragma once
#include <type_traits>

namespace CBUnit
{
  template <typename T, typename U> class ExpectSame
  {
  public:
    using DecayedType = typename std::remove_cv<typename std::remove_reference<T>::type>::type;

    static constexpr bool value = std::is_same<DecayedType, U>::value;
  };

  template <typename T, typename U> class ExpectEnableIfSame: public std::enable_if<ExpectSame<T, U>::value> {};
}