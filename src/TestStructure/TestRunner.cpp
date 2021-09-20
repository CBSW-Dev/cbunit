#include "TestStructure/TestRunner.hpp"
#include "TestStructure/TestError.hpp"

namespace CBUnit
{
  TestRunner* TestRunner::_instance = nullptr;

  TestRunner::TestRunner():
    _reporter(nullptr)
  {}

  void TestRunner::addFixture(Fixture* fixture)
  {
    _fixtures.push_back(fixture);
  }

  void TestRunner::setReporter(TestReporter& reporter)
  {
    _reporter = &reporter;
  }

  int TestRunner::run()
  {
    begin();
    for (auto fixture : _fixtures)
    {
      runFixture(fixture);
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
  }

  void TestRunner::end()
  {
    _statistics.end();
    _reporter->end(_statistics);
  }

  void TestRunner::runFixture(Fixture* fixture)
  {
    _reporter->beginFixture(*fixture);
    fixture->run();

    _reporter->endFixture(*fixture);
  }

  void TestRunner::runScenario(Scenario* scenario, RunFunction function)
  {
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
        function();
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
  }
}