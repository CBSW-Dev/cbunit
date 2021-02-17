#pragma once

#include "ExpectSelectSwitch.hpp"
#include "ExpectTraits.hpp"
#include "ExpectIntegerTraits.hpp"

namespace CBUnit
{
  template <typename T> class ExpectTraitsSelect
  {
  public:
   
    using Type = typename ExpectSelectSwitch<
      ExpectSelectCondition<std::is_integral<T>::value, ExpectIntegerTraits>,
      ExpectTraits
    >::Type;
  };
}

