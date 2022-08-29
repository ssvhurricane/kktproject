#pragma once

namespace Engine {
namespace RenderSystem {

enum ETextureFilteringMipMapMode
{
    NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
    LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST,
    NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR,
    LINEAR_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR
};

} // namespace RenderSystem
} // namespace Engine