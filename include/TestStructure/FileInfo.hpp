#pragma once
#include "Common.hpp"

namespace CBUnit
{
  class FileInfo
  {
  public:
    FileInfo(const char* file);
    static const char* file;
  };
}

#define CBUNIT_FILEINFO ::CBUnit::FileInfo CBUNIT_CONCAT(_cbunit_file,__COUNTER__)(__FILE__);