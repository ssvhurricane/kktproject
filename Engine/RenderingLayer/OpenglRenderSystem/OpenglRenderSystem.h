// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "base_context/Defines.h"

namespace Engine {
namespace OpenglRenderSystem {
#if defined _WIN32
class ENGINE_API OpenglRenderSystem : public RenderSystem::IRenderSystem
#elif defined __APPLE__  || defined __linux__
class OpenglRenderSystem : public RenderSystem::IRenderSystem
#endif
{
private:
    // TODO:
public:

    OpenglRenderSystem();

    int Render(bool bDemoMode);

    void Initialize();
}; 

} // namespace OpenglRenderSystem
} // namespace Engine