// TODO: Text and his localization func.
#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API TextComponent : public IComponent
#else
#ifdef __APPLE__  
class TextComponent : public IComponent
#endif
#ifdef  __linux__
class TextComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class TextComponent : public IComponent
#endif
#endif
{
private:

   int _id;
  
public:

    TextComponent();
     
    void SetId(int id);

    int GetId();
};

} // namespace ObjectSystem
} // namespace Engine