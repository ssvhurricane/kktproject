#pragma once

#include "../../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../Base/ESceneType.h"
#include "../Base/IScene.h"

namespace Engine {
namespace SceneSystem {

class BasicScene : public IScene
{
private:

public:

    BasicScene();

    void Initialize(std::string, ESceneType);

    int GetId();

    ESceneType GetType();

    std::string GetName();
        
    void SetOwner(WorldSystem::IWorld*);

    WorldSystem::IWorld* GetOwner();

   // std::vector<ObjectSystem::IObject*> GetCurrentOBjects(); 

   // void AddObjectOnScene(std::vector<ObjectSystem::IObject*>);

    //void RemoveObjectByName(std::string name);

};

} // namespace SceneSystem
} // namespace Engine
