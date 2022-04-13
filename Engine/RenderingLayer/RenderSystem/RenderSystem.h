#pragma once

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "../Base/IRenderSystem.h"

namespace Engine {
namespace RenderSystem {

class ENGINE_API RenderSystem : public _Context::ISystem
{
private:

    IRenderSystem* _renderSystem;

public:

    RenderSystem();

    void Initialize();

    void DemoRender();
}; 

} // namespace RenderSystem
} // namespace Engine