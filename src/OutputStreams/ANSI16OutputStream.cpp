#include "OutputStreams/ANSI16OutputStream.hpp"
#include <iostream>

namespace CBUnit
{
  ANSI16OutputStream& ANSI16OutputStream::operator << (Colours colour)
  {
    switch (colour)
    {
    case Colours::Default:
      std::cout << "\u001b[0m";
      break;
    case Colours::White:
      std::cout << "\u001b[37;1m";
      break;
    case Colours::Grey:
    case Colours::DarkGrey:
      std::cout << "\u001b[37m";
      break;
    case Colours::Red:
      std::cout << "\u001b[31m";
      break;
    case Colours::Green:
      std::cout << "\u001b[32m";
      break;
    case Colours::Yellow:
      std::cout << "\u001b[33m";
      break;
    case Colours::Blue:
      std::cout << "\u001b[34m";
      break;
    }
    return *this;
  }
}