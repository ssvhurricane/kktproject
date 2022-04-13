#include "SceneSystem.h"

namespace Engine {
namespace SceneSystem {

SceneSystem::SceneSystem(){}

void SceneSystem::Initialize(){}

void SceneSystem::CreateScene()
{
    // TODO:
   dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog("[SceneSystem]",  
                                            Engine::LogSystem::ELogType::Message,
                                            "CreateScene!",
                                             Engine::LogSystem::ELogOutputLocationType::All);
}

IScene* SceneSystem::GetScene(ESceneType eSceneType){}

} // namespace SceneSystem
} // namespace Engine