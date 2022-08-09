#include "BasicScene.h"

namespace Engine {
namespace SceneSystem {

BasicScene::BasicScene()
{
    // TODO:
}

void BasicScene::Initialize(std::string, ESceneType)
{
    // TODO:
}

int BasicScene::GetId()
{
    // TODO:
    return -1;
}

ESceneType BasicScene::GetType()
{
    // TODO:
    return ESceneType::BasicScene;
}

std::string BasicScene::GetName()
{
    // TODO:
    return "";
}     
        
void BasicScene::SetOwner(WorldSystem::IWorld*)
{
    // TODO:
}

WorldSystem::IWorld* BasicScene::GetOwner()
{
    // TODO:
    return NULL;
}

} // namespace SceneSystem
} // namespace Engine
