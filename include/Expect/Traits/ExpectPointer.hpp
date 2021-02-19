#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"
#include "Expect/Chains/ExpectEquals.hpp"

namespace CBUnit
{
  namespace
  {
    template <typename T, class Logic> class TestExpectationNullFailure {};
  
    template <typename T> class TestExpectationNullFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationNullFailure(T actual, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, "to be null"), filename, lineNumber)
      {}
    };

    template <typename T> class TestExpectationNullFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationNullFailure(T actual, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, "not to be null"), filename, lineNumber)
      {}
    };

    template <typename T, class Logic> class TestExpectationValidFailure {};
  
    template <typename T> class TestExpectationValidFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationValidFailure(T actual, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, "to be valid"), filename, lineNumber)
      {}
    };

    template <typename T> class TestExpectationValidFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationValidFailure(T actual, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, "not to be valid"), filename, lineNumber)
      {}
    };

    template <typename T, class Logic> class TestExpectationAddressFailure {};
  
    template <typename T> class TestExpectationAddressFailure<T, ExpectLogic>: public TestError
    {
    public:
      TestExpectationAddressFailure(T actual, T address, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, address, "to have address"), filename, lineNumber)
      {}
    };

    template <typename T> class TestExpectationAddressFailure<T, ExpectInvertingLogic>: public TestError
    {
    public:
      TestExpectationAddressFailure(T actual, T address, const char* filename, uint32_t lineNumber):
        TestError(TestExpectationMessageBuilder::buildMessage(actual, address, "not to have address"), filename, lineNumber)
      {}
    };
  }

  template <typename T, typename Logic> class ExpectToBePointer: public virtual ExpectBase<T>
  {
  public:
    void null()
    {
      if (Logic::logic(this->actual() != nullptr))
      {
        throw TestExpectationNullFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }

    void valid()
    {
      if (Logic::logic(this->actual() == nullptr))
      {
        throw TestExpectationValidFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }
  };

  template <typename T, typename Logic> class ExpectToHavePointer: public virtual ExpectBase<T>
  {
  public:
    void address(std::size_t address)
    {
      if (Logic::logic(reinterpret_cast<std::size_t>(this->actual()) != address))
      {
        throw TestExpectationAddressFailure<T, Logic>(this->actual(), reinterpret_cast<T>(address), this->filename(), this->lineNumber());
      }
    }
  };

  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<ExpectIs<T>::pointer>::type>: public ExpectToBePointer<T, Logic> {};
  template <typename T, typename Logic> class ExpectToHave<T, Logic, typename std::enable_if<ExpectIs<T>::pointer>::type>: public ExpectToHavePointer<T, Logic> {};
}