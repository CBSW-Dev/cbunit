#pragma once

#include "Common.hpp"
#include "TestObject.hpp"
#include "Scenario.hpp"
#include "BeforeEach.hpp"
#include "AfterEach.hpp"

namespace CBUnit
{
  

  class Fixture: public TestObject
  {
    friend class FixtureDeclaration;
    friend class TestRunner;
  public:
    using ScenarioList = std::list<Scenario*>;
    Fixture(const char* name, const char* filename, uint32_t lineNumber);
    Fixture(const char* name, std::initializer_list<TestAttributes> attributes, const char* filename, uint32_t lineNumber);

    void run() override;
    ScenarioList& scenarios();

    static Fixture* instance;

    BeforeEach* _beforeEach;
    AfterEach* _afterEach;
  private:
    ScenarioList _scenarios;
  };

  class FixtureDeclaration
  {
  public:
    FixtureDeclaration(Fixture* src);
  };
}