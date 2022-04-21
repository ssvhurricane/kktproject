#include "EngineContextInstaller.h"

namespace Engine {
namespace _Context {

EngineContextInstaller::EngineContextInstaller()
{
    std::cout<< "[EngineLayer] -> [" << typeid(this).name() << "] -> [Create Installer.]" << std::endl;

    CreateContext();
}

void EngineContextInstaller::InstallBindings()
{  
    // This add new LogSysyem
    // etc Systems, order matters.

     std::cout << "[EngineLayer] -> [" << typeid(this).name() << "] -> [Install bindings start proccess...]" << std::endl;

    // 1. Add LogSystem.
    _systems.emplace(ESystemType::LogSystem, new Engine::LogSystem::LogSystem);

    // 2. Add RenderSystem.
    _systems.emplace(ESystemType::RenderSystem, new Engine::RenderSystem::RenderSystem);

    // 3. Add WorldSystem. 
    _systems.emplace(ESystemType::WorldSystem, new Engine::WorldSystem::WorldSystem);

    // 4. Add SceneSystem.
    _systems.emplace(ESystemType::SceneSystem, new Engine::SceneSystem::SceneSystem);

    // 5. Add ObjectSystem.
    _systems.emplace(ESystemType::ObjectSystem, new Engine::ObjectSystem::ObjectSystem);

     std::cout << "[EngineLayer] -> [" << typeid(this).name() << "] -> [Install bindings stop proccess.]" << std::endl;
}

void EngineContextInstaller::CreateContext()
{
    InstallBindings();
}

ISystem* EngineContextInstaller::GetSystem(ESystemType eSystemType)
{
    return _systems[eSystemType];
}

} // namespace _context
} // namespace engine
