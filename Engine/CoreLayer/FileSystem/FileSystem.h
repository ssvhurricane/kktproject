#pragma once

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>


#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../LogSystem/LogSystem.h"

#include "../../PlatformSpecificLayer/PlatformFileSystem/PlatformFileSystem.h"

namespace Engine {
namespace FileSystem {

#ifdef _WIN32
class ENGINE_API FileSystem : public ISystem
#else
#ifdef __APPLE__  
class FileSystem : public ISystem
#endif
#ifdef  __linux__
class FileSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class FileSystem : public ISystem
#endif
#endif
{
private:
// TODO:
public:

    FileSystem();

    void Initialize();

    std::string GetFileData(const char* filePath);
};

} // namespace FileSystem
} // namespace Engine