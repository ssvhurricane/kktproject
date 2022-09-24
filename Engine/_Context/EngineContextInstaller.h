// This is non Context System (you can't use distanced services here).
#pragma once

#include <iostream>
#include <map>

#include "base_context/IContextInstaller.h"

// Add Base systems. This place for add system headers, then use all.
#include "../CoreLayer/AnalyticSystem/AnalyticSystem.h"
#include "../CoreLayer/ApprovalSystem/ApprovalSystem.h"
#include "../CoreLayer/ConfigSystem/ConfigSystem.h"
#include "../CoreLayer/CRSystem/CRSystem.h"
#include "../CoreLayer/FileSystem/FileSystem.h"
#include "../CoreLayer/LocalizationSystem/LocalizationSystem.h"
#include "../CoreLayer/LogSystem/LogSystem.h"
#include "../CoreLayer/MathSystem/MathSystem.h"
#include "../CoreLayer/MemorySystem/MemorySystem.h"
#include "../CoreLayer/ParserSystem/ParserSystem.h"
#include "../CoreLayer/RandomNumGenSystem/RandomNumGenSystem.h"
#include "../CoreLayer/RTTISystem/RTTISystem.h"
#include "../CoreLayer/StringSystem/StringSystem.h"
#include "../CoreLayer/VideoSystem/VideoSystem.h"

#include "../InputLayer/InputSystem/InputSystem.h"

#include "../NetworkLayer/NetworkSystem/NetworkSystem.h"

#include "../PhysicLayer/PhysicSystem/PhysicSystem.h"

#include "../ProfilingLayer/ProfilingSystem/ProfilingSystem.h"

#include "../UILayer/UISystem/UISystem.h"
#include "../RenderingLayer/RenderSystem/RenderSystem.h"

#include "../ResourceLayer/ResourceSystem/ResourceSystem.h"

#include "../TestLayer/TestSystem/TestSystem.h"

#include "../WorldLayer/WorldSystem/WorldSystem.h"
#include "../WorldLayer/SceneSystem/SceneSystem.h"
#include "../WorldLayer/ObjectSystem/ObjectSystem.h"

// Add SubSystems.
#include "../_SubSystem/ProjectSubSystem/ProjectSubSystem.h"
#include "../_SubSystem/SceneSubSystem/SceneSubSystem.h"

#include "../AILayer/AISystem/AISystem.h"
#include "../AnimationLayer/AnimationSystem/AnimationSystem.h"
#include "../AudioLayer/AudioSystem/AudioSystem.h"

namespace Engine {
namespace _Context {

class EngineContextInstaller : public IContextInstaller
{
private:

    std::map<ESystemType, ISystem*> _systems;

    void InstallBindings();

    void CreateContext();

public: 

    EngineContextInstaller();

    ISystem* GetSystem(ESystemType);
};


} // namespace _Context
} // namespace Engine