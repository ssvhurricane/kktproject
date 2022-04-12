#include "KKTEngine.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine {

 void  KKTEngine::InitialEngine()
 {
      std::cout<< "KKTEngine.dll: Initialize!"<< std::endl;

     _initializeSystem = new Engine::InitializeSystem::InitializeSystem();

     _initializeSystem->Initialize();
   
     _mainContext = dynamic_cast<Engine::InitializeSystem::InitializeSystem*>(_initializeSystem)->GetContext();
 }
 
 void KKTEngine::PrintDebugMessage(std::string str)
 {
     std::cout<< "KKTEngine.dll: "<< str << std::endl;
 }
 
 Engine::_Context::IContextInstaller*  KKTEngine::GetContext()
{ 
     std::cout<< "KKTEngine.dll: Get context!"<< std::endl;

     return _mainContext;
}

 void KKTEngine::StartEngine()
 {
     std::cout<< "KKTEngine.dll: Start!"<< std::endl;
 }

 } // namespace engine 