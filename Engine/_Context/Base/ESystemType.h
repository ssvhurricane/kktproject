#pragma once

namespace Engine {
namespace _Context {

enum ESystemType 
{
    // PlatformSpecificLayer.
    FileSystem,
    GraphicShellSystem,
    NetworkSystem,
    PhysicsAndCollisionsShellSystem,

    // CoreLayer.
    LogSystem

};

} // namespace Engine
} // namespace _Context
