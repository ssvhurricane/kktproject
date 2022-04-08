#include <KKTEngine.h>
#include <iostream>
#include "di.hpp"

//#pragma comment(lib,"KKTEngine.lib")

int main()
{
    Engine::InitialEngine(); 
    
    IContextInstaller* engineContext = Engine::GetContext();

    Engine::StartEngine();
  
    return 0;
}