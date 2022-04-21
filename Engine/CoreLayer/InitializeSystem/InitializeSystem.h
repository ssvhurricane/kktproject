// This is non Context System (you can't use distanced services here).
#pragma once

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