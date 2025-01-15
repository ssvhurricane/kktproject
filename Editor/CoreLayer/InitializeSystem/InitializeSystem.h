// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/IAdvancedSystem.h"
#include "base_context/Defines.h"

#include "../../_Context/EditorContextInstaller.h"

namespace Editor {
namespace InitializeSystem {
    
#ifdef _WIN32
class ENGINE_API InitializeSystem : public IAdvancedSystem
#else
#ifdef __APPLE__  
class InitializeSystem : public IAdvancedSystem
#endif
#ifdef  __linux__
class InitializeSystem : public IAdvancedSystem
#endif
#ifdef  __EMSCRIPTEN__
class InitializeSystem : public IAdvancedSystem
#endif
#endif
{
private:

    IContextInstaller* _context;

public:

    InitializeSystem();

    void Initialize(IContextInstaller* _mainContext);

    IContextInstaller* GetContext();
};

} // namespace InitializeSystem
} // namespace Editor