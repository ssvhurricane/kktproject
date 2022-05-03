// This is non Context System (you can't use distanced services here).
#pragma once

#include <iostream>
#include <map>

#include "base_context/IContextInstaller.h"
#include "../_System/UISystem/UISystem.h"

namespace UI {
namespace _Context {

class UIContextInstaller : public IContextInstaller
{
private: 

    std::map<ESystemType, ISystem*> _systems;

    void InstallBindings();

    void CreateContext();

public: 
     
    UIContextInstaller();

    ISystem* GetSystem(ESystemType);
};


} // namespace _Context
} // namespace UI