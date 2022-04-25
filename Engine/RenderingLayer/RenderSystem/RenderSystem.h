#pragma once

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "../Base/ERenderMode.h"

#include "../OpenglRenderSystem/OpenglRenderSystem.h"
#include "../WebglRenderSystem/WebglRenderSystem.h"
#include "../VulkanRenderSystem/VulkanRenderSystem.h"

namespace Engine {
namespace RenderSystem {

class ENGINE_API RenderSystem : public _Context::ISystem
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