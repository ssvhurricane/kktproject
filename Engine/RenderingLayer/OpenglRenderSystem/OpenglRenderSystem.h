// This is non Context System.
#pragma once
#include <functional>
#include <vector>

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "base_context/Defines.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../_Shader/Standard/StandardGLShader.h"
#include "../_Texture/Texture2D.h"
#include "../../CoreLayer/FileSystem/FileSystem.h"

namespace Engine {
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
private:
    // TODO:
public:

    OpenglRenderSystem();

    int Render(bool bDemoMode);

    void Initialize();
}; 

} // namespace OpenglRenderSystem
} // namespace Engine