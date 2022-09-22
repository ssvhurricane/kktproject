// TODO:  Developer custom scene system.
#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace SceneSubSystem{
#ifdef _WIN32
class ENGINE_API SceneSubSystem : public ISystem
#else 
#ifdef __APPLE__
class SceneSubSystem : public ISystem
#endif
#ifdef __linux__
class SceneSubSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class SceneSubSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    SceneSubSystem();

    void Initialize();
    
};
} // namespace SceneSubSystem
} // namespace Engine