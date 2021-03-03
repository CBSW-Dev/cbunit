#pragma once
#include "TestExpectationMessageBuilder.hpp"
#include "Expect/Chains/ExpectLogic.hpp"

namespace CBUnit
{
  template <typename Logic> class TestExpectationObjectFailure {};
  
  template <> class TestExpectationObjectFailure<ExpectLogic>: public TestError
  {
  public:
    TestExpectationObjectFailure(const std::string& object, const std::string& text, const char* filename, uint32_t lineNumber):
      TestError(std::string("Expected ") + object + " " + text, filename, lineNumber)
    {}
  };

  template <> class TestExpectationObjectFailure<ExpectInvertingLogic>: public TestError
  {
  public:
    TestExpectationObjectFailure(const std::string& object, const std::string& text, const char* filename, uint32_t lineNumber):
      TestError(std::string("Expected ") + object + " not " + text, filename, lineNumber)
    {}
  };
}