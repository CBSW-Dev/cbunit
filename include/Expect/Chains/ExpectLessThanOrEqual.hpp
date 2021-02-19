#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "TestExpectationMessageBuilder.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  namespace
  {
    template <class T, class Logic> class TestExpectationLessThanOrEqualFailure {};
  
    template <class T> class TestExpectationLessThanOrEqualFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationLessThanOrEqualFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to be less than or equal"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationLessThanOrEqualFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationLessThanOrEqualFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to be less than or equal"), filename, lineNumber)
      {}
    };

    template <class T, class Logic> class TestExpectationAtMostFailure {};
  
    template <class T> class TestExpectationAtMostFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationAtMostFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to be at most"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationAtMostFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationAtMostFailure(T actual, T expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to be at most"), filename, lineNumber)
      {}
    };
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectLessThanOrEqual: public virtual ExpectBase<T>
  {
  public:
    void lessThanOrEqual(T expected) const
    {
      if (Logic::logic(this->actual() < expected))
      {
        throw TestExpectationLessThanOrEqualFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }

    //aliases
    void lte(T expected) const {lessThanOrEqual(expected);}
  };

  template <class T, class Logic = ExpectLogic>
  class ExpectAtMost: public virtual ExpectBase<T>
  {
  public:
    void most(T expected) const
    {
      if (Logic::logic(this->actual() < expected))
      {
        throw TestExpectationAtMostFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }
  };
}
