#pragma once

#include "../../../KKTEngine.h"
#include "../../../_Context/Base/ISystem.h"
#include "../../../_Context/Base/Defines.h"
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

    virtual std::vector<ObjectSystem::IObject*> GetCurrentOBjects(); 

    virtual void AddObjectOnScene(std::vector<ObjectSystem::IObject*>);

    virtual void RemoveObjectByName(std::string name);

};

} // namespace SceneSystem
} // namespace Engine
