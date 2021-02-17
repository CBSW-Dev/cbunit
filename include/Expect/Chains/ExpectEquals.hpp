#pragma once
#include "ExpectBase.hpp"

#include <iostream>

namespace CBUnit
{
  template <class T>
  class ExpectEquals: public virtual ExpectBase<T>
  {
  public:
    void equal(const T& expected) const
    {
      if (*this->_actual != expected)
      {
        std::cout << "Not Equal" <<std::endl;
      }
      else
      {
        std::cout << "Equal" <<std::endl;
      }
    }
  };
}
