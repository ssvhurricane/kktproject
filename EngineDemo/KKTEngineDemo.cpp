#include <KKTEngine.h>
#include <iostream>

#include "boost/di.hpp"

#include "base_context/IContextInstaller.h"
#include "base_context/ESystemType.h"

int main()
{
    // Create and Init GameEngine.
    Engine::KKTEngine* gameEngine = Engine::KKTEngine::InstancePtr(); // Create Engine.

    gameEngine->InitialEngine();
    
    IContextInstaller* engineContext = gameEngine->GetContext();
  
   // Example, LogSystem.
    auto logSystem 
    = dynamic_cast<Engine::LogSystem::LogSystem*>(engineContext->GetSystem(ESystemType::LogSystem));

    if(logSystem)
    { 
         logSystem->Initialize(); 

         logSystem->ShowLog(Engine::LogSystem::ELogLayer::Game, 
             "Game",  
             Engine::LogSystem::ELogType::Message,
             "LogMessage!",
             Engine::LogSystem::ELogOutputLocationType::All);
    }

    // Example for EditMode.
    // RenderSystem.
    auto renderSystem = dynamic_cast<Engine::RenderSystem::RenderSystem*>(engineContext
                                                            ->GetSystem(ESystemType::RenderSystem));

    renderSystem->Configurate(Engine::RenderSystem::ERenderSystemType::OpenGL, Engine::RenderSystem::ERenderMode::Edit);

    renderSystem->Render(true);

    // WorldSystem. 
    auto worldSystem = dynamic_cast<Engine::WorldSystem::WorldSystem*>(engineContext
                                                            ->GetSystem(ESystemType::WorldSystem));

    worldSystem->CreateWorldByName("GameWorld");

    // SceneSystem. 
    auto sceneSystem = dynamic_cast<Engine::SceneSystem::SceneSystem*>(engineContext
                                                            ->GetSystem(ESystemType::SceneSystem));
                                        
    
    sceneSystem->CreateSceneByName("MainScene");

    // ObjectSystem. 
    auto objectSystem = dynamic_cast<Engine::ObjectSystem::ObjectSystem*>(engineContext
                                                            ->GetSystem(ESystemType::ObjectSystem));
                                        
    
    objectSystem->CreateObjectByName("GameObject");

    // Start Engine(Runtime).
    gameEngine->StartEngine();

    // Example For GameMode, etc.
    // ...
    
    return 0;
}