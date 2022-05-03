#include "UIContextInstaller.h"

namespace UI {
namespace _Context {

UIContextInstaller::UIContextInstaller()
{ 
    std::cout<< "[EngineLayer] -> [" << typeid(this).name() << "] -> [Create Installer.]" << std::endl;

    CreateContext();
}

void UIContextInstaller::InstallBindings()
{  
    // This add new LogSysyem
    // etc Systems, order matters.

     std::cout << "[EngineLayer] -> [" << typeid(this).name() << "] -> [Install bindings start proccess...]" << std::endl;

    // 1. Add UISystem.
     _systems.emplace(ESystemType::UISystem, new UI::UISystem::UISystem);

     std::cout << "[EngineLayer] -> [" << typeid(this).name() << "] -> [Install bindings stop proccess.]" << std::endl;
}

void UIContextInstaller::CreateContext()
{

}

ISystem* UIContextInstaller::GetSystem(ESystemType)
{
    // TODO:
    return NULL;
}

} // namespace _Context
} // namespace UI