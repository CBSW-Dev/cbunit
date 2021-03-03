#include "Reporters/MinTestReporter.hpp"

#include "Utility/Unused.hpp"

namespace CBUnit
{
  MinTestReporter::MinTestReporter(OutputStream& ostream):
    FinalisingTestReporter(ostream)
  {}

  void MinTestReporter::begin() {}
  
  void MinTestReporter::beginFixture(Fixture& fixture) 
  {
    ::CBUnit::unused(fixture);
  }

  void MinTestReporter::endFixture(Fixture& fixture) 
  {
    ::CBUnit::unused(fixture);
  }

  void MinTestReporter::beginGroup(Group& group) 
  {
    ::CBUnit::unused(group);
  }

  void MinTestReporter::endGroup(Group& group) 
  {
    ::CBUnit::unused(group);
  }

  void MinTestReporter::beginScenario(Scenario& scenario) 
  {
    ::CBUnit::unused(scenario);
  }
  
  void MinTestReporter::passScenario(Scenario& scenario) 
  {
    ::CBUnit::unused(scenario);
  }

  void MinTestReporter::skipScenario(Scenario& scenario)  
  {
    ::CBUnit::unused(scenario);
  }

  void MinTestReporter::failScenario(Scenario& scenario, const TestError& error) 
  {
    ::CBUnit::unused(scenario, error);
  }
}