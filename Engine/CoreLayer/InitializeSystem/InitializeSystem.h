// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../_Context/EngineContextInstaller.h"

namespace Engine {
namespace InitializeSystem {

class ENGINE_API InitializeSystem : public ISystem
{
private:

    IContextInstaller* _context;

public:

    InitializeSystem();

    void Initialize();

    IContextInstaller* GetContext();
};

} // namespace InitializeSystem
} // namespace Engine