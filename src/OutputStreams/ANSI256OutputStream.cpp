#include "OutputStreams/ANSI256OutputStream.hpp"
#include <iostream>

namespace CBUnit
{
  ANSI256OutputStream& ANSI256OutputStream::operator << (Colours colour)
  {
    switch (colour)
    {
    case Colours::Default:
      std::cout << "\u001b[0m";
      break;
    case Colours::White:
      std::cout << "\u001b[38;5;231m";
      break;
    case Colours::Grey:
      std::cout << "\u001b[38;5;245m";
      break;
    case Colours::DarkGrey:
      std::cout << "\u001b[38;5;245m";
      break;
    case Colours::Red:
      std::cout << "\u001b[38;5;196m";
      break;
    case Colours::Green:
      std::cout << "\u001b[38;5;34m";
      break;
    case Colours::Yellow:
      std::cout << "\u001b[38;5;220m";
      break;
    case Colours::Blue:
      std::cout << "\u001b[38;5;27m";
      break;
    }
    return *this;
  }
}