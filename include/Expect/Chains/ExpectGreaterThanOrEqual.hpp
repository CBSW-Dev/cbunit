#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "TestExpectationMessageBuilder.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    template <class T, class Logic> class TestExpectationGreaterThanOrEqualFailure {};
  
    template <class T> class TestExpectationGreaterThanOrEqualFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationGreaterThanOrEqualFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to be greater than or equal to"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationGreaterThanOrEqualFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationGreaterThanOrEqualFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to be greater than or equal to"), filename, lineNumber)
      {}
    };

    template <class T, class Logic> class TestExpectationAtLeastFailure {};
  
    template <class T> class TestExpectationAtLeastFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationAtLeastFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to be at least"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationAtLeastFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationAtLeastFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to be at least"), filename, lineNumber)
      {}
    };
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
