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

  void TestStatistics::skipTest()
  {
    ++_skips;
  }

  void TestStatistics::failTest(const std::string& scenario, const TestError& error)
  {
    _failures.push_back({scenario, error});
  }

  const TestStatistics::TestFailures& TestStatistics::failures() const
  {
    return _failures;
  }

  uint32_t TestStatistics::skipCount() const
  {
    return _skips;
  }

  uint32_t TestStatistics::passCount() const
  {
    return _passes;
  }

  uint32_t TestStatistics::failureCount() const
  {
    return _failures.size();
  }
    
  uint32_t TestStatistics::millisecondsElapsed() const
  {
    return std::chrono::duration_cast<std::chrono::milliseconds>(_endTime - _startTime).count();
  }
}