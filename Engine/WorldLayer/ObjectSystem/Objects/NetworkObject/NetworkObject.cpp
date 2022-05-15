#include "NetworkObject.h"

namespace Engine {
namespace ObjectSystem {

NetworkObject::NetworkObject()
{ 
    _id = 1;

    _name = "";

    _type =  EObjectType::BasicObject;

}

void NetworkObject::Initialize(std::string name, EObjectType type)
{
    // TODO:
}

int NetworkObject::GetId()
{
    // TODO:
    return -1;
}

EObjectType NetworkObject::GetType()
{
    // TODO:
    return EObjectType::BasicObject;
}

std::string NetworkObject::GetName()
{
    // TODO:
    return "";
}
void NetworkObject::AddComponent(IComponent* component)
{
    // TODO:
}

IComponent* NetworkObject::GetComponentById(int id)
{
    // TODO:
    return NULL;
}

IComponent* NetworkObject::GetComponentByName(std::string name)
{
    // TODO:
    return NULL;
}

    
void NetworkObject::RemoveComponentById(int id)
{
    // TODO:
}

void NetworkObject::RemoveComponentByName(std::string name)
{
    // TODO:
}

bool NetworkObject::HasComponent(IComponent* component)
{
    // TODO:
    return false;
}

std::vector<IComponent*> NetworkObject::GetAllComponents()
{
    // TODO:
    return std::vector<IComponent*>();
}

void NetworkObject::RemoveAllComponents()
{
    // TODO:
}

} // namespace ObjectSystem
} // namespace Engine
