#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace PlatformSpecificSystem{
#ifdef _WIN32
class ENGINE_API PlatformSpecificSystem : public ISystem
#else 
#ifdef __APPLE__
class PlatformSpecificSystem : public ISystem
#endif
#ifdef __linux__
class PlatformSpecificSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class PlatformSpecificSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    PlatformSpecificSystem();

    void Initialize();
};
} // namespace PlatformSpecificSystem
} // namespace Engine