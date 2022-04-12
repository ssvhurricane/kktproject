#pragma once

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"

namespace Engine {
namespace RenderSystem{

class ENGINE_API RenderSystem : public _Context::ISystem
{
private:
public:

    RenderSystem();

    void Initialize();

    void DemoRender();
}; 
} // namespace Engine
} // namespace RenderSystem