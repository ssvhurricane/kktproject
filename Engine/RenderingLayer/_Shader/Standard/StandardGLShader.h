// TODO: Standard GL Shader Type.
#pragma once

#include "../../../KKTEngine.h"
#include "../../Base/IShader.h"

namespace Engine {
namespace RenderSystem {

class StandardGLShader : public IShader
{
    // TODO:
private:
    unsigned int ID;
public:

    StandardGLShader(const char* vertexPath, const char* fragmentPath);
    
    void Use();

    void SetBool(const std::string &name, bool value) const;  

    void SetInt(const std::string &name, int value) const;  

    void SetFloat(const std::string &name, float value) const;

};

} // namespace RenderSystem
} // namespace Engine