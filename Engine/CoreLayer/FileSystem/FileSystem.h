#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

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
};

} // namespace FileSystem
} // namespace Engine