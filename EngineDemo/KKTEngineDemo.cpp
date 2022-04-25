#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

int main()
{
    // Create and Init GameEngine.
    Engine::KKTEngine* gameEngine = Engine::KKTEngine::InstancePtr(); // Create Engine.

    gameEngine->InitialEngine();
    
    Engine::_Context::IContextInstaller* engineContext = gameEngine->GetContext();
  
   // Example, LogSystem.
    auto logSystem 
    = dynamic_cast<Engine::LogSystem::LogSystem*>(engineContext->GetSystem(Engine::_Context::ESystemType::LogSystem));

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
                                                            ->GetSystem(Engine::_Context::ESystemType::RenderSystem));

    renderSystem->Configurate(Engine::RenderSystem::ERenderSystemType::OpenGL, Engine::RenderSystem::ERenderMode::Edit);

    renderSystem->Render(true);

    // WorldSystem. 
    auto worldSystem = dynamic_cast<Engine::WorldSystem::WorldSystem*>(engineContext
                                                            ->GetSystem(Engine::_Context::ESystemType::WorldSystem));

    worldSystem->CreateWorldByName("GameWorld");

    // SceneSystem. 
    auto sceneSystem = dynamic_cast<Engine::SceneSystem::SceneSystem*>(engineContext
                                                            ->GetSystem(Engine::_Context::ESystemType::SceneSystem));
                                        
    
    sceneSystem->CreateSceneByName("MainScene");

    // ObjectSystem. 
    auto objectSystem = dynamic_cast<Engine::ObjectSystem::ObjectSystem*>(engineContext
                                                            ->GetSystem(Engine::_Context::ESystemType::ObjectSystem));
                                        
    
    objectSystem->CreateObjectByName("GameObject");

    // Start Engine(Runtime).
    gameEngine->StartEngine();

    // Example For GameMode, etc.
    // ...
    
    return 0;
}