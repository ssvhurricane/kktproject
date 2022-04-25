// This is non Context System.
#pragma once

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"

namespace Engine {
namespace WebglRenderSystem {

class ENGINE_API WebglRenderSystem: public _Context::ISystem
{
private:
    // TODO:
public:

    WebglRenderSystem();

    void Initialize();
}; 

} // namespace WebglRenderSystem
} // namespace Engine