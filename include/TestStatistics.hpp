#pragma once

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
    void failTest();

    uint32_t passes() const;
    uint32_t failures() const;
    uint32_t tests() const;
    uint32_t millisecondsElapsed() const;
  private:
    uint32_t _passes;
    uint32_t _failures;
    std::chrono::steady_clock::time_point _startTime;
    std::chrono::steady_clock::time_point _endTime;
  };
}