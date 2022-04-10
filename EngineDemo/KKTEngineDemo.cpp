#include <KKTEngine.h>
#include <LogSystem.h>
#include <Base/ELogType.h>
#include <iostream>
#include "di.hpp"

int main()
{
    Engine::KKTEngine* gameEngine = new Engine::KKTEngine();

    gameEngine->InitialEngine();
    
    Engine::_Context::IContextInstaller* engineContext = gameEngine->GetContext();

    auto logSystem = new Engine::LogSystem::LogSystem();

    engineContext->GetSystem(logSystem); //TODO: 

    logSystem->Initialize();

    logSystem->ShowLog("Item",  
        Engine::LogSystem::ELogType::Message,
         "LogMessage!",
          Engine::LogSystem::ELogOutputLocationType::All);

    gameEngine->StartEngine();
  
    return 0;
}