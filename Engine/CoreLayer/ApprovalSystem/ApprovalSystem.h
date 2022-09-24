#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace ApprovalSystem{
#ifdef _WIN32
class ENGINE_API ApprovalSystem : public ISystem
#else 
#ifdef __APPLE__
class ApprovalSystem : public ISystem
#endif
#ifdef __linux__
class ApprovalSystem : public ISystem
#endif
#ifdef  __EMSCRIPTEN__
class ApprovalSystem : public ISystem
#endif
#endif
{
private:
    // TODO:
public:

    ApprovalSystem();

    void Initialize();
};
} // namespace ApprovalSystem
} // namespace Engine