#include "TestRunner.hpp"
#include "TestStructureError.hpp"

namespace CBUnit
{
  TestRunner* TestRunner::_instance = nullptr;

  TestRunner::TestRunner():
    _reporter(_ostream),
    _deferredTestStructureError("", "", 0)
  {}

  void TestRunner::addFixture(Fixture* fixture)
  {
     TestMonitor::Object object = _testMonitor.currentObject();
    switch (object.type)
    {
    case TestMonitor::ObjectType::Fixture:
      throw TestStructureError("Fixtures cannot be nested", fixture->filename(), fixture->lineNumber());
      break;
    case TestMonitor::ObjectType::Group:
      throw TestStructureError("Fixture cannot be added to a group", fixture->filename(), fixture->lineNumber());
      break;
    case TestMonitor::ObjectType::None:
      _fixtures.push_back(HeapFixture(fixture));
      break;
    case TestMonitor::ObjectType::Scenario:
      throw TestStructureError("Fixture cannot be added within a scenario", fixture->filename(), fixture->lineNumber());
      break;
    }
  }

  void TestRunner::addGroup(Group* group)
  {
    TestMonitor::Object object = _testMonitor.currentObject();
    switch (object.type)
    {
    case TestMonitor::ObjectType::Fixture:
    case TestMonitor::ObjectType::Group:
      _testMonitor.beginGroup(*group);
      _reporter.beginGroup(*group);
      group->run();
      _reporter.endGroup(*group);
      _testMonitor.endGroup();
      delete group;
      break;
    case TestMonitor::ObjectType::None:
      _deferredTestStructureError = TestStructureError("Group cannot be added to the global scope", group->filename(), group->lineNumber());
      break;
    case TestMonitor::ObjectType::Scenario:
      throw TestStructureError("Group cannot be added within a scenario", group->filename(), group->lineNumber());
      break;
    }
  }

  void TestRunner::addScenario(Scenario* scenario)
  { 
    TestMonitor::Object object = _testMonitor.currentObject();
    switch (object.type)
    {
    case TestMonitor::ObjectType::Fixture:
    case TestMonitor::ObjectType::Group:
      _testMonitor.beginScenario(*scenario);
      _reporter.beginScenario(*scenario);
      scenario->run();
      _reporter.passScenario(*scenario);
      _statistics.passTest();
      _testMonitor.endScenario();
      delete scenario;
      break;
    case TestMonitor::ObjectType::None:
      _deferredTestStructureError = TestStructureError("Scenario cannot be added to the global scope", scenario->filename(), scenario->lineNumber());
      break;
    case TestMonitor::ObjectType::Scenario:
      throw TestStructureError("Scenario cannot be added within another scenario", scenario->filename(), scenario->lineNumber());
      break;
    }
  }

  int TestRunner::run()
  {
    _reporter.begin();
    _statistics.begin();
    if (_deferredTestStructureError.message() != "")
    {
      throw _deferredTestStructureError;
    }
    using FixtureListIterator = std::move_iterator<FixtureList::iterator>;
    
    for (FixtureListIterator it = std::make_move_iterator(_fixtures.begin()), end = std::make_move_iterator(_fixtures.end()); it != end; ++it)
    {
      Fixture* fixture = *it;
      _testMonitor.beginFixture(*fixture);
      _reporter.beginFixture(*fixture);
      (*it)->run();
      _reporter.endFixture(*fixture);
      _testMonitor.endFixture();
    }
    _statistics.end();
    _reporter.end(_statistics);
    return 0;
  }

  TestRunner& TestRunner::instance()
  {
    if (_instance == nullptr)
    {
      _instance = new TestRunner;
    }
    return *_instance;
  }
}