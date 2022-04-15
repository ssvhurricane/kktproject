#pragma once

#include <string>

#include "EWorldType.h"

namespace Engine {
namespace WorldSystem {

struct IWorld
{
    virtual void Initialize(std::string, EWorldType) = 0;

    virtual void StartSimulate() = 0;

    virtual void StopSimulate() = 0;

    virtual void ReStart() = 0;

    virtual int GetId() = 0;

    virtual EWorldType GetType() = 0;

    virtual std::string GetName() = 0;
};

} // namespace WorldSystem
} // namespace Engine