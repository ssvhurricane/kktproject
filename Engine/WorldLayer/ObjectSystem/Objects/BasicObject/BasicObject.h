#pragma once

#include <string>
#include <vector>

#include "../../Base/IObject.h"
#include "../../Base/EObjectType.h"

namespace Engine {
namespace ObjectSystem {

class BasicObject : public IObject
{
private:

    int _id;

    std::string _name;

    EObjectType _type;

public:

    BasicObject();

    void Initialize(std::string, EObjectType);

    int GetId();

    EObjectType GetType();

    std::string GetName();
   
    
};

} // namespace ObjectSystem
} // namespace Engine
