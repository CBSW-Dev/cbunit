#pragma once

#pragma once
#include "TestStructure/TestError.hpp"

#include <sstream>
#include <iomanip>

namespace CBUnit
{
  namespace
  {
    template <class T> class StringBuilder
    {
    public:
      static std::string build(const T& value)
      {
        std::stringstream ss;
        ss << value;
        return ss.str();
      }
    };

    template <> class StringBuilder<std::string>
    {
    public:
      static std::string build(const std::string& value)
      {
        return std::string("\"") + value + "\"";
      }
    };

    template <> class StringBuilder<bool>
    {
    public:
      static std::string build(bool value)
      {
        return value ? "true" : "false";
      }
    };

    template <class T> class StringBuilder<T*>
    {
    public:
      static std::string build(const T* value)
      {
        std::stringstream ss;
        ss << "0x" << std::hex << std::setw(sizeof(void*)) << std::setfill('0') << reinterpret_cast<std::size_t>(value);
        return ss.str(); 
      }
    };
  }

  class TestExpectationMessageBuilder
  {
  public:
    template <class T> static std::string buildMessage(const T& actual, const T& expected, const std::string& conjunction)
    {
      std::stringstream ss;
      ss << "Expected ";
      ss << StringBuilder<T>::build(actual);
      ss << " ";
      ss << conjunction;
      ss << " ";
      ss << StringBuilder<T>::build(expected);;
      return ss.str();
    }
  };
}
