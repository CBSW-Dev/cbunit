#pragma once
#include "Expect/Chains/ExpectBase.hpp"

namespace CBUnit
{
  template <class T, class ...Classes> class ExpectCombine: public virtual ExpectBase<T>, public Classes...
  {
  public:
    ExpectCombine(const T& actual, const char* filename, uint32_t lineNumber):
      _actual(actual),
      _filename(filename),
      _lineNumber(lineNumber)
    {}

    const T& actual() const override
    {
      return _actual;
    }

    const char* filename() const override
    {
      return _filename;
    }

    uint32_t lineNumber() const override
    {
      return _lineNumber;
    }
  private:
    const T& _actual;
    const char* _filename;
    uint32_t _lineNumber;
  };
}