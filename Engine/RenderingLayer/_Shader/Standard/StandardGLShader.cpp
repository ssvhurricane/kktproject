// TODO: Standard GL Shader Type.

#include "StandardGLShader.h"

namespace Engine {
namespace RenderSystem {

StandardGLShader::StandardGLShader(const std::string vShaderCode, const std::string fShaderCode)
{ 
      dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Vertex shader: " + (std::string)vShaderCode,
                                        Engine::LogSystem::ELogOutputLocationType::All);

    
      dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "fragment shader: " + (std::string)fShaderCode,
                                        Engine::LogSystem::ELogOutputLocationType::All);

    unsigned int vertex, fragment;
		
    // Vertex shader.
    vertex = glCreateShader(GL_VERTEX_SHADER);
    const char* vrt = vShaderCode.c_str();
    glShaderSource(vertex, 1, &vrt, NULL);
    glCompileShader(vertex);

    CheckCompileErrors(vertex, "VERTEX");
		
    // Fragment shader.
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    const char*frg = fShaderCode.c_str();
    glShaderSource(fragment, 1, &frg, NULL);
    glCompileShader(fragment);

    CheckCompileErrors(fragment, "FRAGMENT");
		
    // Shader program.
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    
    CheckCompileErrors(ID, "PROGRAM");
		
    // Delete shaders.
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
    
void StandardGLShader::Use()
{
     glUseProgram(ID); 
}

void StandardGLShader::SetBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
} 

void StandardGLShader::SetInt(const std::string &name, int value) const
{
     glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
}  

void StandardGLShader::SetFloat(const std::string &name, float value) const
{
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
}

void StandardGLShader::SetVec2(const std::string& name, const glm::vec2& value) const
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void StandardGLShader::SetVec2(const std::string& name, float x, float y) const
{
    glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y);
}   

void StandardGLShader::SetVec3(const std::string& name, const glm::vec3& value) const
{
    glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}
    
void StandardGLShader::SetVec3(const std::string& name, float x, float y, float z) const
{
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void StandardGLShader::SetVec4(const std::string& name, const glm::vec4& value) const
{
    glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]);
}

void StandardGLShader::SetVec4(const std::string& name, float x, float y, float z, float w) const
{
    glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
}

void StandardGLShader::SetMat2(const std::string& name, const glm::mat2& mat) const
{
     glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void StandardGLShader::SetMat3(const std::string& name, const glm::mat3& mat) const
{
    glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void StandardGLShader::SetMat4(const std::string& name, const glm::mat4& mat) const
{
     glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}

void StandardGLShader::CheckCompileErrors(unsigned int shader, std::string type)
{
    int success;

    char infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);

             dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                        "ERROR::SHADER_COMPILATION_ERROR of type: " +  type + "\n" + infoLog + "\n -- --------------------------------------------------- -- " ,
                                        Engine::LogSystem::ELogOutputLocationType::All);
        }
    }
     else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;

                dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                       "ERROR::PROGRAM_LINKING_ERROR of type: " + type + "\n" + infoLog + "\n -- --------------------------------------------------- -- " ,
                                        Engine::LogSystem::ELogOutputLocationType::All);
        }
    }
}

} // namespace RenderSystem
} // namespace Engine