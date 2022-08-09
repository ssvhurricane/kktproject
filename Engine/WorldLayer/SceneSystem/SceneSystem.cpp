#include "SceneSystem.h"

namespace Engine {
namespace SceneSystem {

SceneSystem::SceneSystem()
{
    /*
    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Create SceneSystem.",
                                         Engine::LogSystem::ELogOutputLocationType::All);*/
}

void SceneSystem::Initialize()
{
    // TODO:
}
   
IScene* SceneSystem::CreateSceneByName(std::string name, Engine::WorldSystem::IWorld* owner, ESceneType eSceneType)
{
   IScene* scene = NULL;

   if(!MapContainsKey(_scenes, name))
   {
   switch(eSceneType)
   {
    case Engine::SceneSystem::ESceneType::BasicScene:
    {
        scene = new class Engine::SceneSystem::BasicScene;

        _scenes.emplace(name, scene);

        scene->SetOwner(owner);

        break;
    }
    default:
     break;
   }

    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "CreateScene: " + name,
                                         Engine::LogSystem::ELogOutputLocationType::All);
    }
    else
    {
        dynamic_cast<Engine::LogSystem::LogSystem*>
        (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Warning,
                                        "The scene: " + name + " has already been created!",
                                        Engine::LogSystem::ELogOutputLocationType::All);
    }

    return scene;
}

IScene* SceneSystem::GetSceneByName(std::string name)
{
     auto item = _scenes.find(name);

    if (item == _scenes.end()) 
    {
        dynamic_cast<Engine::LogSystem::LogSystem*>
        (Engine::KKTEngine::InstancePtr()
                                    ->GetContext()
                                    ->GetSystem(ESystemType::LogSystem))
                                    ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                            typeid(this).name(),  
                                            Engine::LogSystem::ELogType::Error,
                                            "The scene " + name + " not found!",
                                            Engine::LogSystem::ELogOutputLocationType::All);
        return NULL;
    } 
    else 
        return  item->second;
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
 
bool SceneSystem::MapContainsKey(std::map<std::string, IScene*>& map, std::string key)
{
    if (map.find(key) == map.end()) return false;
    return true;
}
} // namespace SceneSystem
} // namespace Engine