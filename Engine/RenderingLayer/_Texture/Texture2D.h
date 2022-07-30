// TODO: Standard GL Shader Type.
#pragma once

#include "../../KKTEngine.h"
#include "../Base/ITexture.h"
#include "../../CoreLayer/LogSystem/LogSystem.h"

#include <glad/glad.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stbimage/stb_image.h"

namespace Engine {
namespace RenderSystem {
class Texture2D : public ITexture
{
private:
    int ID;
public:

    Texture2D(ETextureType eTextureType, ETextureOverlayMode eTextureOverlayMode);

    unsigned char* LoadTexture(const char* fileName, int width, int height, int nrChannels);

    void UnloadTexture(char* texture);
};

} // namespace RenderSystem
} // namespace Engine