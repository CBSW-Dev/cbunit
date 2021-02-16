#pragma once

#define CBUNIT_GROUP(GroupName, TestFunction)                                                   \
                                                                                                \
CBUNIT_FILEINFO                                                                                 \
CBUNIT_LINEINFO                                                                                 \
::CBUnit::GroupDeclaration CBUNIT_CONCAT(_cbunit_group_, __COUNTER__)(GroupName, TestFunction);