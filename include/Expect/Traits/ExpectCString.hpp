#pragma once
#include "ExpectRoot.hpp"
#include "ExpectIs.hpp"
#include "ExpectString.hpp"
#include "ExpectPointer.hpp"

#include "Expect/Chains/ExpectEquals.hpp"

#include <string>
namespace CBUnit
{
  template <> class ExpectRoot<const char*>
  {
  public:
    ExpectRoot(const char* actual, const char* filename, uint32_t lineNumber):
      _string(actual),
      not(actual, filename, lineNumber),
      to(actual, filename, lineNumber),
      string(_string, filename, lineNumber),
      size(sizeof(actual), filename, lineNumber)
    {}
  private:
    std::string _string;
  public:
    class Not
    {
    public:
      Not(const char* actual, const char* filename, uint32_t lineNumber):
        to(actual, filename, lineNumber)
      {}

      ExpectBaseMixin<const char*, ExpectToBase<const char*, ExpectInvertingLogic>> to;
    };

    Not not;
    ExpectBaseMixin<const char*, ExpectToBase<const char*, ExpectLogic>> to;
    ExpectRoot<std::string> string;
    ExpectSize size;
  };
}