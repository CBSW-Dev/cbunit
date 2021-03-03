#include "OutputStreams/StdCoutOutputStream.hpp"

#include "Utility/Unused.hpp"
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
    ::CBUnit::unused(colour);
    //Do Nothing - i.e. no colour support
    return *this;
  }
}