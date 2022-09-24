#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace LocalizationSystem{
#ifdef _WIN32
class ENGINE_API LocalizationSystem : public ISystem
#else 
#ifdef __APPLE__
class LocalizationSystem : public ISystem
#endif
#ifdef __linux__
class LocalizationSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class LocalizationSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   LocalizationSystem();

    void Initialize();
};
} // namespace LocalizationSystem
} // namespace Engine