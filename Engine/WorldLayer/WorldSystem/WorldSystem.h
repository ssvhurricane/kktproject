#pragma once

#include <map>
#include <string>

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/EWorldType.h"
#include "Base/IWorld.h"

namespace Engine {
namespace WorldSystem {

class ENGINE_API WorldSystem : public ISystem
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
