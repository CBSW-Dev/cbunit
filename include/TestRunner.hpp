#pragma once

#include "HeapObject.hpp"
#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"
#include "TestMonitor.hpp"
#include "OutputStreams/StdCoutOutputStream.hpp"
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
    using HeapFixture = HeapObject<Fixture>;
    using FixtureList = std::list<HeapFixture>;
    FixtureList _fixtures;

    Fixture* _currentFixture = nullptr;
    TestMonitor _testMonitor;
    StdCoutOutputStream _ostream;
    //DotTestReporter _reporter;
    SpecTestReporter _reporter;
    TestStatistics _statistics;
    TestStructureError _deferredTestStructureError;

    static TestRunner* _instance;
  };
}