#pragma once

namespace CBUnit
{
  template <typename T>
  class ExpectBase
  {
  protected:
    virtual T actual() const = 0;
    virtual const char* filename() const = 0;
    virtual uint32_t lineNumber() const = 0;
  };

  template <typename T> class ExpectEmptyBaseClass 
  {
  public:
    ExpectEmptyBaseClass(T actual, const char* filename, uint32_t lineNumber) {}
  };

  template <typename T, typename Class = ExpectEmptyBaseClass<T>>
  class ExpectBaseMixin: public virtual ExpectBase<T>, public Class
  {
  public:
    ExpectBaseMixin(T actual, const char* filename, uint32_t lineNumber):
      Class(actual, filename, lineNumber),
      _actual(actual),
      _filename(filename),
      _lineNumber(lineNumber)
    {}

    T actual() const override
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