#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include "Expect/Chains/ExpectComparable.hpp"
#include "Expect/Chains/ExpectWithin.hpp"

#include "Expect/Error/TestExpectationFailure.hpp"

#include <cmath>

namespace CBUnit
{
  namespace
  {
    struct TestExpectationNaNText {static constexpr const char* text = "to be NaN";};
    template <typename T, class Logic> using TestExpectationNaNFailure = TestExpectationFailure<T, T, Logic, TestExpectationNaNText>; 

    struct TestExpectationInfiniteText {static constexpr const char* text = "to be infinite";};
    template <typename T, class Logic> using TestExpectationInfiniteFailure = TestExpectationFailure<T, T, Logic, TestExpectationInfiniteText>;

    struct TestExpectationFiniteText {static constexpr const char* text = "to be finite";};
    template <typename T, class Logic> using TestExpectationFiniteFailure = TestExpectationFailure<T, T, Logic, TestExpectationFiniteText>;
  }

  template <typename T, typename Logic> using ExpectToFloatingPoint = typename ExpectComparable<T, Logic>::To;
  template <typename T, typename Logic> class ExpectToBeFloatingPoint: public ExpectComparable<T, Logic>::Be
  {
  public:
    ExpectWithin<T,Logic> within(T value)
    {
      return ExpectWithin<T, Logic>(value, this->actual(), this->filename(), this->lineNumber());
    }

    void infinite()
    {
      if (Logic::logic(!std::isinf(this->actual())))
      {
        throw TestExpectationInfiniteFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }

    void finite()
    {
      if (Logic::logic(std::isinf(this->actual())))
      {
        throw TestExpectationFiniteFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }

    void NaN()
    {
      if (Logic::logic(!std::isnan(this->actual())))
      {
        throw TestExpectationNaNFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }
  };
  template <typename T, typename Logic> using ExpectToBeAtFloatingPoint = typename ExpectComparable<T, Logic>::At;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToFloatingPoint<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToBeFloatingPoint<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<std::is_floating_point<T>::value>::type>: public ExpectToBeAtFloatingPoint<T, Logic> {};
}