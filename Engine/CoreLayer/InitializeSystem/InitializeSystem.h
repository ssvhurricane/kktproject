// This is non Context System.
#pragma once

#include "../LogSystem/LogSystem.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "../../_Context/EngineContextInstaller.h"

namespace Engine {
namespace InitializeSystem {

class ENGINE_API InitializeSystem : public _Context::ISystem
{
private:
    Engine::_Context::IContextInstaller* _context;
public:
    InitializeSystem();

    void Initialize();

    Engine::_Context::IContextInstaller* GetContext();
};

} // namespace InitializeSystem
} // namespace Engine