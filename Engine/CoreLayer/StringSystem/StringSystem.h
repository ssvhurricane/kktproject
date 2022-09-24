#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace StringSystem{
#ifdef _WIN32
class ENGINE_API StringSystem : public ISystem
#else 
#ifdef __APPLE__
class StringSystem : public ISystem
#endif
#ifdef __linux__
class StringSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class StringSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   StringSystem();

    void Initialize();
};
} // namespace StringSystem
} // namespace Engine