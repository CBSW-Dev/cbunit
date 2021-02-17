#include "OutputStreams/OutputStreamFactory.hpp"
#include "OutputStreams/StdCoutOutputStream.hpp"
#include "OutputStreams/ANSI8OutputStream.hpp"
#include "OutputStreams/ANSI16OutputStream.hpp"
#include "OutputStreams/ANSI256OutputStream.hpp"

namespace CBUnit
{
  OutputStream* OutputStreamFactory::createOutputStream(const std::string& streamName)
  {
    if (streamName == "ansi8")
    {
      return new ANSI8OutputStream;
    }
    else if (streamName == "ansi16")
    {
      return new ANSI16OutputStream;
    }
    else if (streamName == "ansi256")
    {
      return new ANSI256OutputStream;
    }
    else
    {
      return new StdCoutOutputStream;
    }
  }
}