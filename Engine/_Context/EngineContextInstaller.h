// This is non Context System (you can't use distanced services here).
#pragma once

#include <iostream>
#include <map>

#include "base_context/IContextInstaller.h"
#include "../CoreLayer/LogSystem/LogSystem.h" // This place for add system headers, then use all.
#include "../RenderingLayer/RenderSystem/RenderSystem.h"
#include "../WorldLayer/WorldSystem/WorldSystem.h"
#include "../WorldLayer/SceneSystem/SceneSystem.h"
#include "../WorldLayer/ObjectSystem/ObjectSystem.h"

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