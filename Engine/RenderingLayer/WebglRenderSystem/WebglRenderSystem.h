// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace WebglRenderSystem {
#if defined _WIN32
class ENGINE_API WebglRenderSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class WebglRenderSystem : public ISystem
#endif
{
private:
    // TODO:
public:

    WebglRenderSystem();

    void Initialize();
}; 

} // namespace WebglRenderSystem
} // namespace Engine