#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../_Context/Base/ISystem.h"
#include "../../../../_Context/Base/Defines.h"
#include "../../Base/EWorldType.h"
#include "../../Base/EWorldMode.h"
#include "../../Base/IWorld.h"

namespace Engine {
namespace WorldSystem {

class BasicWorld : public IWorld
{
private:

    int _id;

    std::string _name;

    EWorldType _type;

public:

    BasicWorld();

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