#pragma once
#include "base_context/IContextInstaller.h"

struct IAdvancedSystem
{ 
    // TODO:
    virtual void Initialize(IContextInstaller* _mainContext) = 0;
};
