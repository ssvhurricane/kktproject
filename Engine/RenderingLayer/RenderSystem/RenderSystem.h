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

class ENGINE_API RenderSystem : public ISystem
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