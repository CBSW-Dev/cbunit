#include "LineInfo.hpp"

namespace CBUnit
{
  LineInfo::LineInfo(uint32_t line)
  {
    LineInfo::line = line;
  }

  uint32_t LineInfo::line = 0;
}