#pragma once

#include <map>

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "Base/EWorldType.h"
#include "Base/IWorld.h"

namespace Engine {
namespace WorldSystem {

class ENGINE_API WorldSystem : public _Context::ISystem
{
private: 

    std::map<EWorldType, IWorld*> _worlds;

public:

    WorldSystem();

    void Initialize();

    void CreateWorld();

    IWorld* GetWorld(EWorldType);
};

} // namespace WorldSystem
} // namespace Engine
