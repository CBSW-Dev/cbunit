#include "TestStructure/Fixture.hpp"
#include "TestStructure/TestRunner.hpp"
#include <iostream>

namespace CBUnit
{
  Fixture* Fixture::instance = nullptr;

  Fixture::Fixture(const char* name, const char* filename, uint32_t lineNumber):
    TestObject(name, {}, filename, lineNumber),
    _beforeEach(nullptr),
    _afterEach(nullptr)
  {
    TestRunner::instance().addFixture(this);
  }

  Fixture::Fixture(const char* name, std::initializer_list<TestAttributes> attributes, const char* filename, uint32_t lineNumber):
    TestObject(name, attributes, filename, lineNumber),
    _beforeEach(nullptr),
    _afterEach(nullptr)
  {
    TestRunner::instance().addFixture(this);
  }

  void Fixture::run()
  {
    for (auto scenario: _scenarios)
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
    return _scenarios;
  }

  FixtureDeclaration::FixtureDeclaration(Fixture* src)
  {
    Fixture::instance = src;
  }
}