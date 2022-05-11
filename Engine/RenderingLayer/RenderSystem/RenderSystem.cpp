#include "RenderSystem.h"

namespace Engine {
namespace RenderSystem {


void RenderSystem::DemoRender()
{
    // TODO:
}

void RenderSystem::UpdateRender()
{
    // TODO:
}

RenderSystem::RenderSystem()
{
    _renderSystem = nullptr; 

/*
     dynamic_cast<Engine::LogSystem::LogSystem*>
    (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Create RenderSystem.",
                                        Engine::LogSystem::ELogOutputLocationType::All);*/
}

void RenderSystem::Initialize()
{
    // TODO:
}

void RenderSystem::Configurate(ERenderSystemType eRennderSystemType, ERenderMode eRenderMode)
{
    switch (eRennderSystemType)
    {
    case ERenderSystemType::OpenGL:
    {
        _renderSystem = dynamic_cast<OpenglRenderSystem::OpenglRenderSystem*>(new OpenglRenderSystem::OpenglRenderSystem);

        break;
    }
    case ERenderSystemType::WebGL:
    {
         _renderSystem = dynamic_cast<WebglRenderSystem::WebglRenderSystem*>(new WebglRenderSystem::WebglRenderSystem);

        break;
    } 
    case ERenderSystemType::Vulkan:
    {
         _renderSystem = dynamic_cast<VulkanRenderSystem::VulkanRenderSystem*>(new VulkanRenderSystem::VulkanRenderSystem);

        break;
    }
    
    default:
        break;
    }

    switch (eRenderMode)
    {
    case ERenderMode::Edit:
    {
        // TODO:

        break;
    }
    case ERenderMode::Game:
    {
        // TODO:

        break;
    } 
    case ERenderMode::Custom:
    {
        // TODO:

        break;
    }
    
    default:
        break;
    }
}

void RenderSystem::Render(bool bDemoMode)
{
    _renderSystem->Render(bDemoMode);
}

} // namespace RenderSystem
} // namespace Engine