#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "Expect/Error/TestExpectationFailure.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    struct TestExpectationLessThanText {static constexpr const char* text = "to be less than";};
    template <typename T, class Logic> using TestExpectationLessThanFailure = TestExpectationFailure<T, T, Logic, TestExpectationLessThanText>; 

  }

  template <class T, class Logic = ExpectLogic>
  class ExpectLessThan: public virtual ExpectBase<T>
  {
  public:
    void lessThan(typename ExpectBase<T>::Type expected) const
    {
      if (Logic::logic(this->actual() >= expected))
      {
        throw TestExpectationLessThanFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }

    //aliases
    void below(typename ExpectBase<T>::Type expected) {lessThan(expected);}
    void lt(typename ExpectBase<T>::Type expected) const {lessThan(expected);}
  };
}
