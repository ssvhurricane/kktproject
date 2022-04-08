#include "EngineContextInstaller.h"

namespace Engine {
namespace _Context {

EngineContextInstaller::EngineContextInstaller(){}
void EngineContextInstaller::InstallBindings()
{  
   //  _injector = di::make_injector();

    // _injector.create<LogSystem::LogSystem>();
}

void EngineContextInstaller::CreateContext()
{
    InstallBindings();
}

} // namespace _context
} // namespace engine
