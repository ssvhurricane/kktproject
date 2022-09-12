#include "OpenglRenderSystem.h"

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#define GL_GLEXT_PROTOTYPES
#define EGL_EGLEXT_PROTOTYPES
#else
#include <glad/glad.h>
#endif

#include <GLFW/glfw3.h>

namespace Engine {
namespace OpenglRenderSystem {
    
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);

unsigned int SCR_WIDTH;
unsigned int SCR_HEIGHT;

char *vertexShaderSource;
char *fragmentShaderSource;

// Камера
Engine::ObjectSystem::CameraComponent camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;

bool firstMouse = true;

// Тайминги
float deltaTime = 0.0f;	// время между текущим кадром и последним кадром
float lastFrame = 0.0f;

std::function<void()> loop;
void main_loop() { loop(); }

void OpenglRenderSystem::RenderWorld(Engine::WorldSystem::IWorld* world)
{
	// TODO:
}

void OpenglRenderSystem::RenderScene(Engine::SceneSystem::IScene* scene)
{
	// TODO:
}

void OpenglRenderSystem::RenderObject(Engine::ObjectSystem::IObject* object)
{
	// TODO:
}

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
                                        "OpenGL Rendering...",
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
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

    // Сообщаем GLFW, чтобы он захватил наш курсор
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED); // TODO: bug webgl pointer

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Конфигурирование глобального состояния OpenGL
	glEnable(GL_DEPTH_TEST);

    glfwSwapInterval(1);

    auto fileSystem  = dynamic_cast<Engine::FileSystem::FileSystem*>(Engine::KKTEngine::InstancePtr()
                                                                                            ->GetContext()
                                                                                            ->GetSystem(ESystemType::FileSystem));
                                
#ifdef _WIN32 // TOD REF:
Engine::RenderSystem::StandardGLShader shader(fileSystem->GetFileData("C:/Users/Admin/Desktop/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample4/ShaderExample4.vs"),
                                              fileSystem->GetFileData("C:/Users/Admin/Desktop/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample4/ShaderExample4.fs")); 
       
#else 
#ifdef __APPLE__ 
Engine::RenderSystem::StandardGLShader shader(fileSystem->GetFileData("/Volumes/DataSSD/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample4/ShaderExample4.vs"), 
                                              fileSystem->GetFileData("/Volumes/DataSSD/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample4/ShaderExample4.fs")); 
#endif
#ifdef __linux__
Engine::RenderSystem::StandardGLShader shader(fileSystem->GetFileData("/home/sergei/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample4/ShaderExample4.vs"),
											 fileSystem->GetFileData("/home/sergei/Projects/kkt/EngineDemo/Content/Shaders/ShaderExample4/ShaderExample4.fs")); 
#endif
#ifdef __EMSCRIPTEN__

Engine::RenderSystem::StandardGLShader shader(fileSystem->GetFileData("Content/Shaders/ShaderExample4/ShaderExample4_webgl.vs"), 
                                            fileSystem->GetFileData("Content/Shaders/ShaderExample4/ShaderExample4_webgl.fs")); 
#endif
#endif

   // Указание вершин (и буфера(ов)) и настройка вершинных атрибутов
	float vertices[] = {
		  // координаты        // текстурные координаты
		 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
		  0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		  0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
		 -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
		 -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
	};

	// Мировые координаты наших кубиков
	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};

	unsigned int VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// Координатные атрибуты
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// Атрибуты текстурных координат
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);

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
   data = texture2D_1.LoadTexture("/home/sergei/Projects/kkt/EngineDemo/Content/Graphics/Textures/wooden_container.jpg",  width, height, nrChannels);
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
     data = texture2D_2.LoadTexture("/home/sergei/Projects/kkt/EngineDemo/Content/Graphics/Textures/awesomeface.png", width, height, nrChannels, true);
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
      
        // Логическая часть работы со временем для каждого кадра
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		// Обработка ввода
		processInput(window);

		// Рендеринг
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищаем буфер цвета и буфер глубины

		// Привязка текстур к соответствующим текстурным юнитам
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);

		// Активируем шейдер
		shader.Use();
		
		// Передаем шейдеру матрицу проекции (поскольку проекционная матрица редко меняется, то нет необходимости делать это для каждого кадра)
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		shader.SetMat4("projection", projection);

		// Создаем преобразование камеры/вида
		glm::mat4 view = camera.GetViewMatrix();
		shader.SetMat4("view", view);

		// Рендерим ящик
		glBindVertexArray(VAO);
		for (unsigned int i = 0; i < 10; i++)
		{
			// Вычисляем матрицу модели для каждого объекта и передаем её в шейдер до отрисовки
			glm::mat4 model = glm::mat4(1.0f);
			model = glm::translate(model, cubePositions[i]);
			float angle = 20.0f * i;
			model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
			shader.SetMat4("model", model);

			glDrawArrays(GL_TRIANGLES, 0, 36);
        }

       // gameUI->DemoRender();
 
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
  //  glDeleteBuffers(1, &EBO);
     
    gameUI->Clear();
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
   
    glfwTerminate();
    
    }
    else
	{
		// TODO:
		// Get current world.
		auto worldSystem = dynamic_cast<Engine::WorldSystem::WorldSystem*>(Engine::KKTEngine::InstancePtr()
																				 				->GetContext()
                               																	->GetSystem(ESystemType::WorldSystem));
                               
		RenderWorld(worldSystem->GetCurrentWorld());

		// Get current scene(s).
        auto sceneSystem = dynamic_cast<Engine::SceneSystem::SceneSystem*>(Engine::KKTEngine::InstancePtr()
																				 				->GetContext()
                               																	->GetSystem(ESystemType::SceneSystem));
		
		RenderScene(sceneSystem->GetCurrentScene());
		
		// Get Objects.
		auto objectSystem = dynamic_cast<Engine::ObjectSystem::ObjectSystem*>(Engine::KKTEngine::InstancePtr()
																				 				->GetContext()
                               																	->GetSystem(ESystemType::ObjectSystem));
		auto objects = objectSystem->GetAllObjects();		

		for (auto objectItem : objects) RenderObject(objectItem.second);
       
	}

	return 0;
}

void OpenglRenderSystem::Initialize()
{
    // TODO:
}

// Обработка всех событий ввода: запрос GLFW о нажатии/отпускании кнопки мыши в данном кадре и соответствующая обработка данных событий
void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(Engine::ObjectSystem::ECameraMovementMode::FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(Engine::ObjectSystem::ECameraMovementMode::BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(Engine::ObjectSystem::ECameraMovementMode::LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(Engine::ObjectSystem::ECameraMovementMode::RIGHT, deltaTime);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

// glfw: всякий раз, когда перемещается мышь, вызывается данная callback-функция
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // перевернуто, так как y-координаты идут снизу вверх

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: всякий раз, когда прокручивается колесико мыши, вызывается данная callback-функция
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

} // namespace  OpenglRenderSystem
} // namespace Engine