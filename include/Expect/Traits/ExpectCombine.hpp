#pragma once
#include "Expect/Chains/ExpectBase.hpp"

namespace CBUnit
{
  template <class T, class ...Classes> class ExpectCombine: public virtual ExpectBase<T>, public Classes...
  {
  public:
    ExpectCombine(const T& actual, const char* filename, uint32_t lineNumber):
      ExpectBase<T>(actual, filename, lineNumber)
    {}
  };
}