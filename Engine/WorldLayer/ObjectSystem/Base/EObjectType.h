#pragma once

namespace Engine {
namespace ObjectSystem {

enum EObjectType 
{
    // You can also combine both.
    BasicObject, // Use for 3d objects, props, UI(in world).
    UIObject // Use for 2d objects, props, ui.
};

} // namespace ObjectSystem
} // namespace Engine
