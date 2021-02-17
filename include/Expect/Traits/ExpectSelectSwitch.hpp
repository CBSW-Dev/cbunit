#pragma once
#include "ExpectSelectCondition.hpp"
#include <type_traits>

namespace CBUnit
{
  //Default is not implemented
  template <typename Head, typename ...Tail> class ExpectSelectSwitch {};

  template <bool Predicate, typename T, typename ...Tail> class ExpectSelectSwitch<ExpectSelectCondition<Predicate, T>, Tail...>
  {
  public:
    using Type = typename std::conditional<Predicate, T, typename ExpectSelectSwitch<Tail...>::Type>::type;
  };

  template <bool Predicate, typename T> class ExpectSelectSwitch<ExpectSelectCondition<Predicate, T>>
  {
  public:
    using Type = T;
  };

  template<typename Head> class ExpectSelectSwitch<Head>
  {
  public:
    using Type = Head;
  };
}

