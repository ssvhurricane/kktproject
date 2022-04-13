#pragma once

namespace Engine {
namespace _Context {

enum ESystemType 
{
    // - PlatformSpecificLayer.
    //FileSystem,
    //GraphicShellSystem,
    //NetworkSystem,
    //PhysicsAndCollisionsShellSystem,

    // CoreLayer.
    LogSystem,

    // Rendering Layer.
    RenderSystem,

    // World Layer.
    WorldSystem

};

} // namespace Engine
} // namespace _Context
