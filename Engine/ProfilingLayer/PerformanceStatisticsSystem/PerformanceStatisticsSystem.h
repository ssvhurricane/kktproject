// TODO: None add in context system.
#pragma once

#include "../../KKTEngine.h"
#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace Engine {
namespace PerformanceStatisticsSystem{

class PerformanceStatisticsSystem : public ISystem
{
private:
    // TODO:
public:

    PerformanceStatisticsSystem();

    void Initialize();
};
} // namespace PerformanceStatisticsSystem
} // namespace Engine