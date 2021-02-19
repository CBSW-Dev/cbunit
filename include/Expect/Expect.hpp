#pragma once
#include "Traits/ExpectRoot.hpp"
#include "Traits/ExpectTraits.hpp"
#include <string>

namespace CBUnit
{
  //By defining this as a class, it allows for specialisation of custom classes
	template <class Type> using Expect = ExpectRoot<Type>;
  
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
	private:
		const char* _file;
		uint32_t _line;
	};
			
	inline MakeExpect build_make_expect(const char* file, uint32_t line)
  {
		return MakeExpect(file, line);
	}
}
