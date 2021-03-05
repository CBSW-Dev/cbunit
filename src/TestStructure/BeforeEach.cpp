#include "TestStructure/BeforeEach.hpp"
#include "TestStructure/TestRunner.hpp"
#include "TestStructure/FileInfo.hpp"
#include "TestStructure/LineInfo.hpp"

namespace CBUnit
{
  BeforeEach::BeforeEach(RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject("", {}, function, filename, lineNumber)
  {}

  void BeforeEach::run()
  {
    _function();
  }

  BeforeEachDeclaration::BeforeEachDeclaration(RunFunction function)
  {
    TestRunner::instance().addBeforeEach(new BeforeEach(function, FileInfo::file, LineInfo::line));
  }
}