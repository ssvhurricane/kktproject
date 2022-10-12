#pragma once

#include "../../KKTEngine.h" // Include only systems and components.
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace TestSystem{
#ifdef _WIN32
class ENGINE_API TestSystem : public ISystem
#else 
#ifdef __APPLE__
class TestSystem : public ISystem
#endif
#ifdef __linux__
class TestSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class TestSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    TestSystem();

    void Initialize();
};
} // namespace TestSystem
} // namespace Engine