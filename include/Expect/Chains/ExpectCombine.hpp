#pragma once

namespace CBUnit
{
  template <typename ...Classes> class ExpectCombine: public Classes... {};
}