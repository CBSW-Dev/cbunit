#pragma once

namespace CBUnit
{
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
}