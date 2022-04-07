#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

//typedef Engine::_Context::EngineContextInstaller* (__cdecl *EngineContextInstaller)();
int main()
{
    Engine::KKTEngine* engine = new Engine::KKTEngine();

    engine->PrintDebugMessage("KKTEngine Message!");

    engine->InitialEngine();

    engine->StartEngine();

   // engine->GetContext();
  
    return 0;
}