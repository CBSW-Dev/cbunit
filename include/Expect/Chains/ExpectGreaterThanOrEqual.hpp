#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "Expect/Error/TestExpectationFailure.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    struct TestExpectationGreaterThanOrEqualText {static constexpr const char* text = "to be greater than or equal to";};
    template <typename T, class Logic> using TestExpectationGreaterThanOrEqualFailure = TestExpectationFailure<T, Logic, TestExpectationGreaterThanOrEqualText>; 

    struct TestExpectationAtLeastText {static constexpr const char* text = "to be at least";};
    template <typename T, class Logic> using TestExpectationAtLeastFailure = TestExpectationFailure<T, Logic, TestExpectationAtLeastText>; 
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectGreaterThanOrEqual: public virtual ExpectBase<T>
  {
  public:
    void greaterThanOrEqual(T expected) const
    {
      if (Logic::logic(this->actual() < expected))
      {
        throw TestExpectationGreaterThanOrEqualFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }

    //aliases
    void gte(T expected) const {greaterThanOrEqual(expected);}
  };

  template <class T, class Logic = ExpectLogic>
  class ExpectAtLeast: public virtual ExpectBase<T>
  {
  public:
    void least(T expected) const
    {
      if (Logic::logic(this->actual() < expected))
      {
        throw TestExpectationAtLeastFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }
  };
}
