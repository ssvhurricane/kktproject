#pragma once

#include "ERenderSystemType.h"

namespace Engine {
namespace RenderSystem {

struct IRenderSystem 
{ 
    virtual IRenderSystem* GetSystem(ERenderSystemType) = 0;
};

} // namespace _Context
} // namespace Engine
