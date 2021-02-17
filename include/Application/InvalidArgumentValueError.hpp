#pragma once

#include "TestStructure/Common.hpp"

namespace CBUnit
{
  class InvalidArgumentValueError
  {
  public:
    std::string argument;
    std::string value;
  };
}