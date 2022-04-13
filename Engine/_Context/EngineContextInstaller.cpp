#include "EngineContextInstaller.h"

namespace Engine {
namespace _Context {

EngineContextInstaller::EngineContextInstaller()
{
    CreateContext();
}

void EngineContextInstaller::InstallBindings()
{  
    // This add new LogSysyem
    // etc Systems, order matters.

    // 1. Add LogSystem.
    _systems.emplace(ESystemType::LogSystem, new Engine::LogSystem::LogSystem);

    // 2. Add RenderSystem.
    _systems.emplace(ESystemType::RenderSystem, new Engine::RenderSystem::RenderSystem);

    // 3. Add WorldSystem. 
    _systems.emplace(ESystemType::WorldSystem, new Engine::WorldSystem::WorldSystem);

    // 4. Add SceneSystem.
    _systems.emplace(ESystemType::SceneSystem, new Engine::SceneSystem::SceneSystem);

    std::cout<< "Install Bindings Method!"<< std::endl;
}

void EngineContextInstaller::CreateContext()
{
      std::cout<< "Create Context Method!"<< std::endl;

    InstallBindings();
}

ISystem* EngineContextInstaller::GetSystem(ESystemType eSystemType)
{
    std::cout<< "Get System Method!"<< std::endl;

    return _systems[eSystemType];
}

} // namespace _context
} // namespace engine
