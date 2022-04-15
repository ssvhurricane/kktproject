#pragma once

#include <string>
#include <vector>

#include "../../KKTEngine.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"
#include "Base/EObjectType.h"
#include "Base/IObject.h"

namespace Engine {
namespace ObjectSystem {

class ENGINE_API ObjectSystem : public _Context::ISystem
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