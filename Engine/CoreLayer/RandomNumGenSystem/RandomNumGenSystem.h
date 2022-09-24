#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace RandomNumGenSystem{
#ifdef _WIN32
class ENGINE_API RandomNumGenSystem : public ISystem
#else 
#ifdef __APPLE__
class RandomNumGenSystem : public ISystem
#endif
#ifdef __linux__
class RandomNumGenSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class RandomNumGenSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   RandomNumGenSystem();

    void Initialize();
};
} // namespace RandomNumGenSystem
} // namespace Engine