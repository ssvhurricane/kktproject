// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../_Context/EngineContextInstaller.h"

namespace Engine {
namespace StartSystem {

class ENGINE_API StartSystem : public ISystem
{
private:


public:

    StartSystem();

    void Initialize();
};

} // namespace StartSystem
} // namespace Engine