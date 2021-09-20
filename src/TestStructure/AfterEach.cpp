#include "TestStructure/AfterEach.hpp"
#include "TestStructure/TestRunner.hpp"
#include "TestStructure/Fixture.hpp"

namespace CBUnit
{
  AfterEach::AfterEach(RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject("", {}, filename, lineNumber),
    _function(function)
  {}

  void AfterEach::run()
  {
    _function();
  }

  AfterEachDeclaration::AfterEachDeclaration(AfterEach* src)
  {
    Fixture::instance->_afterEach = src;
  }
}