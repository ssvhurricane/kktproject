#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace ParserSystem{
#ifdef _WIN32
class ENGINE_API ParserSystem : public ISystem
#else 
#ifdef __APPLE__
class ParserSystem : public ISystem
#endif
#ifdef __linux__
class ParserSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class ParserSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

   ParserSystem();

    void Initialize();
};
} // namespace ParserSystem
} // namespace Engine