#pragma once

#include "Common.hpp"

namespace CBUnit
{
  class TestObject
  {
  protected:
    TestObject(const char* name, RunFunction function, const char* filename, uint32_t lineNumber);
    virtual ~TestObject();
  public:
    const char* name() const;
    RunFunction function() const;
    const char* filename() const;
    uint32_t lineNumber() const;
  protected:
    const char* _name;
    RunFunction _function;
    const char* _filename;
    uint32_t _lineNumber;
  };
}