#pragma once
#include "ExpectTraitsSelect.hpp"
#include "ExpectIntegerTraits.hpp"
#include "ExpectCombine.hpp"
#include "ExpectEmptyClass.hpp"
#include "Expect/Chains/ExpectEquals.hpp"
#include "Expect/Chains/ExpectGreaterThan.hpp"

namespace CBUnit
{
  template <typename T, typename Traits = typename ExpectTraitsSelect<T>::Type> class ExpectBuilder
  {
  public:
    ExpectBuilder(const T& actual, const char* filename, uint32_t lineNumber):
      to(actual, filename, lineNumber)
    {}

    using Be = ExpectCombine<T, 
      typename std::conditional<Traits::hasGreaterThan, ExpectGreaterThan<T>, ExpectEmptyClass>::type
    >;

    using ToBase = ExpectCombine<T, 
      typename std::conditional<Traits::hasEquals, ExpectEquals<T>, ExpectEmptyClass>::type
    >;
    class To: public ToBase
    {
    public:
      To(const T& actual, const char* filename, uint32_t lineNumber):
        ToBase(actual, filename, lineNumber),
        be(actual, filename, lineNumber)
      {}

      Be be;
    };
    To to;
  };
}

