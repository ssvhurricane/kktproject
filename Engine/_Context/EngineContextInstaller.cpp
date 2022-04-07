#include "EngineContextInstaller.h"

namespace Engine {
namespace _Context {
   
EngineContextInstaller::EngineContextInstaller(){}
    
EngineContextInstaller::~EngineContextInstaller(){}

void EngineContextInstaller::InstallBindings()
{  
   //  _injector = di::make_injector();

    // _injector.create<LogSystem::LogSystem>();
}

void EngineContextInstaller::CreateContext()
{
    InstallBindings();
}

 void cplusplus_callback_CreateContext(EngineContextInstaller* engineContextInstaller)
 {
    engineContextInstaller->CreateContext();
 }

} // namespace _context
} // namespace engine
