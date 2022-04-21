#include "StartSystem.h"

namespace Engine {
namespace StartSystem {

StartSystem::StartSystem()
{
    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Create StartSystem.",
                                        Engine::LogSystem::ELogOutputLocationType::All);
}

void StartSystem::Initialize()
{
    dynamic_cast<Engine::WorldSystem::WorldSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::WorldSystem))->Initialize();

}

} // namespace StartSystem
} // namespace Engine