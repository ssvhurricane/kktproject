#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API MaterialComponent : public IComponent
#else
#ifdef __APPLE__  
class MaterialComponent : public IComponent
#endif
#ifdef  __linux__
class MaterialComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class MaterialComponent : public IComponent
#endif
#endif
{
private:

   int _id;
  
public:

    MaterialComponent();
     
    void SetId(int id);

    int GetId();
};

} // namespace ObjectSystem
} // namespace Engine