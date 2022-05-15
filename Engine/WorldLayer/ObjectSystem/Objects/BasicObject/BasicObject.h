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

    std::vector<IComponent*> _components;

public:

    BasicObject();

    void Initialize(std::string name, EObjectType type);

    int GetId();

    EObjectType GetType();

    std::string GetName();

    void AddComponent(IComponent* component);

    IComponent* GetComponentById(int id);

    IComponent* GetComponentByName(std::string name);

    void RemoveComponentById(int id);

    void RemoveComponentByName(std::string name);

    bool HasComponent(IComponent* component);

    std::vector<IComponent*> GetAllComponents();

    void RemoveAllComponents();
    
};

} // namespace ObjectSystem
} // namespace Engine
