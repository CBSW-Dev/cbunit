#pragma once

#define CBUNIT_GROUP(...)                                                                       \
                                                                                                \
CBUNIT_FILEINFO                                                                                 \
CBUNIT_LINEINFO                                                                                 \
::CBUnit::GroupDeclaration CBUNIT_CONCAT(_cbunit_group_, __COUNTER__)(__VA_ARGS__);