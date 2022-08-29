#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "../Base/ERenderMode.h"

#include "../OpenglRenderSystem/OpenglRenderSystem.h"
#include "../VulkanRenderSystem/VulkanRenderSystem.h"

namespace Engine {
namespace RenderSystem {
#ifdef _WIN32
class ENGINE_API RenderSystem : public ISystem
#else
#ifdef __APPLE__ 
class RenderSystem : public ISystem
#endif
#ifdef __linux__
class RenderSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class RenderSystem : public ISystem
#endif
#endif
{
private:

    IRenderSystem* _renderSystem;

    void DemoRender();

public:

    RenderSystem();

    void Initialize();

    void Configurate(ERenderSystemType eRennderSystemType, ERenderMode eRenderMode);

    void Render(bool bDemoMode = false);

    void UpdateRender();

}; 

} // namespace RenderSystem
} // namespace Engine