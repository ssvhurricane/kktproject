#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../../WorldLayer/ObjectSystem/Objects/BasicObject/BasicObject.h"
#include "../../../WorldLayer/ObjectSystem/Base/IEditable.h"
#include "../Base/IControl.h"

namespace Engine {
namespace UISystem {

class Canvas : public Engine::ObjectSystem::BasicObject, public Engine::ObjectSystem::IEditable, public IControl
{
private:
   // TODO:
public:

   Canvas();
};

} // namespace UISystem
} // namespace Engine