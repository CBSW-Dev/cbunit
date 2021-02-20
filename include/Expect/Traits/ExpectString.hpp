#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

#include "Expect/Chains/ExpectEquals.hpp"

#include <string>
namespace CBUnit
{
  namespace
  {
    struct TestExpectationContainText {static constexpr const char* text = "to contain";};
    template <class Logic> using TestExpectationContainFailure = TestExpectationFailure<std::string, std::string, Logic, TestExpectationContainText>; 
  }

  template <typename Logic> class ExpectToString: public ExpectEquals<std::string, Logic>
  {
  public:
    void contain(const std::string& value)
    {
      if (Logic::logic(this->actual().find(value) == std::string::npos))
      {
        throw TestExpectationContainFailure<Logic>(this->actual(), value, this->filename(), this->lineNumber());
      }
    }
  };

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::string>::type>: public ExpectToString<Logic> {};

  template <> class ExpectRoot<std::string>
  {
  public:
    ExpectRoot(const std::string& actual, const char* filename, uint32_t lineNumber):
      _length(actual.length()),
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber),
      size(sizeof(actual), filename, lineNumber),
      length(_length, filename, lineNumber)
    {}
  private:
    std::string::size_type _length;
  public:
    class Not
    {
    public:
      Not(const std::string& actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      ExpectBaseMixin<std::string, ExpectToBase<std::string, ExpectInvertingLogic>> to;
    };

    Not not;
    ExpectBaseMixin<std::string, ExpectToBase<std::string, ExpectLogic>> to;
    ExpectSize size;
    ExpectRoot<std::string::size_type> length;
  };
}