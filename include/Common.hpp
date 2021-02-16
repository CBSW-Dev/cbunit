#pragma once

#include <stdint.h>
#include <list>
#include <stack>
#include <string>
#include <functional>
#include <initializer_list>

namespace CBUnit
{
  using RunFunction = std::function<void()>;
}

#define CBUNIT_CONCAT2(x, y) x ## y
#define CBUNIT_CONCAT(x, y) CBUNIT_CONCAT2(x, y)