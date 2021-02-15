#pragma once

#define CBUNIT_SCENARIO(ScenarioName, TestFunction)                                             \
                                                                                                \
CBUNIT_FILEINFO                                                                                 \
CBUNIT_LINEINFO                                                                                 \
::CBUnit::ScenarioDeclaration CBUNIT_CONCAT(scenario_, __COUNTER__)(ScenarioName, TestFunction);