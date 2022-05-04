#pragma once

#include <string>
#include <map>

#include "base_context/ISystem.h"
#include "base_context/Defines.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine {
namespace UISystem {
#if defined _WIN32
class ENGINE_API UISystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class UISystem : public ISystem
#endif
{
private:

    //std::map<std::string, nk_context*> _uiContexts;
public:

    UISystem();

    void Initialize();

    void CreateContext(std::string name, GLFWwindow *window);

    void GetContextByName(std::string name);

    void DemoRender();
};

} // namespace UISystem
} // namespace Engine