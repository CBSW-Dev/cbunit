#pragma once

#include "HeapObject.hpp"
#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"
#include "BeforeEach.hpp"
#include "AfterEach.hpp"
#include "TestMonitor.hpp"
#include "Reporters/TestReporter.hpp"
#include "TestStructureError.hpp"

namespace CBUnit
{
  class TestRunner
  {
    friend class Fixture;
    friend class Group;
    friend class Scenario;
  public:
    TestRunner();
    void setReporter(TestReporter& reporter);
    void addFixture(Fixture* fixture);
    void addGroup(Group* group);
    void addScenario(Scenario* scenario);
    void addBeforeEach(BeforeEach* beforeEach);
    void addAfterEach(AfterEach* afterEach);

    int run();

    static TestRunner& instance();
  private:
    void begin();
    void end();
    void runFixture(Fixture* fixture);
    void runGroup(Group* group, RunFunction function);
    void runScenario(Scenario* scenario, RunFunction function);
  private:
    using HeapFixture = HeapObject<Fixture>;
    using FixtureList = std::list<HeapFixture>;
    FixtureList _fixtures;
    TestMonitor _testMonitor;
    TestReporter* _reporter;
    TestStatistics _statistics;
    TestStructureError _deferredTestStructureError;

    static TestRunner* _instance;
  };
}