#include "BasicObject.h"

namespace Engine {
namespace ObjectSystem {

BasicObject::BasicObject()
{ 
    _id = 1;

    _name = "";

    _type =  EObjectType::BasicObject;

}

void BasicObject::Initialize(std::string, EObjectType)
{
    // TODO:
}

int BasicObject::GetId()
{
    // TODO:
    return -1;
}

EObjectType BasicObject::GetType()
{
    // TODO:
    return EObjectType::BasicObject;
}

std::string BasicObject::GetName()
{
    // TODO:
    return "";
}

} // namespace ObjectSystem
} // namespace Engine
