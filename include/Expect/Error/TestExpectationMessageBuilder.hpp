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
      static std::string build(T value)
      {
        std::stringstream ss;
        ss 
        << value;
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

    template <class T> class SequenceStringBuilder
    {
    public:
      static std::string build(const T& value)
      {
        std::string output = std::string("{");
        bool comma = false;
        for (auto item : value)
        {
          if (comma)
          {
            output += ",";
          }
          else
          {
            comma = true;
          }
          output += StringBuilder<typename T::value_type>::build(item);
        }
        output += "}";
        return output;
      }
    };

    template <class U> class StringBuilder<std::vector<U>>: public SequenceStringBuilder<std::vector<U>> {};
    template <class U> class StringBuilder<std::list<U>>: public SequenceStringBuilder<std::list<U>> {};
    template <class U> class StringBuilder<std::deque<U>>: public SequenceStringBuilder<std::deque<U>> {};
    template <class U, std::size_t N> class StringBuilder<std::array<U, N>>: public SequenceStringBuilder<std::array<U, N>> {};

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
    template <class T, class U> static std::string buildMessage(T actual, U expected, const std::string& conjunction)
    {
      std::stringstream ss;
      ss << "Expected ";
      ss << StringBuilder<T>::build(actual);
      ss << " ";
      ss << conjunction;
      ss << " ";
      ss << StringBuilder<U>::build(expected);;
      return ss.str();
    }
    template <class T> static std::string buildMessage(T actual, const std::string& suffix)
    {
      std::stringstream ss;
      ss << "Expected ";
      ss << StringBuilder<T>::build(actual);
      ss << " ";
      ss << suffix;
      return ss.str();
    }
  };
}
