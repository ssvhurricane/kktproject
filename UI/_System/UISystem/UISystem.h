#pragma once

#include <string>
#include <map>

#include "base_context/ISystem.h"
#include "base_context/Defines.h"

namespace UI {
namespace UISystem {
#if defined _WIN32
class ENGINE_API UISystem : public ISystem
#elif defined __APPLE__  || defined __linux__
class UISystem : public ISystem
#endif
{
private:

    //std::map<std::string, nk_context*> _uiContexts;

    //struct nk_glfw glfw = {0};

   // struct nk_context *ctx; // TODO Ref.

   // int width = 0, height = 0;

public:

    UISystem();

    void Initialize();

    void CreateContext(std::string name/*, GLFWwindow *window*/);

    void GetContextByName(std::string name);

    void DemoRender();
};

} // namespace UISystem
} // namespace UI