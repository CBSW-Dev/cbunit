#pragma once
#include "ExpectCombine.hpp"

#include "ExpectEquals.hpp"
#include "ExpectGreaterThan.hpp"
#include "ExpectGreaterThanOrEqual.hpp"
#include "ExpectLessThan.hpp"
#include "ExpectLessThanOrEqual.hpp"
namespace CBUnit
{
  template <typename T, typename Logic> class ExpectComparable
  {
  public:
    using To = ExpectEquals<T, Logic>;
    using Be = ExpectCombine<
      ExpectGreaterThan<T, Logic>,
      ExpectGreaterThanOrEqual<T, Logic>,
      ExpectLessThan<T, Logic>,
      ExpectLessThanOrEqual<T, Logic>
    >;
    using At = ExpectCombine<
      ExpectAtLeast<T, Logic>,
      ExpectAtMost<T, Logic>
    >;
  };
}