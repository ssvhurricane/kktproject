#ifndef ENGINE_KKTENGINE_H_
#define ENGINE_KKTENGINE_H_

#pragma once
#include <iostream>
#include <string>
#include "Defines.h"
#include "_Context/EngineContextInstaller.h"
#include "CoreLayer/InittializeSystem/InittializeSystem.h"

using namespace Engine::_Context;

namespace Engine {

class ENGINE_API KKTEngine
{
private:
     EngineContextInstaller* _engineContextInstaller;
public:
 KKTEngine();

 void __cdecl PrintDebugMessage(std::string str);

 void __cdecl InitialEngine();

 void __cdecl StartEngine();
 
 EngineContextInstaller* __cdecl GetContext();
};

} // namespace engine

#endif //  ENGINE_KKTENGINE_H_