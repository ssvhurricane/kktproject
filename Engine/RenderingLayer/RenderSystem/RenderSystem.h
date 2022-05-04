#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "../Base/ERenderMode.h"

#include "../OpenglRenderSystem/OpenglRenderSystem.h"
#include "../WebglRenderSystem/WebglRenderSystem.h"
#include "../VulkanRenderSystem/VulkanRenderSystem.h"

namespace Engine {
namespace RenderSystem {
#if defined _WIN32
class ENGINE_API RenderSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class RenderSystem : public ISystem
#endif
{
private:

    IRenderSystem* _renderSystem;

public:

    RenderSystem();

    void Initialize();

    void Configurate(ERenderSystemType eRennderSystemType, ERenderMode eRenderMode);

    int Render(bool bDemoMode = false);
}; 

} // namespace RenderSystem
} // namespace Engine