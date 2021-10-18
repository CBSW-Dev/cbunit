#pragma once

#define CBUNIT_BEFORE_EACH()                                                                                      \
                                                                                                                  \
static void _cbunit_beforeEachFunction();                                                                         \
static ::CBUnit::BeforeEach _cbunit_beforeEach(_cbunit_beforeEachFunction, __FILE__, __LINE__);                   \
static ::CBUnit::BeforeEachDeclaration _cbunit_beforeEachDeclaration(&_cbunit_beforeEach);                        \
static void _cbunit_beforeEachFunction()
