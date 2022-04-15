#include "WorldSystem.h"

namespace Engine {
namespace WorldSystem {

WorldSystem::WorldSystem()
{
    // TODO:
}

void  WorldSystem::Initialize()
{
    // TODO:
}

void WorldSystem::CreateWorldByName(std::string name, EWorldType eWorldType)
{
    // TODO:
    
 dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog("[WorldSystem]",  
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