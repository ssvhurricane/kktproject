#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace VideoSystem{
#ifdef _WIN32
class ENGINE_API VideoSystem : public ISystem
#else 
#ifdef __APPLE__
class VideoSystem : public ISystem
#endif
#ifdef __linux__
class VideoSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class VideoSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   VideoSystem();

    void Initialize();
};
} // namespace VideoSystem
} // namespace Engine