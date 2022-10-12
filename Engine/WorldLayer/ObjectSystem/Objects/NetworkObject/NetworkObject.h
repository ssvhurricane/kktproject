// TODO:
#pragma once

#include <string>
#include <vector>

#include "../../Base/EObjectType.h"
#include "../../../../NetworkLayer/Base/INetworkObject.h"

namespace Engine {
namespace ObjectSystem {

class NetworkObject : public NetworkSystem::INetworkObject
{
private:

    int _id;

    std::string _name;

    EObjectType _type;

    std::vector<IComponent*> _components;

public:

    NetworkObject();

    void Initialize(std::string name, EObjectType type);

    int GetId();

    EObjectType GetType();

    std::string GetName();

    void SetOwner(SceneSystem::IScene*);

    SceneSystem::IScene* GetOwner();

    void SetParent(Engine::ObjectSystem::IObject*);

    Engine::ObjectSystem::IObject* GetParent();

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
