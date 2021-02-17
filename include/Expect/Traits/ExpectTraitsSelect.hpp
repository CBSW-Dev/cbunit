#pragma once

#include "ExpectSelectSwitch.hpp"
#include "ExpectDefaultTraits.hpp"
#include "ExpectIntegerTraits.hpp"
#include "ExpectFloatingPointTraits.hpp"

namespace CBUnit
{
  template <typename T> class ExpectTraitsSelect
  {
  public:
    using Type = typename ExpectSelectSwitch<
      ExpectSelectCondition<std::is_same<T, bool>::value, ExpectDefaultTraits>, //only makes sense for boolean to have equals
      ExpectSelectCondition<std::is_integral<T>::value, ExpectIntegerTraits>,
      ExpectSelectCondition<std::is_floating_point<T>::value, ExpectFloatingPointTraits>,
      ExpectDefaultTraits
    >::Type;
  };
}

