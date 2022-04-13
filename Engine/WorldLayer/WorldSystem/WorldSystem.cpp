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

void  WorldSystem::CreateWorld()
{
    // TODO:
    
 dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog("[WorldSystem]",  
                                            Engine::LogSystem::ELogType::Message,
                                            "CreateWorld!",
                                             Engine::LogSystem::ELogOutputLocationType::All);
}

IWorld*  WorldSystem::GetWorld(EWorldType)
{
    // TODO:
}

} // namespace WorldSystem
} // namespace Engine