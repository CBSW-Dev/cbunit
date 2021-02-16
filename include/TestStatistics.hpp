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
    void failTest(const std::string& scenario, const TestError& error);

    struct TestFailure
    {
      std::string scenario;
      TestError error;
    };
    using TestFailures = std::list<TestFailure>;
    
    const TestFailures& failures() const;
    uint32_t testCount() const;
    uint32_t millisecondsElapsed() const;
  private:
    uint32_t _passes;
    TestFailures _failures;
    
    std::chrono::steady_clock::time_point _startTime;
    std::chrono::steady_clock::time_point _endTime;
  };
}