#pragma once

#include <string>
#include <vector>

#include "EObjectType.h"

namespace Engine {
namespace ObjectSystem {

struct IObject
{
    virtual void Initialize(std::string, EObjectType) = 0;

    virtual int GetId() = 0;

    virtual EObjectType GetType() = 0;

    virtual std::string GetName() = 0;
 
};

} // namespace ObjectSystem
} // namespace Engine
