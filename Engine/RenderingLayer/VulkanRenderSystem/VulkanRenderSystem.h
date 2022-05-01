// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace VulkanRenderSystem {
#if defined _WIN32
class ENGINE_API VulkanRenderSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class VulkanRenderSystem : public ISystem
#endif
{
private:
    // TODO:
public:

    VulkanRenderSystem();

    void Initialize();
}; 

} // namespace VulkanRenderSystem
} // namespace Engine