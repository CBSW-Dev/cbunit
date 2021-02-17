#pragma once
#include "ExpectTo.hpp"

#include "Expect/Chains/ExpectEquals.hpp"
#include "Expect/Chains/ExpectGreaterThan.hpp"
#include "Expect/Chains/ExpectGreaterThanOrEqual.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> class ExpectToInteger: public ExpectEquals<T, Logic> 
  {
  public:
    void have() {}
  };

  template <typename T, typename Logic> class ExpectToBeInteger: public ExpectGreaterThan<T, Logic> 
  {
  public:
    void lessThan() {}
  };


  template <typename T, typename Logic> class ExpectToBeAtInteger: public ExpectAtLeast<T, Logic> 
  {
  public:
    void lessThan() {}
  };

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToBeInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToBeAtInteger<T, Logic> {};
}