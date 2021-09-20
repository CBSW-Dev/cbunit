#pragma once

#include "Common.hpp"
#include "TestAttributes.hpp"

namespace CBUnit
{
  class TestObject
  {
  protected:
    TestObject(const char* name, std::initializer_list<TestAttributes> attributes, const char* filename, uint32_t lineNumber);
  public:
    virtual ~TestObject();

    const char* name() const;
    const char* filename() const;
    uint32_t lineNumber() const;

    bool isSkipped() const;

    virtual void run() = 0;
  protected:
    const char* _name;
    std::list<TestAttributes> _attributes;
    const char* _filename;
    uint32_t _lineNumber;
  };
}