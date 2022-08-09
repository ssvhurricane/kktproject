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

    // WorldSystem. 
    auto worldSystem = dynamic_cast<Engine::WorldSystem::WorldSystem*>(engineContext
                                                            ->GetSystem(ESystemType::WorldSystem));
   
    worldSystem->CreateWorldByName("GameWorld", Engine::WorldSystem::BasicWorld);

    // SceneSystem. 
    auto sceneSystem = dynamic_cast<Engine::SceneSystem::SceneSystem*>(engineContext
                                                            ->GetSystem(ESystemType::SceneSystem));
                                        
    
    sceneSystem->CreateSceneByName("MainScene");

    // ObjectSystem. 
    auto objectSystem = dynamic_cast<Engine::ObjectSystem::ObjectSystem*>(engineContext
                                                            ->GetSystem(ESystemType::ObjectSystem));
                                        
    
    objectSystem->CreateObjectByName("BaseGameObject");

    objectSystem->CreateObjectByName("UIGameObject", Engine::ObjectSystem::EObjectType::UIObject);

    // Start Engine(Runtime).
    gameEngine->StartEngine();

    // Example For GameMode, etc.
    // ...
    
    return 0;
}