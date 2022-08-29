#include "Texture2D.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stbimage/stb_image.h"

namespace Engine {
namespace RenderSystem {

Texture2D::Texture2D(ETextureType eTextureType, ETextureOverlayMode eTextureOverlayMode)
{
    // Устанавливаем параметры наложения и фильтрации текстур (для текущего связанного объекта текстуры)
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
   glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture2D::PrepareTexture(unsigned int& texture)
{
    glGenTextures(1, &texture);

    glBindTexture(GL_TEXTURE_2D, texture);

    ID = texture;
}

unsigned char* Texture2D::LoadTexture(const char* fileName, int width, int height, int nrChannels, bool isUseAlphaChl)
{
    auto data = stbi_load(fileName, &width, &height, &nrChannels, 0);
    if (data)
    {
        if(!isUseAlphaChl)
             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        else
             glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        
        glGenerateMipmap(GL_TEXTURE_2D);

        dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                   ->GetContext()
                                   ->GetSystem(ESystemType::LogSystem))
                                   ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Texture load complete.",
                                        Engine::LogSystem::ELogOutputLocationType::All);

        return data;
    }
    else
    {
        dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                   ->GetContext()
                                   ->GetSystem(ESystemType::LogSystem))
                                   ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                        "Failed to load texture!",
                                        Engine::LogSystem::ELogOutputLocationType::All);
        return nullptr;
    }

}

void Texture2D::UnloadTexture(void* texture)
{
    if(texture)
        stbi_image_free(texture);
    else
        dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                   ->GetContext()
                                   ->GetSystem(ESystemType::LogSystem))
                                   ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                        "Texture data null!",
                                        Engine::LogSystem::ELogOutputLocationType::All);
}

} // namespace RenderSystem
} // names