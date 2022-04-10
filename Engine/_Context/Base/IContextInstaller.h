#pragma once

#include "ISystem.h"

namespace Engine {
namespace _Context {

struct IContextInstaller 
{ 
    virtual void GetSystem(ISystem*) = 0;
};

} // namespace _Context
} // namespace Engine
