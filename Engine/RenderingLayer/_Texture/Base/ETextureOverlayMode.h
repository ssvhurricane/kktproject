#pragma once

namespace Engine {
namespace RenderSystem {

enum ETextureOverlayMode
{
    REPEAT = GL_REPEAT,
    MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    CLAMP_TO_BORDER =GL_CLAMP_TO_BORDER
};

} // namespace RenderSystem
} // namespace Engine