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
}

ESceneType BasicScene::GetType()
{
    // TODO:
}

std::string BasicScene::GetName()
{
    // TODO:
}     
        
void BasicScene::SetOwner(WorldSystem::IWorld*)
{
    // TODO:
}

WorldSystem::IWorld* BasicScene::GetOwner()
{
    // TODO:
}

std::vector<ObjectSystem::IObject*> BasicScene::GetCurrentOBjects()
{
    // TODO:
}

void BasicScene::AddObjectOnScene(std::vector<ObjectSystem::IObject*>)
{
    // TODO:
}

void BasicScene::RemoveObjectByName(std::string name)
{
    // TODO:
}

} // namespace SceneSystem
} // namespace Engine
