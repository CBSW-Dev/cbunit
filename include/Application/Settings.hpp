#pragma once

#include "TestStructure/Common.hpp"

namespace CBUnit
{
  class Settings
  {
  public:
    std::string reporter = "";
    std::string output = "";

    void validate();
  };
}