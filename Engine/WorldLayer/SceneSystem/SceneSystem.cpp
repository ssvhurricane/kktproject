#include "SceneSystem.h"

namespace Engine {
namespace SceneSystem {

SceneSystem::SceneSystem()
{
    // TODO:
}

void SceneSystem::Initialize()
{
    // TODO:
}
   
void SceneSystem::CreateSceneByName(std::string name, ESceneType eSceneType)
{
    // TODO:
}

IScene* SceneSystem::GetSceneByName(std::string)
{
    // TODO:
    return NULL;
}

int SceneSystem::GetSceneId(std::string)
{
    // TODO:
    return -1;
}

IScene* SceneSystem::GetCurrentScene()
{
    // TODO::
    return NULL;
}

} // namespace SceneSystem
} // namespace Engine