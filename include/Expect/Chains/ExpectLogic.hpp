#pragma once

namespace CBUnit
{
  class ExpectLogic
  {
  public:
    static inline bool logic(bool value) {return value;}
  };

  class ExpectInvertingLogic
  {
  public:
    static inline bool logic(bool value) {return !value;}
  };
}