CBUNIT_SOURCE_DIRECTORY := src
CBUNIT_INCLUDE_DIRECTORY := include
CBUNIT_BUILD_DIRECTORY := build
CBUNIT_EXAMPLES_DIRECTORY := examples

CBUNIT_SOURCE_FILES = 	src/main.cpp \
												src/TestObject.cpp \
												src/Scenario.cpp \
												src/Group.cpp \
												src/Fixture.cpp \
												src/TestRunner.cpp \
												src/TestMonitor.cpp \
												src/TestStructureError.cpp \
												src/LineInfo.cpp \
												src/FileInfo.cpp


CBUNIT_EXAMPLES_FILES = examples/unit_simple.cpp

CBUNIT_OBJECT_FILES = $(patsubst $(CBUNIT_SOURCE_DIRECTORY)/%.cpp, $(CBUNIT_BUILD_DIRECTORY)/%.o, $(CBUNIT_SOURCE_FILES))
CBUNIT_EXAMPLES_OBJECT_FILES = $(patsubst $(CBUNIT_EXAMPLES_DIRECTORY)/%.cpp, $(CBUNIT_BUILD_DIRECTORY)/examples/%.o, $(CBUNIT_EXAMPLES_FILES))

cbunit: $(CBUNIT_OBJECT_FILES)
	ar rcs cbunit.lib $^

cbunit-examples: $(CBUNIT_OBJECT_FILES) $(CBUNIT_EXAMPLES_OBJECT_FILES) examples/main.cpp
	mkdir -p $(@D)
	g++ -std=c++11 -o $@ $^ -I$(CBUNIT_INCLUDE_DIRECTORY)

$(CBUNIT_BUILD_DIRECTORY)/%.o: $(CBUNIT_SOURCE_DIRECTORY)/%.cpp
	mkdir -p $(@D)
	g++ -std=c++11 -c -o $@ $^ -I$(CBUNIT_INCLUDE_DIRECTORY)

$(CBUNIT_BUILD_DIRECTORY)/examples/%.o: $(CBUNIT_EXAMPLES_DIRECTORY)/%.cpp
	mkdir -p $(@D)
	g++ -std=c++11 -c -o $@ $^ -I$(CBUNIT_INCLUDE_DIRECTORY)