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
  
  template <typename T> class ExpectRoot<T, typename std::enable_if<ExpectIs<T>::sequence>::type>
  {
  public:
    using Type = const T&;
    ExpectRoot(Type actual, const char* filename, uint32_t lineNumber):
      _length(actual.size()),
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber),
      size(sizeof(actual), filename, lineNumber),
      length(_length, filename, lineNumber)
    {}
  private:
    typename T::size_type _length;
  public:
    class Not
    {
    public:
      Not(Type actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      ExpectBaseMixin<Type, ExpectToBase<Type, ExpectInvertingLogic>> to;
    };

    Not not;
    ExpectBaseMixin<Type, ExpectToBase<Type, ExpectLogic>> to;
    ExpectSize size;
    ExpectRoot<typename T::size_type> length;
  };

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::sequence>::type>: public ExpectToSequence<T, Logic> {};
}