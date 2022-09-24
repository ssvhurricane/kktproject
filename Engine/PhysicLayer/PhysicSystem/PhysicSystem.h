#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace PhysicSystem{
#ifdef _WIN32
class ENGINE_API PhysicSystem : public ISystem
#else 
#ifdef __APPLE__
class PhysicSystem : public ISystem
#endif
#ifdef __linux__
class PhysicSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class PhysicSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    PhysicSystem();

    void Initialize();
};
} // namespace PhysicSystem
} // namespace Engine