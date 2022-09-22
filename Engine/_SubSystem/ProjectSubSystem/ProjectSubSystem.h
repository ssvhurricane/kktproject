// TODO:  Developer custom project system.

#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace ProjectSubSystem{
#ifdef _WIN32
class ENGINE_API ProjectSubSystem : public ISystem
#else 
#ifdef __APPLE__
class ProjectSubSystem : public ISystem
#endif
#ifdef __linux__
class ProjectSubSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class ProjectSubSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    ProjectSubSystem();

    void Initialize();
};
} // namespace ProjectSubSystem
} // namespace Engine