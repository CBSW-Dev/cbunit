#pragma once
#include "ExpectTo.hpp"
#include "Expect/Chains/ExpectBase.hpp"
namespace CBUnit
{
  template <typename T, typename Logic> class ExpectToInteger: public ExpectEquals<T, Logic> 
  {
  public:
    void have() {}
  };

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<std::is_integral<T>::value>::type>: public ExpectToInteger<T, Logic> {};
  // template <typename Logic> class ExpectTo<int, Logic>: public ExpectToInteger<int, Logic> {};
  // template <typename Logic> class ExpectTo<long, Logic>: public ExpectToInteger<int, Logic> {};
  // template <typename Logic> class ExpectTo<int, Logic>: public ExpectToInteger<int, Logic> {};
  // template <typename Logic> class ExpectTo<int, Logic>: public ExpectToInteger<int, Logic> {};
  // template <typename Logic> class ExpectTo<int, Logic>: public ExpectToInteger<int, Logic> {};
  // template <typename Logic> class ExpectTo<int, Logic>: public ExpectToInteger<int, Logic> {};
}