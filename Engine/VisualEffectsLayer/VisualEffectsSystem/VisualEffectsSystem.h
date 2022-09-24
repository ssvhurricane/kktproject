#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace VisualEffectsSystem{
#ifdef _WIN32
class ENGINE_API VisualEffectsSystem : public ISystem
#else 
#ifdef __APPLE__
class VisualEffectsSystem : public ISystem
#endif
#ifdef __linux__
class VisualEffectsSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class VisualEffectsSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    VisualEffectsSystem();

    void Initialize();
};
} // namespace VisualEffectsSystem
} // namespace Engine