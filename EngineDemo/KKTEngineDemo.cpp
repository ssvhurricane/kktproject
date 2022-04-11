#include <KKTEngine.h>
#include <LogSystem.h>
#include <Base/ELogType.h>
#include <iostream>
#include "di.hpp"

int main()
{
    Engine::KKTEngine* gameEngine = Engine::KKTEngine::InstancePtr();

    gameEngine->InitialEngine();
    
    Engine::_Context::IContextInstaller* engineContext = gameEngine->GetContext();

    Engine::LogSystem::LogSystem* logSystem = nullptr;

    engineContext->GetSystem(logSystem);

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