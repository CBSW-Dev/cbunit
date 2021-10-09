#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "Expect/Error/TestExpectationFailure.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    struct TestExpectationEqualsText {static constexpr const char* text = "to equal";};
    template <typename T, class Logic> using TestExpectationEqualsFailure = TestExpectationFailure<T, T, Logic, TestExpectationEqualsText>; 
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectEquals: public virtual ExpectBase<T>
  {
  public:
    void equal(typename ExpectBase<T>::Type expected) const
    {
      if (Logic::logic(this->actual() != expected))
      {
        throw TestExpectationEqualsFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }
  };
}
