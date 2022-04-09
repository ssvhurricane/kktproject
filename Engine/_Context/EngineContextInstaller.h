#ifndef ENGINE_CONTEXT_INSTALLER_H_
#define ENGINE_CONTEXT_INSTALLER_H_
#pragma once

#include <iostream>
#include "Base/IContextInstaller.h"

namespace Engine {
namespace _Context {

class EngineContextInstaller : public IContextInstaller
{
private:

    void InstallBindings();

    void CreateContext();

public: 

    EngineContextInstaller();

    void GetSystem();
};


} // namespace _Context
} // namespace Engine


#endif  // ENGINE_CONTEXT_INSTALLER_H_