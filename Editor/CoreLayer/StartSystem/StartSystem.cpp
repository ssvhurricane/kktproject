#include "StartSystem.h"

namespace Editor {
namespace StartSystem {

StartSystem::StartSystem()
{
    // TODO: Add engine context
    /*
    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Initialize...",
                                        Engine::LogSystem::ELogOutputLocationType::All);
    */
}

void StartSystem::Initialize()
{
    /*
  dynamic_cast<Engine::WorldSystem::WorldSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::WorldSystem))->Initialize();
*/
}

} // namespace StartSystem
} // namespace Editor