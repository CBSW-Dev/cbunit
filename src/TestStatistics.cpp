#include "TestStatistics.hpp"

#include <chrono>
namespace CBUnit
{
  void TestStatistics::begin()
  {
    _passes = 0;
    _failures = 0;
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

  void TestStatistics::failTest()
  {
    ++_failures;
  }

  uint32_t TestStatistics::passes() const
  {
    return _passes;
  }

  uint32_t TestStatistics::failures() const
  {
    return _failures;
  }

  uint32_t TestStatistics::tests() const
  {
    return _passes + _failures;
  }
    
  uint32_t TestStatistics::millisecondsElapsed() const
  {
    return std::chrono::duration_cast<std::chrono::milliseconds>(_endTime - _startTime).count();
  }
}