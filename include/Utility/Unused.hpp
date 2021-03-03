#pragma once

namespace CBUnit
{
  template <class ...T> constexpr bool unused(T&&...) 
  {
    return false;
  }
}