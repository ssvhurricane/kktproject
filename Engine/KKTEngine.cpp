#include "KKTEngine.h"

namespace Engine {

 void KKTEngine::InitialEngine()
 {
      std::cout<< "[EngineLayer] -> [" << typeid(this).name() << "] -> [Initialize...]" << std::endl;

     _initializeSystem = new Engine::InitializeSystem::InitializeSystem();

     _initializeSystem->Initialize();
   
     _mainContext = dynamic_cast<Engine::InitializeSystem::InitializeSystem*>(_initializeSystem)->GetContext();
 }
 
 void KKTEngine::PrintDebugMessage(std::string str)
 {
     std::cout<< "[EngineLayer] -> [" << typeid(this).name() << "] -> [" << str << "]" << std::endl;
 }
 
IContextInstaller* KKTEngine::GetContext()
{ 
     return _mainContext;
}

 void KKTEngine::StartEngine()
 { 
     std::cout<< "[EngineLayer] -> [" << typeid(this).name() << "] -> [Start...]"<< std::endl;

     _startSystem = new Engine::StartSystem::StartSystem();

     _startSystem->Initialize();
 }

 } // namespace engine 