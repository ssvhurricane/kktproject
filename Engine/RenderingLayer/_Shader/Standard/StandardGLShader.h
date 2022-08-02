// TODO: Standard GL Shader Type.
#pragma once

#include <glad/glad.h>

#include "../../../KKTEngine.h"
#include "../../Base/IShader.h"
#include "../../../CoreLayer/LogSystem/LogSystem.h"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdio.h>

namespace Engine {
namespace RenderSystem {
class StandardGLShader : public IShader
{
    // TODO:
private:

    void CheckCompileErrors(unsigned int shader, std::string type);

public: 

    unsigned int ID; // TODO

    StandardGLShader(const char* vertexPath, const char* fragmentPath);
   
    void Use();

    void SetBool(const std::string &name, bool value) const;  

    void SetInt(const std::string &name, int value) const;  

    void SetFloat(const std::string &name, float value) const;

};

} // namespace RenderSystem
} // namespace Engine