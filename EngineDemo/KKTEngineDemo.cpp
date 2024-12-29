#include <KKTEngine.h>
#include <iostream>
#include <string>

#include "boost/di.hpp"

#include "base_context/IContextInstaller.h"
#include "base_context/ESystemType.h"

int main()
{
    // Create and Init engine.
    Engine::KKTEngine* engine = Engine::KKTEngine::InstancePtr(); // Create Engine.

    engine->InitialEngine();
    
    IContextInstaller* engineContext = engine->GetContext();

    // WorldSystem. 
    auto worldSystem = dynamic_cast<Engine::WorldSystem::WorldSystem*>(engineContext
                                                            ->GetSystem(ESystemType::WorldSystem));
   
    worldSystem->CreateWorldByName("GameWorld", Engine::WorldSystem::BasicWorld);
   
    // SceneSystem. 
    auto sceneSystem = dynamic_cast<Engine::SceneSystem::SceneSystem*>(engineContext
                                                            ->GetSystem(ESystemType::SceneSystem));
                                        
    
    sceneSystem->CreateSceneByName("MainScene", worldSystem->GetWorldByName("World"));

    // ObjectSystem. 
    auto objectSystem = dynamic_cast<Engine::ObjectSystem::ObjectSystem*>(engineContext
                                                            ->GetSystem(ESystemType::ObjectSystem));
                                        
    
    // Create cubes.
    for(int object = 0; object < 5; object++)
    {
       auto cubeObject = objectSystem->CreateObjectByName("CubeObject" + std::to_string(object), 
                                                        sceneSystem->GetSceneByName("MainScene"), 
                                                        NULL);

        if(cubeObject)
        { 
            // Add components for object.
            auto transformComponent = new Engine::ObjectSystem::TransformComponent; 
            // TODO: set position, rotation, etc.
            cubeObject->AddComponent(transformComponent);

            auto meshComponent = new Engine::ObjectSystem::MeshComponent;
            // TODO: set, etc.
            cubeObject->AddComponent(meshComponent);

            auto materialComponent = new Engine::ObjectSystem::MaterialComponent;
            // TODO: set, etc.
            cubeObject->AddComponent(materialComponent);
        }
    }

    // Create Camera(Player).
    auto cameraObject = objectSystem->CreateObjectByName("CameraObject", 
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

    // Create Lights. 
    auto pointLightObject = objectSystem->CreateObjectByName("PointLightObject", 
                                                        sceneSystem->GetSceneByName("MainScene"), 
                                                        NULL);
    if(pointLightObject)
    {
         // Add components for object.
        auto transformComponent = new Engine::ObjectSystem::TransformComponent; 
        pointLightObject->AddComponent(transformComponent);

        auto lightComponent = new Engine::ObjectSystem::LightComponent;
        pointLightObject->AddComponent(lightComponent);
    }

    // Create UI.
    // Canvas.
    auto uiCanvasObject = objectSystem->CreateObjectByName("UICanvasObject", 
                                                        sceneSystem->GetSceneByName("MainScene"),
                                                        NULL);

    if(uiCanvasObject)
    {
        // Add components for object.
        auto transformComponent = new Engine::ObjectSystem::TransformComponent; 
        uiCanvasObject->AddComponent(transformComponent);

        auto canvasComponent = new Engine::ObjectSystem::CanvasComponent;
        uiCanvasObject->AddComponent(canvasComponent);
    }

    // Text.
    auto uiTextObject = objectSystem->CreateObjectByName("UITextObject", 
                                                        sceneSystem->GetSceneByName("MainScene"),
                                                        uiCanvasObject);

    if(uiTextObject)
    {
        // Add components for object.
        auto transformComponent = new Engine::ObjectSystem::TransformComponent; 
        uiTextObject->AddComponent(transformComponent);

        auto textComponent = new Engine::ObjectSystem::TextComponent;
        uiTextObject->AddComponent(textComponent);
    }

    // Input System Init. TODO:
    auto inputSystem = dynamic_cast<Engine::InputSystem::InputSystem*>(engineContext
                                                            ->GetSystem(ESystemType::InputSystem));

    if(InputSystem)
    {
        inputSystem->Initialize(); // TODO:
    }
                                        

    // Start Engine(Runtime).
    engine->StartEngine();

    // Example For GameMode, etc.
    // ...
    
    return 0;
}