// This is non Context System.
#pragma once
#include <functional>
#include <vector>

#include "../../KKTEngine.h"

#include "../Base/IRenderSystem.h"
#include "../Base/ERenderSystemType.h"
#include "base_context/Defines.h"

// Maths.
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Shaders, Materials.
#include "../_Shader/Standard/StandardGLShader.h"
#include "../_Texture/Texture2D.h"

// Load files.
#include "../../CoreLayer/FileSystem/FileSystem.h"

// Object system.
#include "../../WorldLayer/ObjectSystem/ObjectSystem.h"
#include "../../WorldLayer/ObjectSystem/Objects/BasicObject/BasicObject.h"
#include "../../WorldLayer/ObjectSystem/_Component/CameraComponent/CameraComponent.h"
#include "../../WorldLayer/ObjectSystem/_Component/CameraComponent/Base/ECameraMovementMode.h"
#include "../../WorldLayer/ObjectSystem/_Component/TransformComponent/TransformComponent.h"

// Scene system.
#include "../../WorldLayer/SceneSystem/SceneSystem.h"
#include "../../WorldLayer/SceneSystem/Scenes/BasicScene.h"

// World system.
#include "../../WorldLayer/WorldSystem/WorldSystem.h"
#include "../../WorldLayer/WorldSystem/Words/BasicWorld/BasicWorld.h"

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
    void RenderWorld(Engine::WorldSystem::IWorld* world);

    void RenderScene(Engine::SceneSystem::IScene* scene);

    void RenderObject(Engine::ObjectSystem::IObject* object);

public:

    OpenglRenderSystem();

    int Render(bool bDemoMode);

    void Initialize();
}; 

} // namespace OpenglRenderSystem
} // namespace Engine