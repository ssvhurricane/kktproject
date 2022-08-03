#include "OpenglRenderSystem.h"
#include <functional>
#include <vector>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../_Shader/Standard/StandardGLShader.h"
#include "../_Texture/Texture2D.h"

namespace Engine {
namespace OpenglRenderSystem {
    
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

unsigned int SCR_WIDTH;
unsigned int SCR_HEIGHT;

char *vertexShaderSource;
char *fragmentShaderSource;


std::function<void()> loop;
void main_loop() { loop(); }

OpenglRenderSystem::OpenglRenderSystem()
{
   SCR_WIDTH = 800;
   SCR_HEIGHT = 600;
}

int OpenglRenderSystem::Render(bool bDemoMode)
{
    if(bDemoMode)
    {
   dynamic_cast<Engine::LogSystem::LogSystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::LogSystem))
                                ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Message,
                                        "Rendering.",
                                        Engine::LogSystem::ELogOutputLocationType::All);

     // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "[KKTEditor: ver.1.0.0] -> [KKTEngine: ver. 1.0.0] -> [ProjectName: MyProject]", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    glfwSwapInterval(1);

#ifdef _WIN32 // TOD REF:
Engine::RenderSystem::StandardGLShader shader(
        "C:/Users/Admin/Desktop/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample3/ShaderExample3.vs", 
        "C:/Users/Admin/Desktop/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample3/ShaderExample3.fs"); 
#else 
#ifdef __APPLE__ 
Engine::RenderSystem::StandardGLShader shader(
        "/Volumes/DataSSD/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample3/ShaderExample3.vs", 
        "/Volumes/DataSSD/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample3/ShaderExample3.fs"); 
#endif
#ifdef __linux__
Engine::RenderSystem::StandardGLShader shader( "", ""); 
#endif
#ifdef __EMSCRIPTEN__
Engine::RenderSystem::StandardGLShader shader("Content/Shaders/ShaderExample3/ShaderExample3_webgl.vs",
                                                            "Content/Shaders/ShaderExample3/ShaderExample3_webgl.fs" ); 
#endif
#endif

   // Указание вершин (и буфера(ов)) и настройка вершинных атрибутов
    float vertices[] = {
         // координаты        // цвета            // текстурные координаты
         0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f, // верхняя правая вершина
         0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f, // нижняя правая вершина
        -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f, // нижняя левая вершина
        -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f  // верхняя левая вершина 
    };
    unsigned int indices[] = {
        0, 1, 3, // первый треугольник
        1, 2, 3  // второй треугольник
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    // Координатные атрибуты
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
	
    // Цветовые атрибуты
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
	
    // Атрибуты текстурных координат
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    // Загрузка и создание текстуры
    int width, height, nrChannels;
    unsigned char* data;
   
    // texture1.
    unsigned int texture1;
	Engine::RenderSystem::Texture2D texture2D_1(Engine::RenderSystem::ETextureType::Tex2D, Engine::RenderSystem::ETextureOverlayMode::REPEAT);
                                                       
    texture2D_1.PrepareTexture(texture1);

#ifdef _WIN32 // TOD REF:
    data = texture2D_1.LoadTexture("C:/Users/Admin/Desktop/Projects/kkt/EngineDemo/Content/Graphics/Textures/wooden_container.jpg", width, height, nrChannels);
#else 
#ifdef __APPLE__ 
    data = texture2D_1.LoadTexture("/Volumes/DataSSD/Projects/kkt/EngineDemo/Content/Graphics/Textures/wooden_container.jpg",  width, height, nrChannels);
#endif
#ifdef __linux__
   // TODO:
#endif
#ifdef __EMSCRIPTEN__
    data = texture2D_1.LoadTexture("Content/Graphics/Textures/wooden_container.jpg", width, height, nrChannels);
#endif
#endif
  
    texture2D_1.UnloadTexture(data);

    // tex2.
    unsigned int texture2; 
    Engine::RenderSystem::Texture2D texture2D_2(Engine::RenderSystem::ETextureType::Tex2D, Engine::RenderSystem::ETextureOverlayMode::REPEAT);

    texture2D_2.PrepareTexture(texture2);

#ifdef _WIN32 // TOD REF:
    data = texture2D_2.LoadTexture("C:/Users/Admin/Desktop/Projects/kkt/EngineDemo/Content/Graphics/Textures/awesomeface.png", width, height, nrChannels, true);
#else 
#ifdef __APPLE__ 
    data = texture2D_2.LoadTexture("/Volumes/DataSSD/Projects/kkt/EngineDemo/Content/Graphics/Textures/awesomeface.png", width, height, nrChannels, true);
#endif
#ifdef __linux__
    
#endif
#ifdef __EMSCRIPTEN__
    data = texture2D_2.LoadTexture("Content/Graphics/Textures/awesomeface.png", width, height, nrChannels, true);
#endif
#endif
  
    texture2D_2.UnloadTexture(data);

    shader.Use();
    shader.SetInt("texture1", 0);
    shader.SetInt("texture2", 1);

    // Temp::Create and Init UI.
    auto gameUI = dynamic_cast<Engine::UISystem::UISystem*>
   (Engine::KKTEngine::InstancePtr()
                                ->GetContext()
                                ->GetSystem(ESystemType::UISystem));
 
    gameUI->CreateContext("", window);

 loop = [&] {
       // input
        // -----
        processInput(window);

       // Рендеринг
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Привязка текстур к соответствующим текстурным юнитам
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture1);
        glActiveTexture(GL_TEXTURE1);
        glBindTexture(GL_TEXTURE_2D, texture2);

         // Создаем преобразование
        glm::mat4 transform = glm::mat4(1.0f); // сначала инициализируем единичную матрицу
        transform = glm::translate(transform, glm::vec3(0.5f, -0.5f, 0.0f));
        transform = glm::rotate(transform, (float)glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));

        // Получаем location uniform-переменной матрицы и настраиваем её
        shader.Use();
        unsigned int transformLoc = glGetUniformLocation(shader.ID, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
        
        // Рендерим ящик
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        gameUI->DemoRender();
 
        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    };

    #ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(main_loop, 0, true);
#else
    while (!glfwWindowShouldClose(window))
        main_loop();
#endif

    // optional: de-allocate all resources once they've outlived their purpose:
    // ------------------------------------------------------------------------
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
     
    gameUI->Clear();
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
   
    glfwTerminate();

    
    }
    return 0;
}

void OpenglRenderSystem::Initialize()
{
    // TODO:
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


} // namespace  OpenglRenderSystem
} // namespace Engine