// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace OpenglRenderSystem {

class ENGINE_API OpenglRenderSystem : public ISystem
{
private:
    // TODO:
public:

    OpenglRenderSystem();

    void Initialize();
}; 

} // namespace  OpenglRenderSystem
} // namespace Engine