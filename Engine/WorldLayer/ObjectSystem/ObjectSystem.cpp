#include "ObjectSystem.h"

namespace Engine {
namespace ObjectSystem {

ObjectSystem::ObjectSystem()
{
    /*
    dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Create ObjectSystem.",
                                         Engine::LogSystem::ELogOutputLocationType::All);*/
}

void ObjectSystem::Initialize()
{
    // TODO:
}
   
IObject* ObjectSystem::CreateObjectByName(std::string name, Engine::SceneSystem::IScene* owner, IObject* parent, Engine::ObjectSystem::EObjectType eObjectType)
{ 
   IObject* object = NULL;

   if(!MapContainsKey(_objects, name) && owner != NULL)
   {
        switch (eObjectType)
        {
            case Engine::ObjectSystem::EObjectType::BasicObject:
            {
                object = new class Engine::ObjectSystem::BasicObject;

                  dynamic_cast<Engine::LogSystem::LogSystem*>
                 (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "CreateObject: " + name,
                                         Engine::LogSystem::ELogOutputLocationType::All);

                break;
            }

            case Engine::ObjectSystem::EObjectType::NetworkObject:
            {
                //object = new class Engine::ObjectSystem::NetworkObject;

                break;
            }

            case Engine::ObjectSystem::EObjectType::UIObject:
            {
                //object = new class Engine::ObjectSystem::UIObject;

                break;
            }

            case Engine::ObjectSystem::EObjectType::UINetworkObject:
            {
                //object = new class Engine::ObjectSystem::UINetworkObject;

                break;
            }
            
            default:
                break;
        }
       
   }
   else
   {
    dynamic_cast<Engine::LogSystem::LogSystem*>
         (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                        "Name or owner are undefined!",
                                         Engine::LogSystem::ELogOutputLocationType::All);
   }

   return object;
}

IObject* ObjectSystem::GetObjectByName(std::string)
{
    // TODO:
    return NULL;
}

int ObjectSystem::GetObjectId(std::string)
{
    // TODO:
    return -1;
}

bool ObjectSystem::MapContainsKey(std::map<std::string, IObject*>& map, std::string key)
{
    if (map.find(key) == map.end()) return false;
    return true;
}

std::map<std::string, IObject*> ObjectSystem::GetAllObjects()
{
    return _objects;
}

std::map<std::string, IObject*> ObjectSystem::GetAllObjectsOnScene(std::string sceneName)
{
    // TODO: search on sceneName.
    return _objects;
}

}
}