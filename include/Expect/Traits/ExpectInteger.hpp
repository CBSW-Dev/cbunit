#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include "Expect/Chains/ExpectComparable.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> using ExpectToInteger = typename ExpectComparable<T, Logic>::To;
  template <typename T, typename Logic> using ExpectToBeInteger = typename ExpectComparable<T, Logic>::Be;
  template <typename T, typename Logic> using ExpectToBeAtInteger = typename ExpectComparable<T, Logic>::At;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::integer>::type>: public ExpectToInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<ExpectIs<T>::integer>::type>: public ExpectToBeInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<ExpectIs<T>::integer>::type>: public ExpectToBeAtInteger<T, Logic> {};

  template <typename T> class ExpectRoot<T, typename std::enable_if<ExpectIs<T>::integer>::type>
  {
  public:
    using Type = typename std::conditional<std::is_scalar<T>::value, T, const T&>::type;
    ExpectRoot(Type actual, const char* filename, uint32_t lineNumber):
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber),
      size(sizeof(actual), filename, lineNumber)
    {}
     
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
  };
}