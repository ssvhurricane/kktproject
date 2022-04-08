#ifndef ENGINE_KKTENGINE_H_
#define ENGINE_KKTENGINE_H_

#pragma once
#include <iostream>
#include <string>
#include "Defines.h"

//#include "_Context/IContextInstaller.h"
#include "_Context/EngineContextInstaller.h"

#include "CoreLayer/InittializeSystem/InittializeSystem.h"


using namespace Engine::_Context;

namespace Engine {

IContextInstaller* _context;

extern "C" {
    ENGINE_API void __cdecl PrintDebugMessage(std::string str);

    ENGINE_API void __cdecl InitialEngine();
    
    ENGINE_API IContextInstaller* __cdecl GetContext();

    ENGINE_API void __cdecl StartEngine();
};

} // namespace engine

#endif //  ENGINE_KKTENGINE_H_