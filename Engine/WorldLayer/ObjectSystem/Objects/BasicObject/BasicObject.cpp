#include "BasicObject.h"

namespace Engine {
namespace ObjectSystem {

BasicObject::BasicObject()
{ 
    _id = 1;

    _name = "";

    _type =  EObjectType::BasicObject;

}

void BasicObject::Initialize(std::string name, EObjectType type)
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

void BasicObject::SetOwner(SceneSystem::IScene*)
{
    // TODO:
}

SceneSystem::IScene* BasicObject::GetOwner()
{
    // TODO:
    return NULL;
}

void BasicObject::SetParent(Engine::ObjectSystem::IObject*)
{
    // TODO:
}

Engine::ObjectSystem::IObject* BasicObject::GetParent()
{
    // TODO:
    return NULL;
}

void BasicObject::AddComponent(IComponent* component)
{
    // TODO:
}

IComponent* BasicObject::GetComponentById(int id)
{
    // TODO:
    return NULL;
}

IComponent* BasicObject::GetComponentByName(std::string name)
{
    // TODO:
    return NULL;
}

    
void BasicObject::RemoveComponentById(int id)
{
    // TODO:
}

void BasicObject::RemoveComponentByName(std::string name)
{
    // TODO:
}

bool BasicObject::HasComponent(IComponent* component)
{
    // TODO:
    return false;
}

std::vector<IComponent*> BasicObject::GetAllComponents()
{
    // TODO:
    return std::vector<IComponent*>();
}

void BasicObject::RemoveAllComponents()
{
    // TODO:
}

} // namespace ObjectSystem
} // namespace Engine
