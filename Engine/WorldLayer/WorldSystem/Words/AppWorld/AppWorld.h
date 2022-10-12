#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../Base/EWorldType.h"
#include "../../Base/EWorldMode.h"
#include "../../Base/IWorld.h"

namespace Engine {
namespace WorldSystem {

class AppWorld : public IWorld
{
private:

    int _id;

    std::string _name;

    EWorldType _type;

public:

    AppWorld();

    void Initialize(std::string, EWorldType, EWorldMode);

    void StartSimulate();

    void StopSimulate();

    void ReStart();

    int GetId();

    EWorldType GetType();

    std::string GetName();

    void SetCurrentMode(EWorldMode);

    EWorldMode GetCurrentMode();

};

} // namespace WorldSystem
} // namespace Engine