#pragma once
#include "TestExpectationFailure.hpp"
#include "ExpectSelect.hpp"

#include <type_traits>
#include <iostream>

namespace CBUnit
{
  class ExpectEmptyClass {};

  template <class T>
  class ExpectBase
  {
  protected:
    ExpectBase() {}

    ExpectBase(const T& actual, const char* filename, uint32_t lineNumber):
      _actual(&actual),
      _filename(filename),
      _lineNumber(lineNumber)
    {}

    const T* _actual;
    const char* _filename;
    uint32_t _lineNumber;
  };

  template <class T>
  class ExpectGreaterThan: public virtual ExpectBase<T>
  {
  public:
    void beGreaterThan(const T& expected) const
    {
      if (*this->_actual <= expected)
      {
        std::cout << "Less Than or Equal" <<std::endl;
      }
      else
      {
        std::cout << "GrreaterThan" <<std::endl;
      }
    }
  };

  template <class T, class ...Classes> class ExpectCombine: public virtual ExpectBase<T>, public Classes...
  {
  public:
    ExpectCombine(const T& actual, const char* filename, uint32_t lineNumber):
      ExpectBase<T>(actual, filename, lineNumber)
    {}
  };

  template <class T, class Traits>
  class ExpectBuilder
  {
  public:
    ExpectBuilder(const T& actual, const char* filename, uint32_t lineNumber):
      to(actual, filename, lineNumber)
    {}

    using To = ExpectCombine<T, 
      typename std::conditional<Traits::hasEquals, ExpectEquals<T>, ExpectEmptyClass>::type,
      typename std::conditional<Traits::hasGreaterThan, ExpectGreaterThan<T>, ExpectEmptyClass>::type
    >;
    To to;
  };

  

  template <class T> class ExpectIntegral
  {
  public:
    static constexpr bool hasEquals = true;
    static constexpr bool hasGreaterThan = true;
  };
}
