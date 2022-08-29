#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/Quaternion.h"
#include "Base/Vector2D.h"
#include "Base/Vector3D.h"

namespace Engine {
namespace MathSystem{
#ifdef _WIN32
class ENGINE_API MathSystem : public ISystem
#else 
#ifdef __APPLE__
class MathSystem : public ISystem
#endif
#ifdef __linux__
class MathSystem: public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class MathSystem: public ISystem
#endif
#endif
{
private:
    // TODO:
public:
    MathSystem();
};
} // namespace Engine
} // namespace MathSystem