#pragma once
#include <type_traits>
#include <array>
#include <vector>
#include <list>
#include <deque>
namespace CBUnit
{
  namespace
  {
    template<typename... Ts> struct MakeExpectVoid { typedef void type;};
    template<typename... Ts> using ExpectVoid = typename MakeExpectVoid<Ts...>::type;

    template <class T, class = void> class ExpectIsVoidFunction: public std::false_type {};
    
    template <class R, typename...Args> class ExpectIsVoidFunction<R (*)(Args...)>
    {
    public:
      static constexpr bool value = std::is_same<void, R>::value;
    };

    template <class R, typename C, typename...Args> class ExpectIsVoidFunction<R (C::*)(Args...)>
    {
    public:
      static constexpr bool value = std::is_same<void, R>::value;
    };

    template <class R, typename C, typename...Args> class ExpectIsVoidFunction<R (C::*)(Args...) const>
    {
    public:
      static constexpr bool value = std::is_same<void, R>::value;
    };

    template <class T> class ExpectIsVoidFunction<T, ExpectVoid<decltype(&T::operator())>>: public ExpectIsVoidFunction<decltype(&T::operator())> {};

    template<class T> struct ExpectIsSequence: std::false_type {};
    template<class U, std::size_t N> struct ExpectIsSequence<std::array<U, N>>: std::true_type {};
    template<class U> struct ExpectIsSequence<std::vector<U>>: std::true_type {};
    template<class U> struct ExpectIsSequence<std::list<U>>: std::true_type {};
    template<class U> struct ExpectIsSequence<std::deque<U>>: std::true_type {};
  }

  template <typename T> class ExpectIs
  {
  public:
    using DecayedType = typename std::remove_cv<typename std::remove_reference<T>::type>::type;
    static constexpr bool boolean = std::is_same<DecayedType, bool>::value;
    static constexpr bool integer = std::is_integral<DecayedType>::value && !boolean;
    static constexpr bool string = std::is_same<DecayedType, std::string>::value;
    static constexpr bool pointer = std::is_pointer<DecayedType>::value;
    static constexpr bool constCharArray = std::is_same<DecayedType, const char*>::value;
    static constexpr bool sequence =  ExpectIsSequence<DecayedType>::value;
    static constexpr bool voidFunction = ExpectIsVoidFunction<DecayedType>::value;
  };
}