#pragma once

#include "StdCoutOutputStream.hpp"

namespace CBUnit
{
  class ANSI8OutputStream: public StdCoutOutputStream
  {
  public:
    ANSI8OutputStream& operator << (Colours colour) override;
  };
}