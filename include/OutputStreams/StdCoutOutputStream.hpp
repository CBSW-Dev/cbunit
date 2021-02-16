#pragma once

#include "OutputStream.hpp"

namespace CBUnit
{
  class StdCoutOutputStream: public OutputStream
  {
  public:
    StdCoutOutputStream& operator << (const std::string& string) override;
    StdCoutOutputStream& operator << (uint32_t value) override;
    StdCoutOutputStream& operator << (Colours colour) override;
  };
}