#pragma once

#include "Fixture.hpp"
#include "Scenario.hpp"
#include "BeforeEach.hpp"
#include "AfterEach.hpp"
#include "Reporters/TestReporter.hpp"

namespace CBUnit
{
  class TestRunner
  {
    friend class Fixture;
    friend class Scenario;
  public:
    TestRunner();
    void setReporter(TestReporter& reporter);
    void addFixture(Fixture* fixture);

    int run();

    static TestRunner& instance();
  private:
    void begin();
    void end();
    void runFixture(Fixture* fixture);
    void runScenario(Scenario* scenario, RunFunction function);
  private:
    using FixtureList = std::list<Fixture*>;
    FixtureList _fixtures;
    TestReporter* _reporter;
    TestStatistics _statistics;

    static TestRunner* _instance;
  };
}