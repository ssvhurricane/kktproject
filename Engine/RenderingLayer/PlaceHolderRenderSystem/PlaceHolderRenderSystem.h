#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/IPlaceHolder.h"
#include "Base/EPlaceHolderType.h"

#include "../Base/EWindowRenderApiSystemType.h"

namespace Engine {
namespace PlaceHolderRenderSystem {
#ifdef _WIN32
class ENGINE_API PlaceHolderRenderSystem : public ISystem
#else
#ifdef  __APPLE__
class PlaceHolderRenderSystem : public ISystem
#endif
#ifdef  __linux__
class PlaceHolderRenderSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class PlaceHolderRenderSystem : public ISystem
#endif
#endif
{
private:

   // TODO:
public:
    PlaceHolderRenderSystem();

    // TODO:

}; 

} // namespace PlaceHolderRenderSystem
} // namespace Engine