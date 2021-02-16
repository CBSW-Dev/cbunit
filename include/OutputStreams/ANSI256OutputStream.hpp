#pragma once

#include "StdCoutOutputStream.hpp"

namespace CBUnit
{
  class ANSI256OutputStream: public StdCoutOutputStream
  {
  public:
    ANSI256OutputStream& operator << (Colours colour) override;
  };
}