#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace CRSystem{
#ifdef _WIN32
class ENGINE_API CRSystem : public ISystem
#else 
#ifdef __APPLE__
class CRSystem : public ISystem
#endif
#ifdef __linux__
class CRSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class CRSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    CRSystem();

    void Initialize();
};
} // namespace CRSystem
} // namespace Engine