// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

#include "../../_Context/EditorContextInstaller.h"

namespace Editor {
namespace StartSystem {
#ifdef _WIN32
class ENGINE_API StartSystem : public ISystem
#else
#ifdef __APPLE__ 
class StartSystem : public ISystem
#endif
#ifdef __linux__
class StartSystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class StartSystem : public ISystem
#endif
#endif
{
public:

    StartSystem();

    void Initialize();

    void Play();

    void Pause(bool isPaused);
};

} // namespace StartSystem
} // namespace Editor