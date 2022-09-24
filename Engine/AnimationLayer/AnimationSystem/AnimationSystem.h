#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace AnimationSystem{
#ifdef _WIN32
class ENGINE_API AnimationSystem : public ISystem
#else 
#ifdef __APPLE__
class AnimationSystem : public ISystem
#endif
#ifdef __linux__
class AnimationSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class AnimationSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    AnimationSystem();

    void Initialize();
};
} // namespace AnimationSystem
} // namespace Engine