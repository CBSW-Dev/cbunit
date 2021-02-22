default: help

include make/c++.mk
include make/tools.mk
include make/sources.mk
include src/make.mk
include examples/make.mk

CBUNIT_LIBRARY = 							$(CBUNIT_BINARY_DIRECTORY)/cbunit.lib
CBUNIT_EXAMPLES_EXECUTABLE =	$(CBUNIT_BINARY_DIRECTORY)/cbunit-examples

CPP_INCLUDES += $(CBUNIT_INCLUDE_DIRECTORY)

cbunit: $(CBUNIT_LIBRARY)

$(CBUNIT_LIBRARY): $(CBUNIT_OBJECT_FILES)
	$(MAKE_LIBRARY) $(CBUNIT_LIBRARY) $^

cbunit-clean:
	$(REMOVE) $(CBUNIT_OBJECT_FILES) $(CBUNIT_EXAMPLES_OBJECT_FILES) $(CBUNIT_EXAMPLES_EXECUTABLE) $(CBUNIT_LIBRARY)

cbunit-examples: $(CBUNIT_EXAMPLES_EXECUTABLE)
	$(CBUNIT_EXAMPLES_EXECUTABLE) --reporter spec --output ansi256

$(CBUNIT_EXAMPLES_EXECUTABLE): $(CBUNIT_OBJECT_FILES) $(CBUNIT_EXAMPLES_OBJECT_FILES) examples/main.cpp
	$(MAKE_DIRECTORY) $(@D)
	$(REMOVE) $@
	$(CPP) -o $@ $^

$(CBUNIT_BUILD_DIRECTORY)/%.o: %.cpp
	$(MAKE_DIRECTORY) $(@D)
	$(CPP) -c -o $@ $^ 

.PHONY: cbunit-clean
