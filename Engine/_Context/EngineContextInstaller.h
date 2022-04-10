#pragma once

#include <iostream>
#include "Base/IContextInstaller.h"
#include "../CoreLayer/LogSystem/LogSystem.h"

namespace Engine {
namespace _Context {

class EngineContextInstaller : public IContextInstaller
{
private:

    void InstallBindings();

    void CreateContext();

public: 

    EngineContextInstaller();

    void GetSystem(ISystem*);
};


} // namespace _Context
} // namespace Engine