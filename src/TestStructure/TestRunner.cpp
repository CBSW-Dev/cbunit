#include "TestStructure/TestRunner.hpp"
#include "TestStructure/TestError.hpp"
#include "TestStructure/TestStructureError.hpp"

namespace CBUnit
{
  TestRunner* TestRunner::_instance = nullptr;

  TestRunner::TestRunner():
    _reporter(nullptr),
    _deferredTestStructureError("", "", 0)
  {}

  void TestRunner::setReporter(TestReporter& reporter)
  {
    _reporter = &reporter;
  }
  
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
      runGroup(group);
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
      runScenario(scenario);
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
    begin();
    using FixtureListIterator = std::move_iterator<FixtureList::iterator>;
    
    for (FixtureListIterator it = std::make_move_iterator(_fixtures.begin()), end = std::make_move_iterator(_fixtures.end()); it != end; ++it)
    {
      runFixture(*it);
    }
    end();
    return (_statistics.failureCount() == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  }

  TestRunner& TestRunner::instance()
  {
    if (_instance == nullptr)
    {
      _instance = new TestRunner;
    }
    return *_instance;
  }

  void TestRunner::begin()
  {
    _reporter->begin();
    _statistics.begin();
    if (_deferredTestStructureError.message() != "")
    {
      throw _deferredTestStructureError;
    }
  }

  void TestRunner::end()
  {
    _statistics.end();
    _reporter->end(_statistics);
  }

  void TestRunner::runFixture(Fixture* fixture)
  {
    _testMonitor.beginFixture(*fixture);
    _reporter->beginFixture(*fixture);
    fixture->run();
    _reporter->endFixture(*fixture);
    _testMonitor.endFixture();
  }

  void TestRunner::runGroup(Group* group)
  {
    _testMonitor.beginGroup(*group);
    _reporter->beginGroup(*group);
    group->run();
    _reporter->endGroup(*group);
    _testMonitor.endGroup();
    delete group;
  }

  void TestRunner::runScenario(Scenario* scenario)
  {
    _testMonitor.beginScenario(*scenario);
    _reporter->beginScenario(*scenario);

    if (scenario->isSkipped())
    {
      _statistics.skipTest();
      _reporter->skipScenario(*scenario);
    }
    else
    {
      bool testPass = true;
      try
      {
        scenario->run();
      }
      catch (const TestError& error)
      {
        testPass = false;
        _statistics.failTest(scenario->name(), error);
        _reporter->failScenario(*scenario, error);
      }
      if (testPass)
      {
        _statistics.passTest();
        _reporter->passScenario(*scenario);
      }
    }
    
    _testMonitor.endScenario();
    delete scenario;
  }
}