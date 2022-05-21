#pragma once

#include "../../KKTEngine.h"

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "Base/IPlaceHolder.h"
#include "Base/EPlaceHolderType.h"

namespace Engine {
namespace PlaceHolderRenderSystem {
#if defined _WIN32
class ENGINE_API PlaceHolderRenderSystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class PlaceHolderRenderSystem : public ISystem
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