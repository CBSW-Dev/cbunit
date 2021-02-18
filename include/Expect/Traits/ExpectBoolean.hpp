#pragma once
#include "ExpectTo.hpp"

#include "Expect/Chains/ExpectEquals.hpp"
#include "ExpectIs.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> using ExpectToBoolean = ExpectEquals<T, Logic>;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::boolean>::type>: public ExpectToBoolean<T, Logic> {};
}