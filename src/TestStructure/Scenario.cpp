#include "TestStructure/Scenario.hpp"
#include "TestStructure/TestRunner.hpp"

namespace CBUnit
{
  Scenario::Scenario(Fixture* fixture, const char* name, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, {}, filename, lineNumber),
    _function(function)
  {
    fixture->scenarios().push_back(this);
  }

  Scenario::Scenario(Fixture* fixture, const char* name, TestAttributes attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, {attributes}, filename, lineNumber),
    _function(function)
  {
    fixture->scenarios().push_back(this);
  }

  Scenario::Scenario(Fixture* fixture, const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, filename, lineNumber),
    _function(function)
  {
    fixture->scenarios().push_back(this);
  }

  void Scenario::run()
  {
    TestRunner::instance().runScenario(this, _function);
  }
}