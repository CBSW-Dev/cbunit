#pragma once
#include "Traits/ExpectBuilder.hpp"

#include <string>

namespace CBUnit
{
  //By defining this as a class, it allows for specialisation of custom classes
	template <class Type> class Expect: public ExpectBuilder<Type> 
  {
  public:
    Expect(const Type& actual, const char* filename, uint32_t lineNumber):
      ExpectBuilder<Type>(actual, filename, lineNumber)
    {}
  };

	class MakeExpect 
	{
	public:
		MakeExpect(const char* file, uint32_t line):
			_file(file),
			_line(line)
		{}

		template <class Type> Expect<Type> expect(const Type& value) const
		{
			return Expect<Type>(value,  _file, _line);
		}

		Expect<std::string> expect(const char* value) const
		{
			return Expect<std::string>(value, _file, _line);
		}
	private:
		const char* _file;
		uint32_t _line;
	};
			
	inline MakeExpect build_make_expect(const char* file, uint32_t line)
  {
		return MakeExpect(file, line);
	}
}
