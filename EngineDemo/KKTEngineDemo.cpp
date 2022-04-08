#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

int main()
{
    Engine::KKTEngine* gameEngine = new Engine::KKTEngine();

    gameEngine->InitialEngine();
    
    IContextInstaller* engineContext = gameEngine->GetContext();

    engineContext->GetSystem(); //TODO: 
    
    gameEngine->StartEngine();
  
    return 0;
}