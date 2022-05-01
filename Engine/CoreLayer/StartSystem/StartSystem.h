// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../_Context/EngineContextInstaller.h"

namespace Engine {
namespace StartSystem {
#if defined _WIN32
class ENGINE_API StartSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class StartSystem : public ISystem
#endif
{
private:


public:

    StartSystem();

    void Initialize();
};

} // namespace StartSystem
} // namespace Engine