#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "Expect/Chains/ExpectBase.hpp"
#include "ExpectTo.hpp"
namespace CBUnit
{
  template <typename T> class ExpectRoot
  {
  public:
    ExpectRoot(const T& actual, const char* filename, uint32_t lineNumber):
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber)
    {}

    class Not
    {
    public:
      Not(const T& actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      ExpectBaseMixin<T, ExpectToBase<T, ExpectInvertingLogic>> to;
    };

    Not not;
    ExpectBaseMixin<T, ExpectToBase<T, ExpectLogic>> to;
  };
}

