// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../_Context/EngineContextInstaller.h"

namespace Engine {
namespace InitializeSystem {

#if defined _WIN32
class ENGINE_API InitializeSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class InitializeSystem : public ISystem
#endif
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