#pragma once
#include <string>
#include <map>

#include "base_context/ISystem.h"
#include "base_context/Defines.h"


#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "NuklearUISystem/NuklearUISystem.h"
#include "ImgGuiUISystem/ImgGuiUISystem.h"

namespace Engine {
namespace UISystem {
#ifdef _WIN32
class ENGINE_API UISystem : public ISystem
#else
#ifdef __APPLE__ 
class UISystem : public ISystem
#endif
#ifdef  __linux__
class UISystem : public ISystem
#endif
#ifdef __EMSCRIPTEN__
class UISystem : public ISystem
#endif
#endif
{
private:
    ISystem* _uiSystem;
   // std::map<std::string, nk_context*> _uiContexts;
   
public:

    UISystem();

    void Initialize();

    void CreateContext(std::string name, GLFWwindow *window);

    void GetContextByName(std::string name);

    void DemoRender();

    void Clear();
};

} // namespace UISystem
} // namespace Engine