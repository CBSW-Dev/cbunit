#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include "Expect/Chains/ExpectEquals.hpp"


namespace CBUnit
{
  template <typename T, typename Logic> using ExpectToBoolean = ExpectEquals<T, Logic>;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename ExpectEnableIfBoolean<T>::type>: public ExpectToBoolean<T, Logic> {};
}