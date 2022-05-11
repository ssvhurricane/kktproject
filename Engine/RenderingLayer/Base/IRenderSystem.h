#pragma once

#include "base_context/ISystem.h"

#include "ERenderSystemType.h"

namespace Engine {
namespace RenderSystem {

struct IRenderSystem : public ISystem
{ 
    virtual int Render(bool bDemoMode) = 0;
};

} // namespace _Context
} // namespace Engine
