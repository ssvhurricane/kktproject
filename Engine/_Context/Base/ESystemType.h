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
    WorldSystem,
    SceneSystem,
    ObjectSystem

};

} // namespace Engine
} // namespace _Context
