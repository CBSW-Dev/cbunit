#pragma once

#include "Common.hpp"

namespace CBUnit
{
  class LineInfo
  {
  public:
    LineInfo(uint32_t line);
    static uint32_t line;
  };
}

#define CBUNIT_LINEINFO ::CBUnit::LineInfo CBUNIT_CONCAT(_cbunit_line,__COUNTER__)(__LINE__);