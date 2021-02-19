#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"
#include "Expect/Chains/ExpectEquals.hpp"

namespace CBUnit
{
  namespace
  {
    struct TestExpectationNullText {static constexpr const char* text = "to be null";};
    template <typename T, class Logic> using TestExpectationNullFailure = TestExpectationFailure<T, T, Logic, TestExpectationNullText>; 

    struct TestExpectationValidText {static constexpr const char* text = "to be valid";};
    template <typename T, class Logic> using TestExpectationValidFailure = TestExpectationFailure<T, T, Logic, TestExpectationValidText>; 

    struct TestExpectationAddressText {static constexpr const char* text = "to have address";};
    template <typename T, class Logic> using TestExpectationAddressFailure = TestExpectationFailure<T, T, Logic, TestExpectationAddressText>; 
  }

  template <typename T, typename Logic> class ExpectToBePointer: public virtual ExpectBase<T>
  {
  public:
    void null()
    {
      if (Logic::logic(this->actual() != nullptr))
      {
        throw TestExpectationNullFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }

    void valid()
    {
      if (Logic::logic(this->actual() == nullptr))
      {
        throw TestExpectationValidFailure<T, Logic>(this->actual(), this->filename(), this->lineNumber());
      }
    }
  };

  template <typename T, typename Logic> class ExpectToHavePointer: public virtual ExpectBase<T>
  {
  public:
    void address(std::size_t address)
    {
      if (Logic::logic(reinterpret_cast<std::size_t>(this->actual()) != address))
      {
        throw TestExpectationAddressFailure<T, Logic>(this->actual(), reinterpret_cast<T>(address), this->filename(), this->lineNumber());
      }
    }
  };

  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<ExpectIs<T>::pointer>::type>: public ExpectToBePointer<T, Logic> {};
  template <typename T, typename Logic> class ExpectToHave<T, Logic, typename std::enable_if<ExpectIs<T>::pointer>::type>: public ExpectToHavePointer<T, Logic> {};
}