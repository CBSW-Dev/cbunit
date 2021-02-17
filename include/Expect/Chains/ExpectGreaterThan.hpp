#pragma once
#include "ExpectBase.hpp"

#include <iostream>

namespace CBUnit
{
  template <class T>
  class ExpectGreaterThan: public virtual ExpectBase<T>
  {
  public:
    void greaterThan(const T& expected) const
    {
      if (*this->_actual <= expected)
      {
        std::cout << "Not Greater Than" <<std::endl;
      }
      else
      {
        std::cout << "Greater Than" <<std::endl;
      }
    }

    //aliases
    void above(const T& expected) {greaterThan(expected);}
    void gt(const T& expected) const {greaterThan(expected);}
  };
}
