#pragma once
#include "ExpectTraitsSelect.hpp"
#include "ExpectIntegerTraits.hpp"
#include "ExpectCombine.hpp"
#include "ExpectEmptyClass.hpp"
#include "Expect/Chains/ExpectEquals.hpp"
#include "Expect/Chains/ExpectGreaterThan.hpp"
#include "Expect/Chains/ExpectGreaterThanOrEqual.hpp"
#include "Expect/Chains/ExpectLessThan.hpp"
#include "Expect/Chains/ExpectLessThanOrEqual.hpp"

namespace CBUnit
{
  template <bool Value, typename T> class ExpectConditional
  {
  public:
    using Type = typename std::conditional<Value, T, ExpectEmptyClass<T>>::type;
  };

  template <typename T, typename Traits = typename ExpectTraitsSelect<T>::Type> class ExpectBuilder
  {
  public:
    ExpectBuilder(const T& actual, const char* filename, uint32_t lineNumber):
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber)
    {}

    template <class Logic> using BeAt = ExpectCombine<T, 
      typename ExpectConditional<Traits::hasGreaterThanOrEqual, ExpectAtLeast<T, Logic>>::Type,
      typename ExpectConditional<Traits::hasLessThanOrEqual, ExpectAtMost<T, Logic>>::Type

    >;

    template <class Logic> using BeBase = ExpectCombine<T, 
      typename ExpectConditional<Traits::hasGreaterThan, ExpectGreaterThan<T, Logic>>::Type,
      typename ExpectConditional<Traits::hasGreaterThanOrEqual, ExpectGreaterThanOrEqual<T, Logic>>::Type,
      typename ExpectConditional<Traits::hasLessThan, ExpectLessThan<T, Logic>>::Type,
      typename ExpectConditional<Traits::hasLessThanOrEqual, ExpectLessThanOrEqual<T, Logic>>::Type
    >;

    template <class Logic> class Be: public BeBase<Logic>
    {
    public:
      Be(const T& actual, const char* filename, uint32_t lineNumber):
        BeBase<Logic>(actual, filename, lineNumber),
        at(actual, filename, lineNumber)
      {}

      BeAt<Logic> at;
    };

    
    template <class Logic> using ToBase = ExpectCombine<T, 
      typename ExpectConditional<Traits::hasEquals, ExpectEquals<T, Logic>>::Type
    >;

    template <class Logic>
    class To: public ToBase<Logic>
    {
    public:
      To(const T& actual, const char* filename, uint32_t lineNumber):
        ToBase<Logic>(actual, filename, lineNumber),
        be(actual, filename, lineNumber)
      {}

      Be<Logic> be;
    };

    class Not
    {
    public:
      Not(const T& actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      To<ExpectInvertingLogic> to;
    };

    Not not;
    To<ExpectLogic> to;
  };
}

