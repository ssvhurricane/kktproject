#include "RenderSystem.h"

namespace Engine {
namespace RenderSystem{

RenderSystem::RenderSystem()
{
    // TODO:
}

void RenderSystem::Initialize()
{
    // TODO:
}

void RenderSystem::DemoRender()
{
   dynamic_cast<Engine::LogSystem::LogSystem*>(Engine::KKTEngine::InstancePtr()
                                                                ->GetContext()
                                                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                                                    ->ShowLog("[RenderSystem]",  
                                                                                Engine::LogSystem::ELogType::Message,
                                                                                "DemoRender!",
                                                                                Engine::LogSystem::ELogOutputLocationType::All);

   
}

} // namespace Engine
} // namespace RenderSystem