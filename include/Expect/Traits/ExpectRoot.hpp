#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "Expect/Chains/ExpectBase.hpp"
#include "ExpectSize.hpp"
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include <iostream>

namespace CBUnit
{
  template <typename T, typename Enabler = void> class ExpectRoot
  {
  public:
    using Type = typename std::conditional<std::is_scalar<T>::value, T, const T&>::type;
    ExpectRoot(Type actual, const char* filename, uint32_t lineNumber):
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber),
      size(sizeof(actual), filename, lineNumber)
    {}

    class Not
    {
    public:
      Not(Type actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      ExpectBaseMixin<Type, ExpectToBase<Type, ExpectInvertingLogic>> to;
    };

    Not not;
    ExpectBaseMixin<Type, ExpectToBase<Type, ExpectLogic>> to;
    ExpectSize size;
  };
}

