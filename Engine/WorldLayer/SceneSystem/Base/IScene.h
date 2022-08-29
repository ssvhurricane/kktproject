#pragma once

#include <string>
#include <vector>

#include "ESceneType.h"
#include "../../WorldSystem/Base/IWorld.h"

namespace Engine {
namespace SceneSystem {

struct IScene
{
   virtual void Initialize(std::string, ESceneType) = 0;

   virtual int GetId() = 0;
  
   virtual ESceneType GetType() = 0;

   virtual std::string GetName() = 0;
    
   virtual void SetOwner(WorldSystem::IWorld*) = 0;

   virtual WorldSystem::IWorld* GetOwner() = 0;
};

} // namespace SceneSystem
} // namespace Engine