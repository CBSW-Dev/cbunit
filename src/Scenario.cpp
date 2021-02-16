#include "Scenario.hpp"
#include "TestRunner.hpp"
#include "FileInfo.hpp"
#include "LineInfo.hpp"

#include <iostream>

namespace CBUnit
{
  Scenario::Scenario(const char* name, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, function, filename, lineNumber)
  {}

  void Scenario::run()
  {
    _function();
  }

  ScenarioDeclaration::ScenarioDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addScenario(new Scenario(name, function, FileInfo::file, LineInfo::line));
  }
}