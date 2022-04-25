// This is non Context System.
#pragma once

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"

namespace Engine {
namespace VulkanRenderSystem {

class ENGINE_API VulkanRenderSystem : public _Context::ISystem
{
private:
    // TODO:
public:

    VulkanRenderSystem();

    void Initialize();
}; 

} // namespace VulkanRenderSystem
} // namespace Engine