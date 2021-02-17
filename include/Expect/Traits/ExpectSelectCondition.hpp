#pragma once

namespace CBUnit
{
  template <bool Predicate, typename T> class ExpectSelectCondition
  {
  public:
    static constexpr bool Value = Predicate;
    using Type = T;
  };
};