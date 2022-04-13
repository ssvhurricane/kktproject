#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

int main()
{
    Engine::KKTEngine* gameEngine = Engine::KKTEngine::InstancePtr(); // Create Engine.

    gameEngine->InitialEngine();
    
    Engine::_Context::IContextInstaller* engineContext = gameEngine->GetContext();
  
   // LogSystem.
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

    // RenderSystem.
    auto renderSystem =  dynamic_cast<Engine::RenderSystem::RenderSystem*>(engineContext
                                                            ->GetSystem(Engine::_Context::ESystemType::RenderSystem));

    renderSystem->DemoRender();

    // WorldSystem. 
    auto worldSystem = dynamic_cast<Engine::WorldSystem::WorldSystem*>(engineContext
                                                            ->GetSystem(Engine::_Context::ESystemType::WorldSystem));

    worldSystem->CreateWorld();

    // SceneSystem. 
    auto sceneSystem = dynamic_cast<Engine::SceneSystem::SceneSystem*>(engineContext
                                                            ->GetSystem(Engine::_Context::ESystemType::SceneSystem));
                                        
    
    sceneSystem->CreateScene();
    
    // Start Engine(Runtime).
    gameEngine->StartEngine();
  
    return 0;
}