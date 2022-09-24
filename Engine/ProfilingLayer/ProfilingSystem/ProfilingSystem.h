#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace ProfilingSystem{
#ifdef _WIN32
class ENGINE_API ProfilingSystem : public ISystem
#else 
#ifdef __APPLE__
class ProfilingSystem : public ISystem
#endif
#ifdef __linux__
class ProfilingSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class ProfilingSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    ProfilingSystem();

    void Initialize();
};
} // namespace ProfilingSystem
} // namespace Engine