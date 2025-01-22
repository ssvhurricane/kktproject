#include "EditorContextInstaller.h"

namespace Editor {
namespace _Context {

EditorContextInstaller::EditorContextInstaller()
{
     std::cout<< "[EditorLayer] -> [" << typeid(this).name() << "] -> [Create Installer.]" << std::endl;

    CreateContext();
}

void EditorContextInstaller::InstallBindings()
{
    std::cout << "[EditorLayer] -> [" << typeid(this).name() << "] -> [Install bindings start proccess...]" << std::endl;

    // Add core systems.
    _systems.emplace(ESystemType::ConfigSystem, new Editor::ConfigSystem::ConfigSystem);
    _systems.emplace(ESystemType::LogSystem, new Editor::LogSystem::LogSystem); 
    
     // Render Systems.
    _systems.emplace(ESystemType::RenderSystem, new Editor::RenderSystem::RenderSystem);
  
    // UI systems.
    _systems.emplace(ESystemType::UISystem, new Editor::UISystem::UISystem);

   
    std::cout << "[EditorLayer] -> [" << typeid(this).name() << "] -> [Install bindings stop proccess.]" << std::endl;
}

void EditorContextInstaller::CreateContext()
{
    InstallBindings();
}

ISystem* EditorContextInstaller::GetSystem(ESystemType eSystemType)
{
    return _systems[eSystemType];
}

} // namespace _Context
} // namespace Editor