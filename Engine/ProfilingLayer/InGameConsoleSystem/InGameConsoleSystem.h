// TODO: None add in context system.
#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace InGameConsoleSystem{

class InGameConsoleSystem : public ISystem
{
private:
    // TODO:
public:

    InGameConsoleSystem();

    void Initialize();
};
} // namespace InGameConsoleSystem
} // namespace Engine