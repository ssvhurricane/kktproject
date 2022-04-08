#ifndef ENGINE_KKTENGINE_H_
#define ENGINE_KKTENGINE_H_

#pragma once
#include <iostream>
#include <string>
#include "_Context/Base/Defines.h"
#include "_Context/EngineContextInstaller.h"

using namespace Engine::_Context;

namespace Engine {
class KKTEngine
{
private:
    IContextInstaller* _context;
public:

 ENGINE_API void __cdecl PrintDebugMessage(std::string str);

 ENGINE_API void __cdecl InitialEngine();
    
 ENGINE_API IContextInstaller* __cdecl GetContext();

 ENGINE_API void __cdecl StartEngine();
};

} // namespace Engine

#endif //  ENGINE_KKTENGINE_H_