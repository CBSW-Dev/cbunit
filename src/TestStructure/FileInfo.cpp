#include "TestStructure/FileInfo.hpp"

namespace CBUnit
{
  FileInfo::FileInfo(const char* file)
  {
    FileInfo::file = file;
  }
  
  const char* FileInfo::file = "";
}