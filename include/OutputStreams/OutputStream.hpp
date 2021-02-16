#pragma once

#include "Fixture.hpp"
#include "Group.hpp"
#include "Scenario.hpp"

namespace CBUnit
{
  class OutputStream
  {
  public:
    virtual ~OutputStream();
    virtual OutputStream& operator << (const std::string& string) = 0;
    virtual OutputStream& operator << (uint32_t value) = 0;

    enum class Colours
    {
      Default,
      White,
      Grey,
      Red,
      Green,
      Yellow,
      Blue
    };

    virtual OutputStream& operator << (Colours colour) = 0;

    static constexpr Colours reset = Colours::Default;
    static constexpr Colours white = Colours::White;
    static constexpr Colours grey = Colours::Grey;
    static constexpr Colours red = Colours::Red;
    static constexpr Colours green = Colours::Green;
    static constexpr Colours yellow = Colours::Yellow;
    static constexpr Colours blue = Colours::Blue;
  };
}