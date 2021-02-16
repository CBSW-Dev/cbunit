#include "OutputStreams/StdCoutOutputStream.hpp"
#include <iostream>

namespace CBUnit
{
  StdCoutOutputStream& StdCoutOutputStream::operator << (const std::string& string)
  {
    std::cout << string;
    return *this;
  }

  StdCoutOutputStream& StdCoutOutputStream::operator << (uint32_t value)
  {
    std::cout << value;
    return *this;
  }

  StdCoutOutputStream& StdCoutOutputStream::operator << (Colours colour)
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