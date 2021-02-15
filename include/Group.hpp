#pragma once

#include "Common.hpp"
#include "TestObject.hpp"
#include "HeapObject.hpp"
#include "Scenario.hpp"

namespace CBUnit
{
  class Group: public TestObject
  {
    friend class GroupDeclaration;
    friend class TestRunner;
  private:
    Group(const char* name, RunFunction function, const char* filename, uint32_t lineNumber);

    void run();
  private:
    using HeapScenario = HeapObject<Scenario>;
    using ScenarioList = std::list<HeapScenario>;
    ScenarioList _scenarios;
  };

  class GroupDeclaration
  {
  public:
    GroupDeclaration(const char* name, RunFunction function);
  };
}