#pragma once
#include "Expect/Chains/ExpectLogic.hpp"

#include "Utility/Unused.hpp"

namespace CBUnit
{
  //default ExpectToBeAt has nothing
  template <typename T, typename Logic, typename Enabler = void> class ExpectToBeAt {};

  template <typename T, typename Logic> class ExpectToBeAtBase: public ExpectToBeAt<T, Logic> 
  {
  public:
    ExpectToBeAtBase(typename ExpectBase<T>::Type actual, const char* filename, uint32_t lineNumber) 
    {
      ::CBUnit::unused(actual, filename, lineNumber);
    }
  };
}

