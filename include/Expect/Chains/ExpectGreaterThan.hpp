#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "Expect/Error/TestExpectationFailure.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    struct TestExpectationGreaterThanText {static constexpr const char* text = "to be greater than";};
    template <typename T, class Logic> using TestExpectationGreaterThanFailure = TestExpectationFailure<T, Logic, TestExpectationGreaterThanText>; 
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectGreaterThan: public virtual ExpectBase<T>
  {
  public:
    void greaterThan(T expected) const
    {
      if (Logic::logic(this->actual() <= expected))
      {
        throw TestExpectationGreaterThanFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }

    //aliases
    void above(T expected) {greaterThan(expected);}
    void gt(T expected) const {greaterThan(expected);}
  };
}
