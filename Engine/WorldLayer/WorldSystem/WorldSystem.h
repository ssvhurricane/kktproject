#pragma once

#include <map>
#include <string>

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/EWorldType.h"
#include "Base/IWorld.h"

#include "Words/BasicWorld/BasicWorld.h"
#include "Words/AppWorld/AppWorld.h"
#include "Words/ARWorld/ARWorld.h"
#include "Words/VRWorld/VRWorld.h"

namespace Engine {
namespace WorldSystem {
#ifdef _WIN32
class ENGINE_API WorldSystem : public ISystem
#else
#ifdef __APPLE__  
class WorldSystem : public ISystem
#endif
#ifdef  __linux__
class WorldSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class WorldSystem : public ISystem
#endif
#endif
{
private: 

    std::map<std::string, IWorld*> _worlds;

    bool MapContainsKey(std::map<std::string, IWorld*>& map, std::string key);

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
