#pragma once
#include "ExpectTo.hpp"

#include "Expect/Chains/ExpectEquals.hpp"
#include "Expect/Chains/ExpectGreaterThan.hpp"
#include "Expect/Chains/ExpectGreaterThanOrEqual.hpp"
#include "Expect/Chains/ExpectLessThan.hpp"
#include "Expect/Chains/ExpectLessThanOrEqual.hpp"

namespace CBUnit
{
  template <typename T, typename Logic> class ExpectToInteger: public ExpectEquals<T, Logic> 
  {
  public:
    
  };

  template <typename T, typename Logic> class ExpectToBeInteger: 
    public ExpectGreaterThan<T, Logic>,
    public ExpectGreaterThanOrEqual<T, Logic>,
    public ExpectLessThan<T, Logic>,
    public ExpectLessThanOrEqual<T, Logic> 
  {};


  template <typename T, typename Logic> class ExpectToBeAtInteger: 
    public ExpectAtLeast<T, Logic>,
    public ExpectAtMost<T, Logic> 
  {};

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBe<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToBeInteger<T, Logic> {};
  template <typename T, typename Logic> class ExpectToBeAt<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToBeAtInteger<T, Logic> {};
}