/*
    Dynamic Labriary.
    It can be very well used in the target application, 
    it can be an editor or a game.
    Also, through it, the context is obtained directly in the engine itself.
*/
#pragma once

#include <iostream>
#include <string>

#include "base_context/Singleton.h"
#include "base_context/Defines.h"
#include "base_context/IContextInstaller.h"

#include "CoreLayer/InitializeSystem/InitializeSystem.h"
#include "CoreLayer/StartSystem/StartSystem.h"

namespace Engine {
class ENGINE_API KKTEngine : public Singleton<KKTEngine>
{
private:

    IContextInstaller* _mainContext; // Main Context (Use engine or app)

    ISystem* _initializeSystem; 
    
    ISystem* _startSystem;
    
public:

     void __cdecl InitialEngine(); 

     void __cdecl PrintDebugMessage(std::string str);
    
     IContextInstaller* __cdecl GetContext();

     void __cdecl StartEngine();
};

} // namespace Engine
