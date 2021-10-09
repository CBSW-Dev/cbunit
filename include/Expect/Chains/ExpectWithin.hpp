#pragma once
#include "ExpectBase.hpp"
#include "ExpectLogic.hpp"
#include "Expect/Error/TestExpectationFailure.hpp"
#include "TestStructure/TestError.hpp"

#include <sstream>

namespace CBUnit
{
  namespace
  {
    template <class T> std::string buildWithinMessage(T delta)
    {
      std::stringstream ss;
      ss << "to be within ";
      ss << delta;
      ss << " of";
      return ss.str();
    }
    template <class T, class Logic> class TestExpectationWithinFailure: public TestExpectationFailure<T, T, Logic>
    {
    public:
      TestExpectationWithinFailure(typename ExpectBase<T>::Type actual, typename ExpectBase<T>::Type expected, typename ExpectBase<T>::Type delta, const char* filename, uint32_t lineNumber):
        TestExpectationFailure<T, T, Logic>(actual, expected, buildWithinMessage(delta), filename, lineNumber)
      {}
    };
  }

  template <class T, class Logic = ExpectLogic>
  class ExpectWithin: public ExpectBaseMixin<T>
  {
  public:
    ExpectWithin(typename ExpectBase<T>::Type delta, typename ExpectBase<T>::Type actual, const char* filename, uint32_t lineNumber):
      ExpectBaseMixin<T>(actual, filename, lineNumber),
      _delta(delta)
    {}

    void of(typename ExpectBase<T>::Type expected) const
    {
      auto min = expected - _delta;
      auto max = expected + _delta;
      if (Logic::logic((this->actual() < min) || (this->actual() > max)))
      {
        throw TestExpectationWithinFailure<T, Logic>(this->actual(), expected, _delta, this->filename(), this->lineNumber());
      }
    }
  private:
    typename ExpectBase<T>::Type _delta;
  };
}
