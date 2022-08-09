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
                                        
    
    sceneSystem->CreateSceneByName("MainScene", worldSystem->GetWorldByName("GameWorld"));

    // ObjectSystem. 
    auto objectSystem = dynamic_cast<Engine::ObjectSystem::ObjectSystem*>(engineContext
                                                            ->GetSystem(ESystemType::ObjectSystem));
                                        
    
    auto cameraObject = objectSystem->CreateObjectByName("CameraGameObject", 
                                                        sceneSystem->GetSceneByName("MainScene"), 
                                                        NULL);
    
    if(cameraObject)
    {
        // Add components for object.
        auto transformComponent = new Engine::ObjectSystem::TransformComponent; 
        cameraObject->AddComponent(transformComponent);

        auto cameraComponent = new Engine::ObjectSystem::CameraComponent;
        cameraObject->AddComponent(cameraComponent);
    }

    auto uiObject = objectSystem->CreateObjectByName("UIGameObject", 
                                                        sceneSystem->GetSceneByName("MainScene"),
                                                        NULL,
                                                        Engine::ObjectSystem::EObjectType::UIObject);

    if(uiObject)
    {
        // Add components for object.
        auto transformComponent2 = new Engine::ObjectSystem::TransformComponent; 
        uiObject->AddComponent(transformComponent2);
    }

    // Start Engine(Runtime).
    gameEngine->StartEngine();

    // Example For GameMode, etc.
    // ...
    
    return 0;
}