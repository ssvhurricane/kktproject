// This is non Context System (you can't use distanced services here).
#pragma once

#include <iostream>
#include <map>
#include <algorithm>

#include "Base/IContextInstaller.h"
#include "../CoreLayer/LogSystem/LogSystem.h" // This place for add system headers, then use all.
#include "../RenderingLayer/RenderSystem/RenderSystem.h"

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