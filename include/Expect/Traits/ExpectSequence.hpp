#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include "Expect/Chains/ExpectEquals.hpp"

#include "Expect/Error/TestExpectationFailure.hpp"

#include <algorithm>

namespace CBUnit
{
 namespace
  {
    struct TestExpectationSequenceContainText {static constexpr const char* text = "to contain";};
    template <typename T, class U, class Logic> using TestExpectationSequenceContainFailure = TestExpectationFailure<T, U, Logic, TestExpectationSequenceContainText>; 
  }

  template <typename T, typename Logic> class ExpectToSequence: public ExpectEquals<T, Logic>
  {
  public:
    using value_type = typename std::remove_reference<T>::type::value_type;
    void contain(value_type value)
    {
      if (Logic::logic(std::find(this->actual().begin(), this->actual().end(), value) == this->actual().end()))
      {
        throw TestExpectationSequenceContainFailure<T, value_type, Logic>(this->actual(), value, this->filename(), this->lineNumber());
      }
    }
  };
  
  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::sequence>::type>: public ExpectToSequence<T, Logic> {};
}