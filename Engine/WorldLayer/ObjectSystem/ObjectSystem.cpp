#include "ObjectSystem.h"

namespace Engine {
namespace ObjectSystem {

ObjectSystem::ObjectSystem(){}

void ObjectSystem::Initialize(){}

void ObjectSystem::CreateObject()
{
     // TODO:
   dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(Engine::_Context::ESystemType::LogSystem))
                                ->ShowLog("[ObjectSystem]",  
                                            Engine::LogSystem::ELogType::Message,
                                            "CreateObject!",
                                             Engine::LogSystem::ELogOutputLocationType::All);
}

IObject* ObjectSystem::GetObject(EObjectType eObjectType){}

}
}