#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

int main()
{
    Engine::KKTEngine* gameEngine = Engine::KKTEngine::InstancePtr(); // Create Engine.

    gameEngine->InitialEngine();
    
    Engine::_Context::IContextInstaller* engineContext = gameEngine->GetContext();
  
    auto logSystem 
    = dynamic_cast<Engine::LogSystem::LogSystem*>(engineContext->GetSystem(Engine::_Context::ESystemType::LogSystem));

    if(logSystem)
    { 
         logSystem->Initialize(); 

         logSystem->ShowLog("[LogSystemTest]",  
             Engine::LogSystem::ELogType::Message,
             "LogMessage!",
             Engine::LogSystem::ELogOutputLocationType::All);
    }

    auto rendersystem =  dynamic_cast<Engine::RenderSystem::RenderSystem*>(engineContext->GetSystem(Engine::_Context::ESystemType::RenderSystem));

    rendersystem->DemoRender();

    gameEngine->StartEngine();
  
    return 0;
}