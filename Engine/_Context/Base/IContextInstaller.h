#pragma once

#include "ISystem.h"
#include "ESystemType.h"

namespace Engine {
namespace _Context {

struct IContextInstaller 
{ 
    virtual ISystem* GetSystem(ESystemType) = 0;
};

} // namespace _Context
} // namespace Engine
