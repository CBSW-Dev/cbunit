CBUNIT_SOURCE_DIRECTORY := src
CBUNIT_INCLUDE_DIRECTORY := include
CBUNIT_BUILD_DIRECTORY := build
CBUNIT_EXAMPLES_DIRECTORY := examples

CBUNIT_SOURCE_FILES = 	src/Application/main.cpp \
												src/Application/CommandLineArguments.cpp \
												src/Application/Settings.cpp \
												src/TestStructure/TestObject.cpp \
												src/TestStructure/Scenario.cpp \
												src/TestStructure/Group.cpp \
												src/TestStructure/Fixture.cpp \
												src/TestStructure/TestRunner.cpp \
												src/TestStructure/TestMonitor.cpp \
												src/TestStructure/TestError.cpp \
												src/TestStructure/TestStructureError.cpp \
												src/TestStructure/TestStatistics.cpp \
												src/TestStructure/LineInfo.cpp \
												src/TestStructure/FileInfo.cpp \
												src/Reporters/TestReporter.cpp \
												src/Reporters/FinalisingTestReporter.cpp \
												src/Reporters/MinTestReporter.cpp \
												src/Reporters/DotTestReporter.cpp \
												src/Reporters/SpecTestReporter.cpp \
												src/Reporters/TestReporterFactory.cpp \
												src/OutputStreams/OutputStream.cpp \
												src/OutputStreams/StdCoutOutputStream.cpp \
												src/OutputStreams/ANSI8OutputStream.cpp \
												src/OutputStreams/ANSI16OutputStream.cpp \
												src/OutputStreams/ANSI256OutputStream.cpp \
												src/OutputStreams/OutputStreamFactory.cpp \
												


CBUNIT_EXAMPLES_FILES = examples/unit_simple.cpp \
												examples/unit_calculator.cpp

CBUNIT_OBJECT_FILES = $(patsubst $(CBUNIT_SOURCE_DIRECTORY)/%.cpp, $(CBUNIT_BUILD_DIRECTORY)/%.o, $(CBUNIT_SOURCE_FILES))
CBUNIT_EXAMPLES_OBJECT_FILES = $(patsubst $(CBUNIT_EXAMPLES_DIRECTORY)/%.cpp, $(CBUNIT_BUILD_DIRECTORY)/examples/%.o, $(CBUNIT_EXAMPLES_FILES))

cbunit: $(CBUNIT_OBJECT_FILES)
	ar rcs cbunit.lib $^

cbunit-clean:
	rm -rf $(CBUNIT_OBJECT_FILES) $(CBUNIT_EXAMPLES_OBJECT_FILES) cbunit-examples cbunit.lib

cbunit-examples: $(CBUNIT_OBJECT_FILES) $(CBUNIT_EXAMPLES_OBJECT_FILES) examples/main.cpp
	mkdir -p $(@D)
	g++ -std=c++11 -fno-operator-names -o $@ $^ -I$(CBUNIT_INCLUDE_DIRECTORY)

$(CBUNIT_BUILD_DIRECTORY)/%.o: $(CBUNIT_SOURCE_DIRECTORY)/%.cpp
	mkdir -p $(@D)
	g++ -std=c++11 -fno-operator-names -c -o $@ $^ -I$(CBUNIT_INCLUDE_DIRECTORY)

$(CBUNIT_BUILD_DIRECTORY)/examples/%.o: $(CBUNIT_EXAMPLES_DIRECTORY)/%.cpp
	mkdir -p $(@D)
	g++ -std=c++11 -fno-operator-names -c -o $@ $^ -I$(CBUNIT_INCLUDE_DIRECTORY)

.PHONY: cbunit-clean