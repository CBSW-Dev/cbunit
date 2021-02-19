#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "ExpectToBeAt.hpp"

namespace CBUnit
{
  //default ExpectToBe has nothing
  template <typename T, typename Logic, typename Enabler = void> class ExpectToBe {};

  template <typename T, typename Logic> class ExpectToBeBase: public ExpectToBe<T, Logic>
  {
  public:
    ExpectToBeBase(T actual, const char* filename, uint32_t lineNumber):
      at(actual, filename, lineNumber)
    {}
    
    ExpectBaseMixin<T, ExpectToBeAtBase<T, Logic>> at;
  };
}

