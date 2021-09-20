#include "TestStructure/Fixture.hpp"
#include "TestStructure/TestRunner.hpp"
namespace CBUnit
{
  Fixture::Fixture(const char* name, ScenarioList& scenarios, BeforeEach* beforeEach, AfterEach* afterEach, const char* filename, uint32_t lineNumber):
    TestObject(name, {}, filename, lineNumber),
    _scenarios(&scenarios),
    _beforeEach(beforeEach),
    _afterEach(afterEach)
  {
    TestRunner::instance().addFixture(this);
  }

  Fixture::Fixture(const char* name, std::initializer_list<TestAttributes> attributes, ScenarioList& scenarios, BeforeEach* beforeEach, AfterEach* afterEach, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, filename, lineNumber),
    _scenarios(&scenarios),
    _beforeEach(beforeEach),
    _afterEach(afterEach)
  {
    TestRunner::instance().addFixture(this);
  }

  void Fixture::run()
  {
    for (auto scenario: *_scenarios)
    {
      if (_beforeEach)
      {
        _beforeEach->run();
      }
      scenario->run();
      if (_afterEach)
      {
        _afterEach->run();
      }
    }
  }

  Fixture::ScenarioList& Fixture::scenarios()
  {
    return *_scenarios;
  }

}