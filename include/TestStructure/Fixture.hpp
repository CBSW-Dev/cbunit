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
    Fixture(const char* name, ScenarioList& scenarios, BeforeEach* beforeEach, AfterEach* afterEach, const char* filename, uint32_t lineNumber);
    Fixture(const char* name, std::initializer_list<TestAttributes> attributes, ScenarioList& scenarios, BeforeEach* beforeEach, AfterEach* afterEach, const char* filename, uint32_t lineNumber);

    void run() override;
    ScenarioList& scenarios();
  private:
    ScenarioList* _scenarios;
    BeforeEach* _beforeEach;
    AfterEach* _afterEach;
  };
}