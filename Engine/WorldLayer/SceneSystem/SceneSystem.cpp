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
    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog("[WorldSystem]",  
                                            Engine::LogSystem::ELogType::Message,
                                            "CreateScene: " + name,
                                             Engine::LogSystem::ELogOutputLocationType::All);
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