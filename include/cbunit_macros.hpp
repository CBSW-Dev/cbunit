#pragma once

#include "FixtureMacros.hpp"
#include "GroupMacros.hpp"
#include "ScenarioMacros.hpp"
#include "TestErrorMacros.hpp"

#define fixture(FixtureName, TestFunction)    CBUNIT_FIXTURE(FixtureName, TestFunction)
#define group(GroupName, TestFunction)        CBUNIT_GROUP(GroupName, TestFunction)
#define scenario(ScenarioName, TestFunction)  CBUNIT_SCENARIO(ScenarioName, TestFunction)
#define failTest(message)                     CBUNIT_FAIL_TEST(message)