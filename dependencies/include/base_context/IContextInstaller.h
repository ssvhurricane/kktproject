#pragma once

#include "ISystem.h"
#include "ESystemType.h"

struct IContextInstaller 
{ 
    virtual ISystem* GetSystem(ESystemType) = 0;
};

