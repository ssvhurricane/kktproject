// TODO: Standard GL Shader Type.
#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API TransformComponent : public IComponent
#else
#ifdef __APPLE__  
class TransformComponent : public IComponent
#endif
#ifdef  __linux__
class TransformComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class TransformComponent : public IComponent
#endif
#endif
{
private:
   
public:
    TransformComponent();
};

} // namespace ObjectSystem
} // namespace Engine