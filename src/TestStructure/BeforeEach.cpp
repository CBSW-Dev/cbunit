#include "TestStructure/BeforeEach.hpp"
#include "TestStructure/TestRunner.hpp"

namespace CBUnit
{
  BeforeEach::BeforeEach(RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject("", {}, filename, lineNumber),
    _function(function)
  {}

  void BeforeEach::run()
  {
    _function();
  }
}