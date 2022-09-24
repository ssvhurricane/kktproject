#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace RTTISystem{
#ifdef _WIN32
class ENGINE_API RTTISystem : public ISystem
#else 
#ifdef __APPLE__
class RTTISystem : public ISystem
#endif
#ifdef __linux__
class RTTISystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class RTTISystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   RTTISystem();

    void Initialize();
};
} // namespace RTTISystem
} // namespace Engine