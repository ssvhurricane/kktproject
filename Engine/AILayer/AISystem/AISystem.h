#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace AISystem{
#ifdef _WIN32
class ENGINE_API AISystem : public ISystem
#else 
#ifdef __APPLE__
class AISystem : public ISystem
#endif
#ifdef __linux__
class AISystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class AISystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    AISystem();

    void Initialize();
};
} // namespace AISystem
} // namespace Engine