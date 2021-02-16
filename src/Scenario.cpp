#include "Scenario.hpp"
#include "TestRunner.hpp"
#include "FileInfo.hpp"
#include "LineInfo.hpp"

#include <iostream>

namespace CBUnit
{
  Scenario::Scenario(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, function, filename, lineNumber)
  {}

  void Scenario::run()
  {
    _function();
  }

  ScenarioDeclaration::ScenarioDeclaration(const char* name, RunFunction function)
  {
    TestRunner::instance().addScenario(new Scenario(name, {}, function, FileInfo::file, LineInfo::line));
  }

  ScenarioDeclaration::ScenarioDeclaration(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function)
  {
    TestRunner::instance().addScenario(new Scenario(name, attributes, function, FileInfo::file, LineInfo::line));
  }
}