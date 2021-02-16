#pragma once

#include "HeapObject.hpp"
#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"
#include "TestMonitor.hpp"
#include "OutputStreams/ANSI8OutputStream.hpp"
#include "OutputStreams/ANSI256OutputStream.hpp"
#include "Reporters/DotTestReporter.hpp"
#include "Reporters/SpecTestReporter.hpp"
#include "TestStructureError.hpp"

namespace CBUnit
{
  class TestRunner
  {
  public:
    TestRunner();
    void addFixture(Fixture* fixture);
    void addGroup(Group* group);
    void addScenario(Scenario* scenario);

    int run();

    static TestRunner& instance();
  private:
    void begin();
    void end();
    void runFixture(Fixture* fixture);
    void runGroup(Group* group);
    void runScenario(Scenario* scenario);
  private:
    using HeapFixture = HeapObject<Fixture>;
    using FixtureList = std::list<HeapFixture>;
    FixtureList _fixtures;

    Fixture* _currentFixture = nullptr;
    TestMonitor _testMonitor;
    //ANSI8OutputStream _ostream;
    ANSI256OutputStream _ostream;
    //DotTestReporter _reporter;
    SpecTestReporter _reporter;
    TestStatistics _statistics;
    TestStructureError _deferredTestStructureError;

    static TestRunner* _instance;
  };
}