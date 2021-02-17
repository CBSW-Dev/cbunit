#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "Expect/Chains/ExpectBase.hpp"
#include "ExpectTo.hpp"
namespace CBUnit
{
  template <typename T> class ExpectUnderlyingType
  {
  public:
    using Type = T;
  };
  
  template <typename T> class ExpectSelect
  {
  public:
    using Type = ExpectUnderlyingType<T>;
  };
}

