#pragma once

#include "map"

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/ESceneType.h"
#include "Base/IScene.h"

namespace Engine {
namespace SceneSystem {

class ENGINE_API SceneSystem : public ISystem
{
private: 

   std::map<ESceneType, IScene*> _scenes;

public:

    SceneSystem();

    void Initialize();
   
    void CreateSceneByName(std::string name, ESceneType eSceneType = ESceneType::BasicScene);

    IScene* GetSceneByName(std::string);

    int GetSceneId(std::string);

    IScene* GetCurrentScene();
};

} // namespace SceneSystem
} // namespace Engine