#pragma once

#include "Common.hpp"
#include "TestObject.hpp"
#include "HeapObject.hpp"
#include "Group.hpp"
#include "Scenario.hpp"

namespace CBUnit
{
  class Fixture: public TestObject
  {
    friend class FixtureDeclaration;
    friend class TestRunner;
  private:
    Fixture(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber);

    void run();
  private:
    using HeapGroup = HeapObject<Group>;
    using GroupList = std::list<HeapGroup>;
    GroupList _groups;

    using HeapScenario = HeapObject<Scenario>;
    using ScenarioList = std::list<HeapScenario>;
    ScenarioList _scenarios;

    using GroupStack = std::stack<Group*>;
    GroupStack _groupStack;
  };

  class FixtureDeclaration
  {
  public:
    FixtureDeclaration(const char* name, RunFunction function);
    FixtureDeclaration(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function);
  };
}