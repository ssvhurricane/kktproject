#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace AnalyticSystem{
#ifdef _WIN32
class ENGINE_API AnalyticSystem : public ISystem
#else 
#ifdef __APPLE__
class AnalyticSystem : public ISystem
#endif
#ifdef __linux__
class AnalyticSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class AnalyticSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    AnalyticSystem();

    void Initialize();
};
} // namespace AnalyticSystem
} // namespace Engine