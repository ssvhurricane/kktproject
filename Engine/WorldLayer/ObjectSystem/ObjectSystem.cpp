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
   // TODO:
   dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "CreateObject: " + name,
                                         Engine::LogSystem::ELogOutputLocationType::All);
    return NULL;

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

}
}