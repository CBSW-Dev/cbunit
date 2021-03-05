#pragma once

#include "Common.hpp"
#include "TestObjectContainer.hpp"
#include "HeapObject.hpp"
#include "Scenario.hpp"

namespace CBUnit
{
  class Group: public TestObjectContainer
  {
    friend class GroupDeclaration;
    friend class TestRunner;
  private:
    Group(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function, const char* filename, uint32_t lineNumber);

    void run() override;
  private:
    using HeapScenario = HeapObject<Scenario>;
    using ScenarioList = std::list<HeapScenario>;
    ScenarioList _scenarios;
  };

  class GroupDeclaration
  {
  public:
    GroupDeclaration(const char* name, RunFunction function);
    GroupDeclaration(const char* name, std::initializer_list<TestAttributes> attributes, RunFunction function);
    
  };
}