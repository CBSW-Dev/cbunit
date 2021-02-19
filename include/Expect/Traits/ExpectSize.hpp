#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "Expect/Chains/ExpectBase.hpp"
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include <iostream>

namespace CBUnit
{
  class ExpectSize
  {
  public:
    ExpectSize(std::size_t actual, const char* filename, uint32_t lineNumber):
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber)
    {}
     
    class Not
    {
    public:
      Not(std::size_t actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      ExpectBaseMixin<std::size_t, ExpectToBase<std::size_t, ExpectInvertingLogic>> to;
    };

    Not not;
    ExpectBaseMixin<std::size_t, ExpectToBase<std::size_t, ExpectLogic>> to;
  };
}

