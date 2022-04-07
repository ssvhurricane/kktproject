#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

typedef void (__cdecl * PrintDebugMessage)();
typedef void (__cdecl * InitialEngine)();
typedef void (__cdecl * StartEngine)();
typedef Engine::_Context::EngineContextInstaller*(__cdecl * GetEngineContext)();

int main()
{
    Engine::PrintDebugMessage("KKTEngine Message!");

    Engine::InitialEngine();

    Engine::StartEngine();

    auto resValue = Engine::GetEngineContext();
  
    return 0;
}