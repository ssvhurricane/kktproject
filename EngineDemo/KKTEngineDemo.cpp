#include <KKTEngine.h>
#include <iostream>
#include <typeinfo>
#include "di.hpp"

int main()
{
    Engine::KKTEngine* gameEngine = Engine::KKTEngine::InstancePtr();

    gameEngine->InitialEngine();
    
    Engine::_Context::IContextInstaller* engineContext = gameEngine->GetContext();
  
    auto logSystem 
    = dynamic_cast<Engine::LogSystem::LogSystem*>(engineContext->GetSystem(Engine::_Context::ESystemType::LogSystem));

    if(logSystem)
    { 
         logSystem->Initialize(); 

         logSystem->ShowLog("Item",  
             Engine::LogSystem::ELogType::Message,
             "LogMessage!",
             Engine::LogSystem::ELogOutputLocationType::All);
    }

    gameEngine->StartEngine();
  
    return 0;
}