#include "TestStructure/TestMonitor.hpp"

namespace CBUnit
{
  void TestMonitor::beginFixture(Fixture& fixture)
  {
    _objectStack.push({&fixture, ObjectType::Fixture});
  }

  void TestMonitor::endFixture()
  {
    _objectStack.pop();
  }

  void TestMonitor::beginGroup(Group& group)
  {
    _objectStack.push({&group, ObjectType::Group});
  }

  void TestMonitor::endGroup()
  {
    _objectStack.pop();
  }

  void TestMonitor::beginScenario(Scenario& scenario)
  {
    _objectStack.push({&scenario, ObjectType::Scenario});
  }

  void TestMonitor::endScenario()
  {
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