#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include "Expect/Chains/ExpectComparable.hpp"
#include "Expect/Chains/ExpectWithin.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> using ExpectToFloatingPoint = typename ExpectComparable<T, Logic>::To;
  template <typename T, typename Logic> class ExpectToBeFloatingPoint: public ExpectComparable<T, Logic>::Be
  {
  public:
    ExpectWithin<T,Logic> within(T value)
    {
      return ExpectWithin<T, Logic>(value, this->actual(), this->filename(), this->lineNumber());
    }
  };
  template <typename T, typename Logic> using ExpectToBeAtFloatingPoint = typename ExpectComparable<T, Logic>::At;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToFloatingPoint<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToBeFloatingPoint<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToBeAtFloatingPoint<T, Logic> {};
}