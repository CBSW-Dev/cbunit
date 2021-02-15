#pragma once

#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"

namespace CBUnit
{
  class TestMonitor
  {
  public:
    void beginFixture(Fixture* fixture);
    void endFixture(Fixture* fixture);
    void beginGroup(Group* group);
    void endGroup(Group* group);
    void beginScenario(Scenario* scenario);
    void passScenario(Scenario* scenario);
    void failScenario(Scenario* scenario);
    void endScenario(Scenario* scenario);

    enum class ObjectType
    {
      None,
      Fixture,
      Group,
      Scenario
    };

    struct Object
    {
      TestObject* object;
      ObjectType type;
    };

    Object currentObject() const;
  private:
    using ObjectStack = std::stack<Object>;
    ObjectStack _objectStack;
  };
}