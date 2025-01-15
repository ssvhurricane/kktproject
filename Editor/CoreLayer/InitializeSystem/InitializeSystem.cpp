#include "InitializeSystem.h"

namespace Editor {
namespace InitializeSystem {

InitializeSystem::InitializeSystem()
{
    // TODO:
}

void InitializeSystem::Initialize()
{
   // TODO:
}

IContextInstaller* InitializeSystem::GetContext()
{
    // TODO:
    _context = new Editor::_Context::EditorContextInstaller();

    return _context;
}
} // nmaespace InitializeSystem
} // namespace Editor