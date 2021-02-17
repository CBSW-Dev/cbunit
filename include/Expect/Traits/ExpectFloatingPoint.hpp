#pragma once
#include "ExpectTo.hpp"

#include "Expect/Chains/ExpectComparable.hpp"
#include "Expect/Chains/ExpectWithin.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> using ExpectToFloatingPoint = typename ExpectComparable<T, Logic>::To;
  template <typename T, typename Logic> class ExpectToBeFloatingPoint: public ExpectComparable<T, Logic>::Be
  {
  public:
    ExpectWithin<T,Logic> within(const T& value)
    {
      return ExpectWithin<T, Logic>(value, this->actual(), this->filename(), this->lineNumber());
    }
  };

  // template <typename T, typename Logic> class ExpectToBase: public ExpectTo<T, Logic>
  // {
  // public:
  //   ExpectToBase(const T& actual, const char* filename, uint32_t lineNumber):
  //     be(actual, filename, lineNumber)
  //   {}

  //   ExpectBaseMixin<T, ExpectToBeBase<T, Logic>> be;
  // };

  template <typename T, typename Logic> using ExpectToBeAtFloatingPoint = typename ExpectComparable<T, Logic>::At;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToFloatingPoint<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToBeFloatingPoint<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToBeAtFloatingPoint<T, Logic> {};
}