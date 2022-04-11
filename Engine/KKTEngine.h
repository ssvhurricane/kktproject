/*
    It can be very well used in the target application, 
    it can be an editor or a game.
    Also, through it, the context is obtained directly in the engine itself.
*/
#pragma once

#include <iostream>
#include <string>
#include "_Context/Base/Singleton.h"
#include "_Context/Base/Defines.h"
#include "_Context/Base/IContextInstaller.h"
#include "CoreLayer/InitializeSystem/InitializeSystem.h"

namespace Engine {
class KKTEngine : public Singleton<KKTEngine>
{
private:

    Engine::_Context::IContextInstaller* _mainContext; // Main Context (Use engine or app)

    Engine::_Context::ISystem* _initializeSystem; 
    
    // Engine::_Context::ISystem* _startSystem; // TODO (game runtime)
   
public:

    ENGINE_API void __cdecl InitialEngine(); 

    ENGINE_API void __cdecl PrintDebugMessage(std::string str);
    
    ENGINE_API Engine::_Context::IContextInstaller* __cdecl GetContext();

    ENGINE_API void __cdecl StartEngine();
};

} // namespace Engine
