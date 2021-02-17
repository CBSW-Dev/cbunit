#include "TestStructure/TestObject.hpp"

namespace CBUnit
{
  TestObject::TestObject(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    _name(name),
    _attributes(attributes),
    _function(function),
    _filename(filename),
    _lineNumber(lineNumber)
  {}
   
  TestObject::~TestObject() = default;

  const char* TestObject::name() const
  {
    return _name;
  }

  RunFunction TestObject::function() const
  {
    return _function;
  }

  const char* TestObject::filename() const
  {
    return _filename;
  }

  uint32_t TestObject::lineNumber() const
  {
    return _lineNumber;
  }

  bool TestObject::isSkipped() const
  {
    for (auto attribute: _attributes)
    {
      if (attribute == TestAttributes::Skip)
      {
        return true;
      } 
    }
    return false;
  }
}