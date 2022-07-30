#pragma once

#include "../_Texture/Base/ETextureFilteringMipMapMode.h" 
#include "../_Texture/Base/ETextureFilteringMode.h" 
#include "../_Texture/Base/ETextureOverlayMode.h" 
#include "../_Texture/Base/ETextureType.h"

namespace Engine {
namespace RenderSystem {

struct ITexture
{ 
   virtual unsigned char* LoadTexture(const char* fileName, int width, int height, int nrChannels) = 0;
   virtual void UnloadTexture(char* texture) = 0;
};

} // namespace _Context
} // namespace Engine
