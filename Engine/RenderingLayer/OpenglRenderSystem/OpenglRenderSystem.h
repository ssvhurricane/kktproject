// This is non Context System.
#pragma once

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"

namespace Engine {
namespace OpenglRenderSystem {

class ENGINE_API OpenglRenderSystem : public _Context::ISystem
{
private:
    // TODO:
public:

    OpenglRenderSystem();

    void Initialize();
}; 

} // namespace  OpenglRenderSystem
} // namespace Engine