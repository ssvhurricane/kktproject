#pragma once

#include <iostream>
#include <map>

#include "base_context/IContextInstaller.h"

// Add Base systems. This place for add system headers, then use all.
#include "../CoreLayer/ConfigSystem/ConfigSystem.h"
#include "../RenderingLayer/RenderSystem/RenderSystem.h"
#include "../CoreLayer/LogSystem/LogSystem.h"
namespace Editor {
namespace _Context {
class EditorContextInstaller : public IContextInstaller
{
private:

    std::map<ESystemType, ISystem*> _systems;

    void InstallBindings();

    void CreateContext();

public:

    EditorContextInstaller();

    ISystem* GetSystem(ESystemType);
};
} // namespace _Context
} // namespace Editor