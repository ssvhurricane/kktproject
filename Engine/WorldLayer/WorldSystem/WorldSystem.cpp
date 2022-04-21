#include "WorldSystem.h"

namespace Engine {
namespace WorldSystem {

WorldSystem::WorldSystem()
{
    /*
   dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Create WorldSystem.",
                                        Engine::LogSystem::ELogOutputLocationType::All);*/
}

void  WorldSystem::Initialize()
{
    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Initialize.",
                                        Engine::LogSystem::ELogOutputLocationType::All);
}

void WorldSystem::CreateWorldByName(std::string name, EWorldType eWorldType)
{
    // TODO:
    
 dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "CreateWorld: " + name,
                                        Engine::LogSystem::ELogOutputLocationType::All);
}

IWorld* WorldSystem::GetWorldByName(std::string name)
{
    // TODO:
    return NULL;
} 

int GetWorldId(std::string)
{
    // TODO:
    return -1;
}

IWorld* GetCurrentWorld()
{
    // TODO:
    return NULL;
}

} // namespace WorldSystem
} // namespace Engine