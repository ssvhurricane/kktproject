// This is non Context System (you can't use distanced services here).
#pragma once

#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "../../_Context/EngineContextInstaller.h"

namespace Engine {
namespace StartSystem {

class ENGINE_API StartSystem : public _Context::ISystem
{
private:


public:

    StartSystem();

    void Initialize();
};

} // namespace StartSystem
} // namespace Engine