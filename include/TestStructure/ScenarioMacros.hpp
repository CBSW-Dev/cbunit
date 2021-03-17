#pragma once

#define CBUNIT_SCENARIO(...)                                                                    \
                                                                                                \
CBUNIT_FILEINFO                                                                                 \
CBUNIT_LINEINFO                                                                                 \
::CBUnit::ScenarioDeclaration CBUNIT_CONCAT(_cbunit_scenario_, __COUNTER__)(__VA_ARGS__);
