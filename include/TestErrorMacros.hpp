#pragma once

#define CBUNIT_FAIL_TEST(message) throw ::CBUnit::TestError(message, __FILE__, __LINE__)