#pragma once

#include "Common.hpp"
#include "TestObjectContainer.hpp"
#include "HeapObject.hpp"
#include "Group.hpp"
#include "Scenario.hpp"
#include "BeforeEach.hpp"

namespace CBUnit
{
  class Fixture: public TestObjectContainer
  {
    friend class FixtureDeclaration;
    friend class TestRunner;
  private:
    Fixture(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber);

    void run() override;
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