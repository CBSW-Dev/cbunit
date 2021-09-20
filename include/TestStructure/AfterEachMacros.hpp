#pragma once

#define CBUNIT_AFTER_EACH()                                                                                   \
                                                                                                              \
static void _cbunit_afterEachFunction();                                                                      \
::CBUnit::AfterEach _cbunit_afterEach(_cbunit_afterEachFunction, __FILE__, __LINE__);                         \
::CBUnit::AfterEachDeclaration _cbunit_afterEachDeclaration(&_cbunit_afterEach);                             \
static void _cbunit_afterEachFunction()
