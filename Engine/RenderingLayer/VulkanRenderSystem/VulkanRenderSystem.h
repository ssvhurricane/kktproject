// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace VulkanRenderSystem {

class ENGINE_API VulkanRenderSystem : public ISystem
{
private:
    // TODO:
public:

    VulkanRenderSystem();

    void Initialize();
}; 

} // namespace VulkanRenderSystem
} // namespace Engine