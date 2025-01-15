// This is non Context System.
#pragma once

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "base_context/Defines.h"

namespace Editor {
namespace OpenglRenderSystem {
#ifdef _WIN32
class ENGINE_API OpenglRenderSystem : public RenderSystem::IRenderSystem
#else 
#ifdef __APPLE__ 
class OpenglRenderSystem : public RenderSystem::IRenderSystem
#endif
#ifdef __linux__
class OpenglRenderSystem : public RenderSystem::IRenderSystem
#endif
#ifdef __EMSCRIPTEN__
class OpenglRenderSystem : public RenderSystem::IRenderSystem
#endif
#endif
{
public:

    OpenglRenderSystem();

    int Render(bool bDemoMode);

    void Initialize();
}; 

} // namespace OpenglRenderSystem
} // namespace Editor