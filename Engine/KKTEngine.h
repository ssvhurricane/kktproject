#pragma once

#include <iostream>
#include <string>
#include "_Context/Base/Defines.h"
#include "_Context/EngineContextInstaller.h"

namespace Engine {
class KKTEngine
{
private:
   Engine::_Context::IContextInstaller* _context;
public:

 ENGINE_API void __cdecl PrintDebugMessage(std::string str);

 ENGINE_API void __cdecl InitialEngine();
    
 ENGINE_API Engine::_Context::IContextInstaller* __cdecl GetContext();

 ENGINE_API void __cdecl StartEngine();
};

} // namespace Engine
