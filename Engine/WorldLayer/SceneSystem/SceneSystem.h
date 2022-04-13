#pragma once

#include "vector"

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "Base/ESceneType.h"
#include "Base/IScene.h"

namespace Engine {
namespace SceneSystem {

class ENGINE_API SceneSystem : public _Context::ISystem
{
private: 

   std::vector<IScene*> _scenes;

public:
    SceneSystem();

    void Initialize();

    void CreateScene();

    IScene* GetScene(ESceneType);
};

} // namespace WorldSystem
} // namespace Engine