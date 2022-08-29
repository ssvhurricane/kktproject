#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API LightComponent : public IComponent
#else
#ifdef __APPLE__  
class LightComponent : public IComponent
#endif
#ifdef  __linux__
class LightComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class LightComponent : public IComponent
#endif
#endif
{
private:

   int _id;
  
public:

    LightComponent();
     
    void SetId(int id);

    int GetId();
};

} // namespace ObjectSystem
} // namespace Engine