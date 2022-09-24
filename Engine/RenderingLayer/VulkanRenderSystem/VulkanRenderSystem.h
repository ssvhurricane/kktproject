// This is non Context System. Only PC.
#pragma once

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"

#include "base_context/Defines.h"

namespace Engine {
namespace VulkanRenderSystem {
#ifdef _WIN32
class ENGINE_API VulkanRenderSystem : public RenderSystem::IRenderSystem
#else
#ifdef __APPLE__ 
class VulkanRenderSystem : public RenderSystem::IRenderSystem
#endif
#ifdef __linux__
class VulkanRenderSystem : public RenderSystem::IRenderSystem
#endif
#ifdef __EMSCRIPTEN__
class VulkanRenderSystem : public RenderSystem::IRenderSystem
#endif
#endif
{
private:
    // TODO:
public:

    VulkanRenderSystem();

    int Render(bool bDemoMode);

    void Initialize();
}; 

} // namespace VulkanRenderSystem
} // namespace Engine