// TODO: Standard GL Shader Type.
#pragma once

#include <glad/glad.h>

#include "../../../KKTEngine.h"
#include "../../Base/IShader.h"
#include "../Base/EShaderRenderType.h"

#include <fstream>
#include <sstream>
#include <iostream>

namespace Engine {
namespace RenderSystem {
class StandardGLShader : public IShader
{
    // TODO:
private:

    unsigned int ID;

    void CheckCompileErrors(unsigned int shader, std::string type);

public:

    StandardGLShader(const char* vertexPath, const char* fragmentPath, EShaderRenderType shaderRenderType = EShaderRenderType::OpenGLShader);
   
    void Use();

    void SetBool(const std::string &name, bool value) const;  

    void SetInt(const std::string &name, int value) const;  

    void SetFloat(const std::string &name, float value) const;

};

} // namespace RenderSystem
} // namespace Engine