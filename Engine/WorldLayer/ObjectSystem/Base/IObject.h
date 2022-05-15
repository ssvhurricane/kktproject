#pragma once

#include <string>
#include <vector>

#include "EObjectType.h"
#include "IComponent.h"

namespace Engine {
namespace ObjectSystem {

struct IObject
{
    virtual void Initialize(std::string, EObjectType) = 0;

    virtual int GetId() = 0;

    virtual EObjectType GetType() = 0;

    virtual std::string GetName() = 0;

    virtual void AddComponent(IComponent*) = 0;

    virtual IComponent* GetComponentById(int id) = 0;

    virtual IComponent* GetComponentByName(std::string) = 0;

    virtual void RemoveComponentById(int id) = 0;

    virtual void RemoveComponentByName(std::string) = 0;

    virtual bool HasComponent(IComponent*) = 0;

    virtual std::vector<IComponent*> GetAllComponents() = 0;

    virtual void RemoveAllComponents() = 0;
 
};

} // namespace ObjectSystem
} // namespace Engine
