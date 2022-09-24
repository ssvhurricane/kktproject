#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace NetworkSystem{
#ifdef _WIN32
class ENGINE_API NetworkSystem : public ISystem
#else 
#ifdef __APPLE__
class NetworkSystem : public ISystem
#endif
#ifdef __linux__
class NetworkSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class NetworkSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    NetworkSystem();

    void Initialize();
};
} // namespace NetworkSystem
} // namespace Engine