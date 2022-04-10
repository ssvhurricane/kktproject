#include "InitializeSystem.h"

namespace Engine {
namespace InitializeSystem {

InitializeSystem::InitializeSystem()
{
    // TODO:
}

void InitializeSystem::Initialize()
{
    // TODO: 
}
Engine::_Context::IContextInstaller* InitializeSystem::GetContext()
{
    _context = new Engine::_Context::EngineContextInstaller();

    return _context;
}
} // namespace InitializeSystem
} // namespace Engine