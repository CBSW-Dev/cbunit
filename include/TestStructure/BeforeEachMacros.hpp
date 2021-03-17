#pragma once

#define CBUNIT_BEFORE_EACH(...)                                             \
                                                                            \
  CBUNIT_FILEINFO                                                           \
  CBUNIT_LINEINFO                                                           \
  ::CBUnit::BeforeEachDeclaration CBUNIT_CONCAT(_cbunit_before_each_, __COUNTER__)(__VA_ARGS__);
  