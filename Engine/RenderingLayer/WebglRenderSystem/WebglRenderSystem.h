// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"

#include "base_context/Defines.h"

namespace Engine {
namespace WebglRenderSystem {
#if defined _WIN32
class ENGINE_API WebglRenderSystem : public RenderSystem::IRenderSystem
#elif defined __APPLE__  || defined __linux__
class WebglRenderSystem : public RenderSystem::IRenderSystem
#endif
{
private:
    // TODO:
public:

    WebglRenderSystem();

    int Render(bool bDemoMode);

    void Initialize();
}; 

} // namespace WebglRenderSystem
} // namespace Engine