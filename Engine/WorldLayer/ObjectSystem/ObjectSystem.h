#pragma once

#include <string>
#include <vector>

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/EObjectType.h"
#include "Base/IObject.h"

namespace Engine {
namespace ObjectSystem {
#if defined _WIN32
class ENGINE_API ObjectSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class ObjectSystem : public ISystem
#endif
{
private: 

    std::vector<IObject*> _objects;

public:

    ObjectSystem();

    void Initialize();
   
    void CreateObjectByName(std::string name, EObjectType eObjectType = EObjectType::BasicObject);

    IObject* GetObjectByName(std::string);

    int GetObjectId(std::string);
};

} // namespace ObjectSystem
} // namespace Engine