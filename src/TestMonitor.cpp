#include "TestMonitor.hpp"

namespace CBUnit
{
  void TestMonitor::beginFixture(Fixture* fixture)
  {
    _objectStack.push({fixture, ObjectType::Fixture});
    (void)fixture;
  }

  void TestMonitor::endFixture(Fixture* fixture)
  {
    (void)fixture;
    _objectStack.pop();
  }

  void TestMonitor::beginGroup(Group* group)
  {
    _objectStack.push({group, ObjectType::Group});
  }

  void TestMonitor::endGroup(Group* group)
  {
    (void)group;
    _objectStack.pop();
    
  }

  void TestMonitor::beginScenario(Scenario* scenario)
  {
    _objectStack.push({scenario, ObjectType::Scenario});
  }

  void TestMonitor::passScenario(Scenario* scenario)
  {
      (void)scenario;
  }

  void TestMonitor::failScenario(Scenario* scenario)
  {
      (void)scenario;
  }

  void TestMonitor::endScenario(Scenario* scenario)
  {
      (void)scenario;
      _objectStack.pop();
  }

  TestMonitor::Object TestMonitor::currentObject() const
  {
    if (_objectStack.empty())
    {
      return {nullptr, ObjectType::None};
    }
    else
    {
      return _objectStack.top();
    }
  }
}