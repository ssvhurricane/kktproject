#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

#include "../../../../UILayer/_Control/Canvas/Canvas.h"
#include "../../../../UILayer/UISystem/UISystem.h" // TODO: Use system for create canvas.h

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API CanvasComponent : public IComponent
#else
#ifdef __APPLE__  
class CanvasComponent : public IComponent
#endif
#ifdef  __linux__
class CanvasComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class CanvasComponent : public IComponent
#endif
#endif
{
private:

   int _id;
  
public:

    CanvasComponent();
     
    void SetId(int id);

    int GetId();
};

} // namespace ObjectSystem
} // namespace Engine