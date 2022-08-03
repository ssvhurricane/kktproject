// TODO: Standard GL Shader Type.

#include "StandardGLShader.h"

namespace Engine {
namespace RenderSystem {

StandardGLShader::StandardGLShader(const char* vertexPath, const char* fragmentPath)
{ 
    const char* vShaderCode;
    const char * fShaderCode;
    
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
		
    // Убеждаемся, что объекты ifstream могут выбросить исключение
    vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try 
    {
    // Открываем файлы
    vShaderFile.open(vertexPath);
    fShaderFile.open(fragmentPath);
    std::stringstream vShaderStream, fShaderStream;
			
    // Считываем содержимое файловых буферов в потоки 
    vShaderStream << vShaderFile.rdbuf();
    fShaderStream << fShaderFile.rdbuf();
			
    // Закрываем файлы
    vShaderFile.close();
    fShaderFile.close();
			
    // Конвертируем данные из потока в строковые переменные
    vertexCode   = vShaderStream.str();
    fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "VertexCode: " + vertexCode,
                                        Engine::LogSystem::ELogOutputLocationType::All);

    vShaderCode = vertexCode.c_str();

    dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                   ->GetContext()
                                   ->GetSystem(ESystemType::LogSystem))
                                   ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "FragmentCode: " + fragmentCode,
                                        Engine::LogSystem::ELogOutputLocationType::All);

    fShaderCode = fragmentCode.c_str();
    
		
    // Этап №2: Компилируем шейдеры
    unsigned int vertex, fragment;
		
    // Вершинный шейдер
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    CheckCompileErrors(vertex, "VERTEX");
		
    // Фрагментный шейдер
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    CheckCompileErrors(fragment, "FRAGMENT");
		
    // Шейдерная программа
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    CheckCompileErrors(ID, "PROGRAM");
		
    // После того, как мы связали шейдеры с нашей программой, удаляем их, так как они нам больше не нужны
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
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
     else
    {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success)
        {
                glGetProgramInfoLog(shader, 1024, NULL, infoLog);
                std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
        }
    }
}
} // namespace RenderSystem
} // namespace Engine