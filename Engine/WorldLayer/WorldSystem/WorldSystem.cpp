#include "WorldSystem.h"

namespace Engine {
namespace WorldSystem {

WorldSystem::WorldSystem()
{
   // TODO: load config data, etc.
}

void  WorldSystem::Initialize()
{
    dynamic_cast<Engine::LogSystem::LogSystem*>
    (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Initialize...",
                                        Engine::LogSystem::ELogOutputLocationType::All);
    
    auto renderSystem = dynamic_cast<Engine::RenderSystem::RenderSystem*>
     (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::RenderSystem));

    renderSystem->Configurate(Engine::RenderSystem::ERenderSystemType::OpenGL, Engine::RenderSystem::ERenderMode::Edit);

    renderSystem->Render(true);

}

void WorldSystem::CreateWorldByName(std::string name, EWorldType eWorldType)
{
    if(!MapContainsKey(_worlds, name))
    {
    switch(eWorldType)
    {
        case EWorldType::BasicWorld:
        {
            auto basicWorld = new class Engine::WorldSystem::BasicWorld();

           _worlds.emplace(name, basicWorld);

            basicWorld->Initialize(name, Engine::WorldSystem::EWorldType::BasicWorld, Engine::WorldSystem::EWorldMode::Combine);

            break;
        }

        case EWorldType::AppWorld:
        {
            auto appWorld = new class Engine::WorldSystem::AppWorld();

           _worlds.emplace(name, appWorld);

            appWorld->Initialize(name, Engine::WorldSystem::EWorldType::AppWorld, Engine::WorldSystem::EWorldMode::Combine);

            break;
        }

        case EWorldType::ARWorld:
        {
            auto arWorld = new class Engine::WorldSystem::ARWorld();

            _worlds.emplace(name, arWorld);

            arWorld->Initialize(name, Engine::WorldSystem::EWorldType::ARWorld, Engine::WorldSystem::EWorldMode::Combine);

            break;
        }

         case EWorldType::VRWorld:
        {
            auto vrWorld = new class Engine::WorldSystem::VRWorld();

            _worlds.emplace(name, vrWorld);

            vrWorld->Initialize(name, Engine::WorldSystem::EWorldType::VRWorld, Engine::WorldSystem::EWorldMode::Combine);

            break;
        }

    }

    dynamic_cast<Engine::LogSystem::LogSystem*>
     (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "CreateWorld: " + name,
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
                                        "The world: " + name + " has already been created!",
                                        Engine::LogSystem::ELogOutputLocationType::All);
    }

    dynamic_cast<Engine::LogSystem::LogSystem*>
    (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Created Words: " +std::to_string(_worlds.size()),
                                        Engine::LogSystem::ELogOutputLocationType::All);
}


IWorld* WorldSystem::GetWorldByName(std::string name)
{
    // TODO:
    return NULL;
} 

int WorldSystem::GetWorldId(std::string)
{
    // TODO:
    return -1;
}

IWorld* WorldSystem::GetCurrentWorld()
{
    // TODO:
    return NULL;
}

bool WorldSystem::MapContainsKey(std::map<std::string, IWorld*>& map, std::string key)
{
  if (map.find(key) == map.end()) return false;
  return true;
}

} // namespace WorldSystem
} // namespace Engine