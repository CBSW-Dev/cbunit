#include "Fixture.hpp"
#include "TestRunner.hpp"
#include "FileInfo.hpp"
#include "LineInfo.hpp"

#include <iostream>

namespace CBUnit
{
  Fixture::Fixture(const char* name, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, function, filename, lineNumber)
  {}

  void Fixture::run()
  {
    std::cout << "Running Fixture: " << _name << std::endl;
    _function();
  }

  FixtureDeclaration::FixtureDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addFixture(new Fixture(name, function, FileInfo::file, LineInfo::line));
  }
}