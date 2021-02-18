#pragma once
#include "Expect/Chains/ExpectLogic.hpp"

namespace CBUnit
{
  //default ExpectToHave has nothing
  template <typename T, typename Logic, typename Enabler = void> class ExpectToHave {};

  template <typename T, typename Logic> class ExpectToHaveBase: public ExpectToHave<T, Logic> 
  {
  public:
    ExpectToHaveBase(const T& actual, const char* filename, uint32_t lineNumber) {}
  };
}

