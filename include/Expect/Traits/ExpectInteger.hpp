#pragma once
#include "ExpectTo.hpp"

#include "Expect/Chains/ExpectComparable.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> using ExpectToInteger = typename ExpectComparable<T, Logic>::To;
  template <typename T, typename Logic> using ExpectToBeInteger = typename ExpectComparable<T, Logic>::Be;
  template <typename T, typename Logic> using ExpectToBeAtInteger = typename ExpectComparable<T, Logic>::At;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::integer>::type>: public ExpectToInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<ExpectIs<T>::integer>::type>: public ExpectToBeInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<ExpectIs<T>::integer>::type>: public ExpectToBeAtInteger<T, Logic> {};
}