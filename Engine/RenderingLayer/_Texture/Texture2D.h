// TODO: Standard GL Shader Type.
#pragma once

#include "../../KKTEngine.h"
#include "../Base/ITexture.h"
#include "../../CoreLayer/LogSystem/LogSystem.h"

#include <glad/glad.h>

namespace Engine {
namespace RenderSystem {
class Texture2D : public ITexture
{
private:
    int ID;
public:

    Texture2D(ETextureType eTextureType, ETextureOverlayMode eTextureOverlayMode);

    void PrepareTexture(unsigned int& texture);

    unsigned char* LoadTexture(const char* fileName, int width, int height, int nrChannels,  bool isUseAlphaChl = false);

    void UnloadTexture(void* texture);
};

} // namespace RenderSystem
} // namespace Engine