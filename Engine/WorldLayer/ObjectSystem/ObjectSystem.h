#pragma once

#include <string>
#include <vector>
#include <map>

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/EObjectType.h"
#include "Base/IObject.h"

#include "Objects/BasicObject/BasicObject.h"
#include "Objects/UIObject/UIObject.h"

//#include "Objects/NetworkObject/NetworkObject.h"
//#include "Objects/UINetworkObject/UINetworkObject.h"

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API ObjectSystem : public ISystem
#else
#ifdef __APPLE__ 
class ObjectSystem : public ISystem
#endif
#ifdef __linux__
class ObjectSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class ObjectSystem : public ISystem
#endif
#endif
{
private: 

   std::map<std::string, IObject*> _objects;

   bool MapContainsKey(std::map<std::string, IObject*>& map, std::string key);

public:

    ObjectSystem();

    void Initialize();
   
    IObject* CreateObjectByName(std::string name, Engine::SceneSystem::IScene* owner, IObject* parent = NULL, Engine::ObjectSystem::EObjectType eObjectType = Engine::ObjectSystem::EObjectType::BasicObject);

    IObject* GetObjectByName(std::string);

    int GetObjectId(std::string);

    std::map<std::string, IObject*> GetAllObjects();

    std::map<std::string, IObject*> GetAllObjectsOnScene(std::string sceneName);

   // std::map<std::string, IObject*> GetAllObjectsOnScene(IScene* scene); TODO:
};

} // namespace ObjectSystem
} // namespace Engine