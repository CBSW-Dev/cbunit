#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "TestExpectationMessageBuilder.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    template <class T, class Logic> class TestExpectationLessThanFailure {};
  
    template <class T> class TestExpectationLessThanFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationLessThanFailure(const T& actual, const T& expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to be less than"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationLessThanFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationLessThanFailure(const T& actual, const T& expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to be less than"), filename, lineNumber)
      {}
    };
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectLessThan: public virtual ExpectBase<T>
  {
  public:
    void lessThan(const T& expected) const
    {
      if (Logic::logic(this->actual() >= expected))
      {
        throw TestExpectationLessThanFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }

    //aliases
    void below(const T& expected) {lessThan(expected);}
    void lt(const T& expected) const {lessThan(expected);}
  };
}
