#include "Reporters/DotTestReporter.hpp"

#include "Utility/Unused.hpp"

namespace CBUnit
{
  DotTestReporter::DotTestReporter(OutputStream& ostream):
    FinalisingTestReporter(ostream)
  {}

  void DotTestReporter::begin() 
  {
     _ostream << "\r\n";
  }

  void DotTestReporter::beginFixture(Fixture& fixture) 
  {
    ::CBUnit::unused(fixture);
  }

  void DotTestReporter::endFixture(Fixture& fixture) 
  {
    ::CBUnit::unused(fixture);
  }

  void DotTestReporter::beginGroup(Group& group) 
  {
    ::CBUnit::unused(group);
  }

  void DotTestReporter::endGroup(Group& group) 
  {
    ::CBUnit::unused(group);
  }

  void DotTestReporter::beginScenario(Scenario& scenario) 
  {
    ::CBUnit::unused(scenario);
  }
  
  void DotTestReporter::passScenario(Scenario& scenario) 
  {
     ::CBUnit::unused(scenario);
    _ostream << _ostream.green << "."  << _ostream.reset;
  }

  void DotTestReporter::skipScenario(Scenario& scenario) 
  {
     ::CBUnit::unused(scenario);
    _ostream << _ostream.darkGrey << "."  << _ostream.reset;
  }

  void DotTestReporter::failScenario(Scenario& scenario, const TestError& error) 
  {
     ::CBUnit::unused(scenario, error);
    _ostream << _ostream.red << "."  << _ostream.reset;
  }

  void DotTestReporter::end(const TestStatistics& statistics)
  {
    _ostream << "\r\n";
    FinalisingTestReporter::end(statistics);
  }
}