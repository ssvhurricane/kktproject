#include <iostream>
#include <string>
#include "base_context/Defines.h"
#include "base_context/IContextInstaller.h"

#include "CoreLayer/InitializeSystem/InitializeSystem.h"
#include "CoreLayer/StartSystem/StartSystem.h"

IContextInstaller* _mainContext; // Main Context (Use engine or app)

Editor::InitializeSystem::InitializeSystem* _initializeSystem; 
Editor::StartSystem::StartSystem* _startSystem;

int main()
{
    std::cout<< "[EditorLayer] -> ["  "] -> [Initialize...]" << std::endl;

    _mainContext = new Editor::_Context::EditorContextInstaller;

    _initializeSystem = new Editor::InitializeSystem::InitializeSystem;
    _initializeSystem->Initialize(_mainContext);

    // TODO: thid is start editor Mode button.
    _startSystem = new Editor::StartSystem::StartSystem();
    _startSystem->Initialize(); 
    
    return 0;
}


