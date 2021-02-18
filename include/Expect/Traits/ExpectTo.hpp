#pragma once
#include "Expect/Chains/ExpectLogic.hpp"
#include "Expect/Chains/ExpectEquals.hpp"
#include "ExpectToBe.hpp"
#include "ExpectToHave.hpp"

namespace CBUnit
{
    //default ExpectTo has equals operator and nothing else
  template <typename T, typename Logic, typename Enabler = void> class ExpectTo: public ExpectEquals<T, Logic> {};

  template <typename T, typename Logic> class ExpectToBase: public ExpectTo<T, Logic>
  {
  public:
    ExpectToBase(const T& actual, const char* filename, uint32_t lineNumber):
      be(actual, filename, lineNumber),
      have(actual, filename, lineNumber)
    {}

    ExpectBaseMixin<T, ExpectToBeBase<T, Logic>> be;
    ExpectBaseMixin<T, ExpectToHaveBase<T, Logic>> have;
  };
}

