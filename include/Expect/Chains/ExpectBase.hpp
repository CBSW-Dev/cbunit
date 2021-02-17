#pragma once

namespace CBUnit
{
  template <class T>
  class ExpectBase
  {
  protected:
    virtual const T& actual() const = 0;
    virtual const char* filename() const = 0;
    virtual uint32_t lineNumber() const = 0;
  };
}