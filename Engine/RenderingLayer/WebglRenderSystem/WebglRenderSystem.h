// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"

#include "base_context/Defines.h"


namespace Engine {
namespace WebglRenderSystem {
#ifdef _WIN32
class ENGINE_API WebglRenderSystem : public RenderSystem::IRenderSystem
#else
#ifdef __APPLE__ // TODO:DEBUG
class WebglRenderSystem : public RenderSystem::IRenderSystem
#endif
#ifdef  __linux__ 
class WebglRenderSystem : public RenderSystem::IRenderSystem
#endif
#ifdef __EMSCRIPTEN__
class WebglRenderSystem : public RenderSystem::IRenderSystem
#endif
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