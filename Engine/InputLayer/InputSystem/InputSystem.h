#pragma once

#include <string>
#include <vector>
#include <map>

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/EInputType.h"

namespace Engine {
namespace InputSystem{
#ifdef _WIN32
class ENGINE_API InputSystem : public ISystem
#else
#ifdef __APPLE__ 
class InputSystem : public ISystem
#endif
#ifdef __linux__
class InputSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class InputSystem : public ISystem
#endif
#endif
{
private: 

public:

    InputSystem();

    void Initialize();
};

} // namespace InputSystem
} // namespace Engine