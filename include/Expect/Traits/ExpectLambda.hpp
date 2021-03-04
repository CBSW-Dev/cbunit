#pragma once
#include "ExpectTo.hpp"
#include "ExpectIs.hpp"

namespace CBUnit
{
   template <typename T, typename Logic> class ExpectToLambda: public virtual ExpectBase<T>
  {
  public:
    template <typename E> void throwException(std::function<void (const E&)> errorCheck = [](const E&) {})
    {
      bool bThrow = false;
      try
      {
        (this->actual())(); //invoke the function
      }
      catch(const E& error)
      {
        bThrow = true;
        errorCheck(error);
      }
      
      if (Logic::logic(bThrow == false))
      {
        throw TestError("Error was not thrown", this->filename(), this->lineNumber());
      }
    }
  };
  template <typename T, typename Logic> using ExpectToBoolean = ExpectEquals<T, Logic>;

  template <typename T, typename Logic> class ExpectTo<T, Logic, typename std::enable_if<ExpectIs<T>::voidFunction>::type>: public ExpectToLambda<T, Logic> {};
}