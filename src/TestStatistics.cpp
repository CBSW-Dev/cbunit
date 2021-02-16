#include "TestStatistics.hpp"

#include <chrono>
namespace CBUnit
{
  void TestStatistics::begin()
  {
    _passes = 0;
    _failures.clear();
    _startTime = std::chrono::steady_clock::now();
  }
    
  void TestStatistics::end()
  {
    _endTime = std::chrono::steady_clock::now();
    
  }


  void TestStatistics::passTest()
  {
    ++_passes;
  }

  void TestStatistics::failTest(const std::string& scenario, const TestError& error)
  {
    _failures.push_back({scenario, error});
  }

  const TestStatistics::TestFailures& TestStatistics::failures() const
  {
    return _failures;
  }

  uint32_t TestStatistics::testCount() const
  {
    return _passes + _failures.size();
  }
    
  uint32_t TestStatistics::millisecondsElapsed() const
  {
    return std::chrono::duration_cast<std::chrono::milliseconds>(_endTime - _startTime).count();
  }
}