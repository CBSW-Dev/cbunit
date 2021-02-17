#pragma once

#include "OutputStream.hpp"

namespace CBUnit
{
  class OutputStreamFactory
  {
  public:
    static OutputStream* createOutputStream(const std::string& streamName);
  };
}