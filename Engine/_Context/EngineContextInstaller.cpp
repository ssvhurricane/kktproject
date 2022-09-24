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
     std::cout << "[EngineLayer] -> [" << typeid(this).name() << "] -> [Install bindings start proccess...]" << std::endl;

    // Add core systems.
    _systems.emplace(ESystemType::LogSystem, new Engine::LogSystem::LogSystem); 
    _systems.emplace(ESystemType::AnalyticSystem, new Engine::AnalyticSystem::AnalyticSystem);
    _systems.emplace(ESystemType::ApprovalSystem, new Engine::ApprovalSystem::ApprovalSystem);
    _systems.emplace(ESystemType::ConfigSystem, new Engine::ConfigSystem::ConfigSystem);
    _systems.emplace(ESystemType::CRSystem, new Engine::CRSystem::CRSystem);
    _systems.emplace(ESystemType::FileSystem, new Engine::FileSystem::FileSystem);
    _systems.emplace(ESystemType::LocalizationSystem, new Engine::LocalizationSystem::LocalizationSystem);
    _systems.emplace(ESystemType::MathSystem, new Engine::MathSystem::MathSystem);
    _systems.emplace(ESystemType::MemorySystem, new Engine::MemorySystem::MemorySystem);
    _systems.emplace(ESystemType::ParserSystem, new Engine::ParserSystem::ParserSystem);
    _systems.emplace(ESystemType::RandomNumGenSystem, new Engine::RandomNumGenSystem::RandomNumGenSystem);
    _systems.emplace(ESystemType::RTTISystem, new Engine::RTTISystem::RTTISystem);
    _systems.emplace(ESystemType::StringSystem, new Engine::StringSystem::StringSystem);
    _systems.emplace(ESystemType::VideoSystem, new Engine::VideoSystem::VideoSystem);

    // Input systems.
    _systems.emplace(ESystemType::InputSystem, new Engine::InputSystem::InputSystem);

    // Network systems.
    _systems.emplace(ESystemType::NetworkSystem, new Engine::NetworkSystem::NetworkSystem);

    // Physic systems.
    _systems.emplace(ESystemType::PhysicSystem, new Engine::PhysicSystem::PhysicSystem);

    // Profiling systems.
    _systems.emplace(ESystemType::ProfilingSystem, new Engine::ProfilingSystem::ProfilingSystem);

    // UI systems.
    _systems.emplace(ESystemType::UISystem, new Engine::UISystem::UISystem);
   
    // Render Systems.
    _systems.emplace(ESystemType::RenderSystem, new Engine::RenderSystem::RenderSystem);

     // Resource Systems.
    _systems.emplace(ESystemType::ResourceSystem, new Engine::ResourceSystem::ResourceSystem);

    // Test systems.
    _systems.emplace(ESystemType::TestSystem, new Engine::TestSystem::TestSystem);

    // World Systems
    _systems.emplace(ESystemType::WorldSystem, new Engine::WorldSystem::WorldSystem);
    _systems.emplace(ESystemType::SceneSystem, new Engine::SceneSystem::SceneSystem);
    _systems.emplace(ESystemType::ObjectSystem, new Engine::ObjectSystem::ObjectSystem);
    _systems.emplace(ESystemType::ProjectSubSystem, new Engine::ProjectSubSystem::ProjectSubSystem);
    _systems.emplace(ESystemType::SceneSubSystem, new Engine::SceneSubSystem::SceneSubSystem);
   
    _systems.emplace(ESystemType::AISystem, new Engine::AISystem::AISystem);
   
    _systems.emplace(ESystemType::AnimationSystem, new Engine::AnimationSystem::AnimationSystem); 
  
    _systems.emplace(ESystemType::AudioSystem, new Engine::AudioSystem::AudioSystem);

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
