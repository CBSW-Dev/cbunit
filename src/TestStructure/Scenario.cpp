#include "TestStructure/Scenario.hpp"
#include "TestStructure/TestRunner.hpp"
#include "TestStructure/FileInfo.hpp"
#include "TestStructure/LineInfo.hpp"

namespace CBUnit
{
  Scenario::Scenario(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, function, filename, lineNumber)
  {}

  void Scenario::run()
  {
    TestRunner::instance().runScenario(this, _function);
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