#include "InitializeSystem.h"

namespace Editor {
namespace InitializeSystem {

InitializeSystem::InitializeSystem()
{
    // TODO:
}

void InitializeSystem::Initialize()
{
     std::cout<< "[EditorLayer] -> [" << typeid(this).name() <<  "] -> [Initialize...]" << std::endl;
}

IContextInstaller* InitializeSystem::GetContext()
{
    _context = new Editor::_Context::EditorContextInstaller();

    return _context;
}
} // nmaespace InitializeSystem
} // namespace Editor