#pragma once

#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"

namespace CBUnit
{
  class TestMonitor
  {
  public:
    void beginFixture(Fixture& fixture);
    void endFixture();
    void beginGroup(Group& group);
    void endGroup();
    void beginScenario(Scenario& scenario);
    void endScenario();

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