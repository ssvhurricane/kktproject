#include "EngineContextInstaller.h"

namespace Engine {
namespace _Context {

EngineContextInstaller::EngineContextInstaller()
{
    CreateContext();
}

void EngineContextInstaller::InstallBindings()
{  
    // _injector = di::make_injector();

    // _injector.create<LogSystem::LogSystem>(); 
    
    std::cout<< "Install Bindings Method!"<< std::endl;
}

void EngineContextInstaller::CreateContext()
{
      std::cout<< "Create Context Method!"<< std::endl;

    InstallBindings();
}

void EngineContextInstaller::GetSystem(ISystem* system)
{
    std::cout<< "Get System Method!"<< std::endl;

    if (!system)
    {
        std::cout<< "Bind System!"<< std::endl;
 // TODO:
    }
    else 
        system = nullptr;
}

} // namespace _context
} // namespace engine
