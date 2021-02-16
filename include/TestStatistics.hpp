#pragma once

#include "TestError.hpp"

#include <stdint.h>
#include <chrono>

namespace CBUnit
{
  class TestStatistics
  {
  public:
    void begin();
    void end();

    void passTest();
    void skipTest();
    void failTest(const std::string& scenario, const TestError& error);

    struct TestFailure
    {
      std::string scenario;
      TestError error;
    };
    using TestFailures = std::list<TestFailure>;
    
    const TestFailures& failures() const;
    uint32_t passCount() const;
    uint32_t skipCount() const;
    uint32_t failureCount() const;
    uint32_t millisecondsElapsed() const;
  private:
    uint32_t _passes;
    uint32_t _skips;
    TestFailures _failures;
    
    std::chrono::steady_clock::time_point _startTime;
    std::chrono::steady_clock::time_point _endTime;
  };
}