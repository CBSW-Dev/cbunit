#include "Fixture.hpp"
#include "TestRunner.hpp"
#include "FileInfo.hpp"
#include "LineInfo.hpp"

#include <iostream>

namespace CBUnit
{
  Fixture::Fixture(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, function, filename, lineNumber)
  {}

  void Fixture::run()
  {
    _function();
  }

  FixtureDeclaration::FixtureDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addFixture(new Fixture(name, {}, function, FileInfo::file, LineInfo::line));
  }

  FixtureDeclaration::FixtureDeclaration(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function)
  {
    TestRunner::instance().addFixture(new Fixture(name, attributes, function, FileInfo::file, LineInfo::line));
  }
}