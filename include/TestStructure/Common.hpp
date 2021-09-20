#pragma once

#include <stdint.h>
#include <list>
#include <stack>
#include <map>
#include <string>
#include <functional>
#include <initializer_list>

namespace CBUnit
{
  using RunFunction = void (*)();
}

#define CBUNIT_CONCAT2(x, y) x ## y
#define CBUNIT_CONCAT(x, y) CBUNIT_CONCAT2(x, y)