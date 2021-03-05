#include "TestStructure/AfterEach.hpp"
#include "TestStructure/TestRunner.hpp"
#include "TestStructure/FileInfo.hpp"
#include "TestStructure/LineInfo.hpp"

namespace CBUnit
{
  AfterEach::AfterEach(RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject("", {}, function, filename, lineNumber)
  {}

  void AfterEach::run()
  {
    _function();
  }

  AfterEachDeclaration::AfterEachDeclaration(RunFunction function)
  {
    TestRunner::instance().addAfterEach(new AfterEach(function, FileInfo::file, LineInfo::line));
  }
}