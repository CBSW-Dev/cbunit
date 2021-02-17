#pragma once

namespace CBUnit
{
  class ExpectIntegerTraits
  {
  public:
    static constexpr bool hasEquals = true;
    static constexpr bool hasGreaterThan = true;
    static constexpr bool hasGreaterThanOrEqual = true;
    static constexpr bool hasLessThan = true;
    static constexpr bool hasLessThanOrEqual = true;
  };
}

