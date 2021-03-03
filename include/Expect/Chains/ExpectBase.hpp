#pragma once

#include "Utility/Unused.hpp"

namespace CBUnit
{
  template <typename T>
  class ExpectBase
  {
  protected:
    using Type = typename std::conditional<std::is_scalar<T>::value, T, const T&>::type;

    virtual Type actual() const = 0;
    virtual const char* filename() const = 0;
    virtual uint32_t lineNumber() const = 0;
  };

  template <typename T> class ExpectEmptyBaseClass 
  {
  public:
    ExpectEmptyBaseClass(T actual, const char* filename, uint32_t lineNumber) 
    {
      ::CBUnit::unused(actual, filename, lineNumber);
    }
  };

  template <typename T, typename Class = ExpectEmptyBaseClass<T>>
  class ExpectBaseMixin: public virtual ExpectBase<T>, public Class
  {
  public:
    ExpectBaseMixin(typename ExpectBase<T>::Type actual, const char* filename, uint32_t lineNumber):
      Class(actual, filename, lineNumber),
      _actual(actual),
      _filename(filename),
      _lineNumber(lineNumber)
    {}

    typename ExpectBase<T>::Type actual() const override
    {
      return _actual;
    }
    const char* filename() const override
    {
      return _filename;
    }
    
    uint32_t lineNumber() const override
    {
      return _lineNumber;
    }
  private:
    T _actual;
    const char* _filename;
    uint32_t _lineNumber;
  };
}