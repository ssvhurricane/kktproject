#pragma once

#include <string>
#include <vector>

#include "ESceneType.h"
#include "../../WorldSystem/Base/IWorld.h"
#include "../../ObjectSystem/Base/IObject.h"

namespace Engine {
namespace SceneSystem {

struct IScene
 {
    virtual void Initialize(std::string, ESceneType) = 0;

    virtual int GetId() = 0;

    virtual ESceneType GetType() = 0;

    virtual std::string GetName() = 0;
    
    virtual void SetOwner(WorldSystem::IWorld*);

    virtual WorldSystem::IWorld* GetOwner();

    virtual std::vector<ObjectSystem::IObject*> GetCurrentOBjects() = 0; 

    virtual void AddObjectOnScene(std::vector<ObjectSystem::IObject*>);

    virtual void RemoveObjectByName(std::string name);
    
 };

} // namespace SceneSystem
} // namespace Engine