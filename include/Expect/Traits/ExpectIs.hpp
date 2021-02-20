#pragma once
#include <type_traits>
#include <array>
#include <vector>
#include <list>
#include <deque>
namespace CBUnit
{
  template<class T> struct ExpectIsSequence
  {
    static constexpr bool value = false;
  };

  template<class U, std::size_t N> struct ExpectIsSequence<std::array<U, N>>
  {
    static constexpr bool value = true;
  };

  template<class U> struct ExpectIsSequence<const std::vector<U>&>
  {
    static constexpr bool value = true;
  };

  template<class U> struct ExpectIsSequence<std::vector<U>>
  {
    static constexpr bool value = true;
  };

  template<class U> struct ExpectIsSequence<const std::list<U>&>
  {
    static constexpr bool value = true;
  };

  template<class U> struct ExpectIsSequence<std::list<U>>
  {
    static constexpr bool value = true;
  };

  template<class U> struct ExpectIsSequence<const std::deque<U>&>
  {
    static constexpr bool value = true;
  };

  template<class U> struct ExpectIsSequence<std::deque<U>>
  {
    static constexpr bool value = true;
  };

  template <typename T> class ExpectIs
  {
  public:
    static constexpr bool boolean = std::is_same<T, bool>::value;
    static constexpr bool integer = std::is_integral<T>::value && !boolean;
    static constexpr bool string = std::is_same<T, std::string>::value;
    static constexpr bool pointer = std::is_pointer<T>::value;
    static constexpr bool constCharArray = std::is_same<T, const char*>::value;
    static constexpr bool sequence =  ExpectIsSequence<T>::value;
  };
}