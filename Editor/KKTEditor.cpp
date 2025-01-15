#include <iostream>
#include <string>

#include "base_context/Singleton.h"
#include "base_context/Defines.h"
#include "base_context/IContextInstaller.h"

#include "CoreLayer/InitializeSystem/InitializeSystem.h"
#include "CoreLayer/StartSystem/StartSystem.h"

 IContextInstaller* _mainContext; // Main Context (Use engine or app)

 ISystem* _initializeSystem; 
 ISystem* _startSystem;

int main()
{
    std::cout<< "[EditorLayer] -> ["  "] -> [Initialize...]" << std::endl;

    _mainContext = new Editor::_Context::EditorContextInstaller;

    _initializeSystem = new Editor::InitializeSystem::InitializeSystem();
    _initializeSystem->Initialize(); // TODO:

    _startSystem = new Editor::StartSystem::StartSystem();
    _startSystem->Initialize(); // TODO:
    

    auto renderSystem = dynamic_cast<Editor::RenderSystem::RenderSystem*>
                    (_mainContext->GetSystem(ESystemType::RenderSystem));

    renderSystem->Configurate(Editor::RenderSystem::ERenderSystemType::OpenGL, Editor::RenderSystem::ERenderMode::Edit);

    renderSystem->Render(true);
    
    return 0;
}


