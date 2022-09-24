#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../FileSystem/FileSystem.h"
#include "../LogSystem/LogSystem.h"

namespace Engine {
namespace ConfigSystem{
#ifdef _WIN32
class ENGINE_API ConfigSystem : public ISystem
#else 
#ifdef __APPLE__
class ConfigSystem : public ISystem
#endif
#ifdef __linux__
class ConfigSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class ConfigSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:
    ConfigSystem();
    
    void Initialize();
};
} // namespace ConfigSystem
} // namespace Engine