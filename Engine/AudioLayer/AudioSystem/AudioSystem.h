#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace AudioSystem{
#ifdef _WIN32
class ENGINE_API AudioSystem : public ISystem
#else 
#ifdef __APPLE__
class AudioSystem : public ISystem
#endif
#ifdef __linux__
class AudioSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class AudioSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    AudioSystem();

    void Initialize();
};
} // namespace AudioSystem
} // namespace Engine