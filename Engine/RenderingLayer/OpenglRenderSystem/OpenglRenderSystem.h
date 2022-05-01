// This is non Context System.
#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace OpenglRenderSystem {
#if defined _WIN32
class ENGINE_API OpenglRenderSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class OpenglRenderSystem : public ISystem
#endif
{
private:
    // TODO:
public:

    OpenglRenderSystem();

    void Initialize();
}; 

} // namespace  OpenglRenderSystem
} // namespace Engine