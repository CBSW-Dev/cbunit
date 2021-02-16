#pragma once

#include "StdCoutOutputStream.hpp"

namespace CBUnit
{
  class ANSI16OutputStream: public StdCoutOutputStream
  {
  public:
    ANSI16OutputStream& operator << (Colours colour) override;
  };
}