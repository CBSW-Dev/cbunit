#pragma once

#include "Common.hpp"

namespace CBUnit
{
  template<class T> class HeapObject
  {
  public:
    HeapObject(T* object):
      _object(object)
    {}

    HeapObject(HeapObject<T>&& object):
      _object(object._object)
    {
      object._object = nullptr;
    }

    ~HeapObject()
    {
      delete _object;
    }

    HeapObject<T>& operator=(HeapObject<T>&& object)
    {
      _object = object._object;
      object._object = nullptr;
    }

    T* operator ->()
    {
      return _object;
    }

    operator T*()
    {
      return _object;
    }
  private:
    HeapObject(const HeapObject<T>& object) = delete;
    HeapObject& operator=(const HeapObject<T>& object) = delete;
  private:
    T* _object;
  };
}