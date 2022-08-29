#pragma once

#include "map"

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/ESceneType.h"
#include "Base/IScene.h"
#include "Scenes/BasicScene.h"

namespace Engine {
namespace SceneSystem {
#ifdef _WIN32
class ENGINE_API SceneSystem : public ISystem
#else
#ifdef __APPLE__ 
class SceneSystem : public ISystem
#endif
#ifdef __linux__
class SceneSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class SceneSystem : public ISystem
#endif
#endif
{
private: 

   std::map<std::string, IScene*> _scenes; 

   bool MapContainsKey(std::map<std::string, IScene*>& map, std::string key);

public:

    SceneSystem();

    void Initialize();
   
    IScene* CreateSceneByName(std::string name, Engine::WorldSystem::IWorld* owner, ESceneType eSceneType = ESceneType::BasicScene);

    IScene* GetSceneByName(std::string);

    int GetSceneId(std::string);

    IScene* GetCurrentScene();

   
};

} // namespace SceneSystem
} // namespace Engine