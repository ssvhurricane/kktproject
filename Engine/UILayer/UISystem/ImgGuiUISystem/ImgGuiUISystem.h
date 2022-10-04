#pragma once
#include <string>
#include <map>

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace UISystem {

class ImgGuiUISystem : public ISystem
{
private:
   // TODO:
public:

   ImgGuiUISystem();

   void Initialize();
};

} // namespace UISystem
} // namespace Engine