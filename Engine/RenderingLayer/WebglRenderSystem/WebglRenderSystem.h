// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace WebglRenderSystem {

class ENGINE_API WebglRenderSystem : public ISystem
{
private:
    // TODO:
public:

    WebglRenderSystem();

    void Initialize();
}; 

} // namespace WebglRenderSystem
} // namespace Engine