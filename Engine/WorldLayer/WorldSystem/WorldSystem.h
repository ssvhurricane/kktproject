#pragma once

#include <map>
#include <string>

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

    std::map<std::string, IWorld*> _worlds;

public:

    WorldSystem();

    void Initialize();

    void CreateWorldByName(std::string name, EWorldType eWorldType = EWorldType::BasicWorld);

    IWorld* GetWorldByName(std::string);

    int GetWorldId(std::string);

    IWorld* GetCurrentWorld();
};

} // namespace WorldSystem
} // namespace Engine
