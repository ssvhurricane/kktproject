#pragma once

#include "../../KKTEngine.h" // Include only systems and components.
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace ResourceSystem{
#ifdef _WIN32
class ENGINE_API ResourceSystem : public ISystem
#else 
#ifdef __APPLE__
class ResourceSystem : public ISystem
#endif
#ifdef __linux__
class ResourceSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class ResourceSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    ResourceSystem();

    void Initialize();
};
} // namespace ResourceSystem
} // namespace Engine