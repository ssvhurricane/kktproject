#pragma once

#include <iostream>
#include <string>
#include "_Context/Base/Defines.h"
#include "_Context/Base/IContextInstaller.h"
#include "CoreLayer/InitializeSystem/InitializeSystem.h"

namespace Engine {
class KKTEngine
{
private:

    Engine::_Context::IContextInstaller* _context;

    Engine::_Context::ISystem* _system; 
   
public:

    ENGINE_API void __cdecl PrintDebugMessage(std::string str);

    ENGINE_API void __cdecl InitialEngine();
    
    ENGINE_API Engine::_Context::IContextInstaller* __cdecl GetContext();

    ENGINE_API void __cdecl StartEngine();
};

} // namespace Engine
