#include "Reporters/SpecTestReporter.hpp"
#include "Utility/Unused.hpp"

namespace CBUnit
{
  SpecTestReporter::SpecTestReporter(OutputStream& ostream):
    FinalisingTestReporter(ostream)
  {}

  void SpecTestReporter::begin() 
  {
     _ostream << "\r\n";
  }

  void SpecTestReporter::beginFixture(Fixture& fixture) 
  {
    _ostream << _ostream.white << fixture.name() << _ostream.reset << "\r\n";
  }

  void SpecTestReporter::endFixture(Fixture& fixture) 
  {
     ::CBUnit::unused(fixture);
  }

  void SpecTestReporter::beginGroup(Group& group) 
  {
    ++_depth;
    printTabs();
   _ostream << _ostream.white << group.name() << _ostream.reset << "\r\n";
  }

  void SpecTestReporter::endGroup(Group& group) 
  {
     ::CBUnit::unused(group);
    --_depth;
  }

  void SpecTestReporter::beginScenario(Scenario& scenario) 
  {
    ::CBUnit::unused(scenario);
    ++_depth;
  }
  
  void SpecTestReporter::passScenario(Scenario& scenario) 
  {
    printTabs();
    _ostream << _ostream.green << scenario.name() << _ostream.reset << "\r\n";
    --_depth;
  }

  void SpecTestReporter::skipScenario(Scenario& scenario) 
  {
    printTabs();
    _ostream << _ostream.darkGrey << "Skipping: " << scenario.name() << _ostream.reset << "\r\n";
    --_depth;
  }

  void SpecTestReporter::failScenario(Scenario& scenario, const TestError& error) 
  {
    ::CBUnit::unused(error);
    printTabs();
    _ostream << _ostream.red << _failureCount++ << ") " << scenario.name() << _ostream.reset << "\r\n";
    --_depth;
  }

  void SpecTestReporter::end(const TestStatistics& statistics)
  {
    _ostream << "\r\n";
    FinalisingTestReporter::end(statistics);
  }

  void SpecTestReporter::printTabs()
  {
    static constexpr const char* tab = "  "; 
    for (uint32_t i = 0; i < _depth; ++i)
    {
      _ostream << tab;
    }
  }
}