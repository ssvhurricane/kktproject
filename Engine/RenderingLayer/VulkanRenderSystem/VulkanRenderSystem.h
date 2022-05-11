// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"

#include "base_context/Defines.h"

namespace Engine {
namespace VulkanRenderSystem {
#if defined _WIN32
class ENGINE_API VulkanRenderSystem : public RenderSystem::IRenderSystem
#elif defined __APPLE__  || defined __linux__
class VulkanRenderSystem : public RenderSystem::IRenderSystem
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