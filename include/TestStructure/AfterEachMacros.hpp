#pragma once

#define CBUNIT_AFTER_EACH(...)                                              \
                                                                            \
  CBUNIT_FILEINFO                                                           \
  CBUNIT_LINEINFO                                                           \
  ::CBUnit::AfterEachDeclaration CBUNIT_CONCAT(_cbunit_after_each_, __COUNTER__)(__VA_ARGS__);
  