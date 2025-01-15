#include "InitializeSystem.h"

namespace Editor {
namespace InitializeSystem {

InitializeSystem::InitializeSystem()
{
    // TODO:
}

void InitializeSystem::Initialize(IContextInstaller* _mainContext)
{
    // Create and Draw editor.
    auto renderSystem = dynamic_cast<Editor::RenderSystem::RenderSystem*>
                    (_mainContext->GetSystem(ESystemType::RenderSystem));

    renderSystem->Configurate(Editor::RenderSystem::ERenderSystemType::OpenGL, Editor::RenderSystem::ERenderMode::Edit);

    renderSystem->Render(true);
}

IContextInstaller* InitializeSystem::GetContext()
{
    // TODO:
    _context = new Editor::_Context::EditorContextInstaller();

    return _context;
}
} // nmaespace InitializeSystem
} // namespace Editor