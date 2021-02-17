#pragma once

#pragma once
#include "TestStructure/TestError.hpp"

#include <sstream>

namespace CBUnit
{
  class TestExpectationMessageBuilder
  {
  public:
    template <class T> static std::string buildMessage(const T& actual, const T& expected, const std::string& conjunction)
    {
      std::stringstream ss;
      ss << "Expected (";
      ss << actual;
      ss << ") ";
      ss << conjunction;
      ss << " (";
      ss << expected;
      ss << ")";
      return ss.str();
    }
  };
}
