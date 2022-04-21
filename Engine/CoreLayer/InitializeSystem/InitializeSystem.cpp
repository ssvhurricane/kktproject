#include "InitializeSystem.h"

namespace Engine {
namespace InitializeSystem {

InitializeSystem::InitializeSystem()
{
    // TODO:
}

void InitializeSystem::Initialize()
{
     std::cout<< "[EngineLayer] -> [" << typeid(this).name() <<  "] -> [Initialize...]" << std::endl;
}

Engine::_Context::IContextInstaller* InitializeSystem::GetContext()
{
    _context = new Engine::_Context::EngineContextInstaller();

    return _context;
}
} // namespace InitializeSystem
} // namespace Engine