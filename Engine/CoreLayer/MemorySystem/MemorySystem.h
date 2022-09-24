#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace MemorySystem{
#ifdef _WIN32
class ENGINE_API MemorySystem : public ISystem
#else 
#ifdef __APPLE__
class MemorySystem : public ISystem
#endif
#ifdef __linux__
class MemorySystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class MemorySystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   MemorySystem();

    void Initialize();
};
} // namespace MemorySystem
} // namespace Engine