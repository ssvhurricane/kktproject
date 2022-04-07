#ifndef ENGINE_KKTENGINE_H_
#define ENGINE_KKTENGINE_H_

#pragma once
#include <iostream>
#include <string>
#include "Defines.h"
#include "_Context/EngineContextInstaller.h"

using namespace Engine::_Context;

namespace Engine {

extern "C" ENGINE_API void __cdecl PrintDebugMessage(std::string str);

extern "C" ENGINE_API void __cdecl InitialEngine();

extern "C" ENGINE_API void __cdecl StartEngine();

extern "C" ENGINE_API EngineContextInstaller* __cdecl GetEngineContext();

} // namespace engine

#endif //  ENGINE_KKTENGINE_H_