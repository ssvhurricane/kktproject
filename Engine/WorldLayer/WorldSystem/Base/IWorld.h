#pragma once

#include <string>

#include "EWorldType.h"
#include "EWorldMode.h"

namespace Engine {
namespace WorldSystem {

struct IWorld
{
    virtual void Initialize(std::string, EWorldType, EWorldMode) = 0;

    virtual void StartSimulate() = 0;

    virtual void StopSimulate() = 0;

    virtual void ReStart() = 0;

    virtual int GetId() = 0;

    virtual EWorldType GetType() = 0;

    virtual std::string GetName() = 0;

    virtual void SetCurrentMode(EWorldMode) = 0;

    virtual EWorldMode GetCurrentMode() = 0;
};

} // namespace WorldSystem
} // namespace Engine