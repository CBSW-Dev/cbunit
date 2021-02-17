#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "TestExpectationMessageBuilder.hpp"
#include "TestStructure/TestError.hpp"

#include <sstream>
#include <iostream>

namespace CBUnit
{
  namespace
  {
    template <class T, class Logic> class TestExpectationEqualsFailure {};
  
    template <class T> class TestExpectationEqualsFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationEqualsFailure(const T& actual, const T& expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "to equal"), filename, lineNumber)
      {}
    };

    template <class T> class TestExpectationEqualsFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationEqualsFailure(const T& actual, const T& expected, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, "not to equal"), filename, lineNumber)
      {}
    };
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectEquals: public virtual ExpectBase<T>
  {
  public:
    void equal(const T& expected) const
    {
      if (Logic::logic(this->actual() != expected))
      {
        throw TestExpectationEqualsFailure<T, Logic>(this->actual(), expected, this->filename(), this->lineNumber());
      }
    }
  };
}
