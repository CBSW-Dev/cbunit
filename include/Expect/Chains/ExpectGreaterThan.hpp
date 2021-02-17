#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "TestExpectationMessageBuilder.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    template <class T, class Logic> class TestExpectationGreaterThanFailure {};
  
    template <class T> class TestExpectationGreaterThanFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationGreaterThanFailure(const T& actual, const T& expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to be greater than"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationGreaterThanFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationGreaterThanFailure(const T& actual, const T& expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to be greater than"), filename, lineNumber)
      {}
    };
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectGreaterThan: public virtual ExpectBase<T>
  {
  public:
    void greaterThan(const T& expected) const
    {
      if (Logic::logic(this->actual() <= expected))
      {
        throw TestExpectationGreaterThanFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }

    //aliases
    void above(const T& expected) {greaterThan(expected);}
    void gt(const T& expected) const {greaterThan(expected);}
  };
}
