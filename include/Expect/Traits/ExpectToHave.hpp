#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "Utility/Unused.hpp"

namespace CBUnit
{
  //default ExpectToHave has nothing
  template <typename T, typename Logic, typename Enabler = void> class ExpectToHave {};

  template <typename T, typename Logic> class ExpectToHaveBase: public ExpectToHave<T, Logic> 
  {
  public:
    ExpectToHaveBase(typename ExpectBase<T>::Type actual, const char* filename, uint32_t lineNumber) 
    {
      ::CBUnit::unused(actual, filename, lineNumber);
    }
  };
}

