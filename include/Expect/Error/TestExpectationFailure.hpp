#pragma once
#include "TestExpectationMessageBuilder.hpp"
#include "Expect/Chains/ExpectLogic.hpp"

namespace CBUnit
{
  struct ExpectNoText {static constexpr const char* text = "";};

  template <typename T, class U, class Logic, class Text = ExpectNoText> class TestExpectationFailure {};

  template <typename T, typename U, class Text> class TestExpectationFailure<T, U, ExpectLogic, Text>: public TestError
  {
  public:
    TestExpectationFailure(T actual, const char* filename, uint32_t lineNumber):
      TestError(TestExpectationMessageBuilder::buildMessage(actual, Text::text), filename, lineNumber)
    {}

    TestExpectationFailure(T actual, U expected, const char* filename, uint32_t lineNumber):
      TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, Text::text), filename, lineNumber)
    {}

    TestExpectationFailure(T actual, U expected, const std::string& text, const char* filename, uint32_t lineNumber):
      TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, text), filename, lineNumber)
    {}
  };

  template <typename T, typename U, class Text> class TestExpectationFailure<T, U, ExpectInvertingLogic, Text>: public TestError
  {
  public:
    TestExpectationFailure(T actual, const char* filename, uint32_t lineNumber):
      TestError(TestExpectationMessageBuilder::buildMessage(actual, std::string("not ") + Text::text), filename, lineNumber)
    {}

    TestExpectationFailure(T actual, U expected, const char* filename, uint32_t lineNumber):
      TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, std::string("not ") + Text::text), filename, lineNumber)
    {}

    TestExpectationFailure(T actual, U expected, const std::string& text, const char* filename, uint32_t lineNumber):
      TestError(TestExpectationMessageBuilder::buildMessage(actual, expected, std::string("not ") + text), filename, lineNumber)
    {}
  };
}