#pragma once
#include "TestStructure/TestError.hpp"

#include <iomanip>
#include <sstream>

namespace CBUnit
{
	template <class Type> class StreamWriter
	{
	public:
		static void writeValue(std::stringstream& stream, const Type& value)
		{
				stream << value;
		}
	};

	template <> class StreamWriter<bool>
	{
	public:
		static void writeValue(std::stringstream& stream, bool value)
		{
				stream << (value ? "true" : "false");
		}
	};

	template <> class StreamWriter<char>
	{
	public:
		static void writeValue(std::stringstream& stream, char value)
		{
			stream << value << "(0x" << std::hex << static_cast<int>(value) << std::dec << ")";
		}
	};

	template <> class StreamWriter<unsigned char>
	{
	public:
		static void writeValue(std::stringstream& stream, unsigned char value)
		{
			stream << value << "(0x" << std::hex << static_cast<int>(value) << std::dec << ")";
		}
	};

	template <class Type> class StreamWriter<Type*>
	{
	public:
		static void writeValue(std::stringstream& stream, Type* value)
		{
			stream << "0x" << std::hex << reinterpret_cast<size_t>(value) << std::dec;
		}
	};

	template <class Type> std::string buildExpectationFailureMessage(const Type& expected, const Type& actual)
	{
		std::stringstream ss;

		ss << "Expected: ";
		StreamWriter<Type>::writeValue(ss, expected);
		ss << ", Actual: ";
		StreamWriter<Type>::writeValue(ss, actual);

		return ss.str();
	}

	template <class Type> std::string buildExpectationNotFailureMessage(const Type& expected, const Type& actual)
	{
		(void)expected;
		std::stringstream ss;

		ss << "Expected was same as Actual: ";
		ss << actual;

		return ss.str();
	}


	std::string buildCharExpectationFailureMessage(char expected, char actual);

	template <class Type> class TestExpectationFailure: public TestError
	{
	public:
		TestExpectationFailure(const Type& expected, const Type& actual, const char* filename, uint32_t lineNumber):
				TestError(buildExpectationFailureMessage<Type>(expected, actual), filename, lineNumber)
		{}
	};

	template <class Type> class TestExpectationNotFailure: public TestError
	{
	public:
		TestExpectationNotFailure(const Type& expected, const Type& actual, const char* filename, uint32_t lineNumber):
			TestError(buildExpectationNotFailureMessage<Type>(expected, actual), filename, lineNumber)
		{}
	};

	template <> class TestExpectationFailure<std::string>: public TestError
	{
	public:
		TestExpectationFailure(const std::string& expected, const std::string& actual, const char* filename, uint32_t lineNumber):
			TestError(buildExpectationFailureMessage<std::string>(expected, actual), filename, lineNumber)
		{}

		TestExpectationFailure(const std::string& expected, const char* actual, const char* filename, uint32_t lineNumber):
			TestError(buildExpectationFailureMessage<std::string>(expected, std::string(actual)), filename, lineNumber)
		{}
	};

	template <> class TestExpectationNotFailure<std::string>: public TestError
	{
	public:
		TestExpectationNotFailure(const std::string& expected, const std::string& actual, const char* filename, uint32_t lineNumber):
			TestError(buildExpectationNotFailureMessage<std::string>(expected, actual), filename, lineNumber)
		{}

		TestExpectationNotFailure(const std::string& expected, const char* actual, const char* filename, uint32_t lineNumber):
			TestError(buildExpectationNotFailureMessage<std::string>(expected, std::string(actual)), filename, lineNumber)
		{}
	};
}