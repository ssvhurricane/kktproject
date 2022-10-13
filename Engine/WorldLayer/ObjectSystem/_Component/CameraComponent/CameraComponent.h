// TODO:.
#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"
#include "Base/ECameraMovementMode.h"

#include "../../../../RenderingLayer/Base/ICamera.h"
#include "../../../../RenderingLayer/_Camera/Base/ECameraType.h"
#include "../../../../RenderingLayer/_Camera/Base/ECameraProjectionType.h"
#include "../../../../RenderingLayer/_Camera/Camera.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

// Параметры камеры по умолчанию
const float YAW         = -90.0f;
const float PITCH       =  0.0f;
const float SPEED       =  2.5f;
const float SENSITIVITY =  0.1f;
const float ZOOM        =  45.0f;

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API CameraComponent : public IComponent
#else
#ifdef __APPLE__  
class CameraComponent : public IComponent
#endif
#ifdef  __linux__
class CameraComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class CameraComponent : public IComponent
#endif
#endif
{
private:

    int _id; 
    
    Engine::RenderSystem::ECameraType _cameraType;

    Engine::RenderSystem::ECameraProjectionType _cameraProjectionType; 

    Engine::RenderSystem::ICamera* _camera;

    void UpdateCameraVectors();

public:

    // Атрибуты камеры
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    
    // углы Эйлера
    float Yaw;
    float Pitch;

    // Настройки камеры
    float MovementSpeed;
    float MouseSensitivity;
    float Zoom;

    CameraComponent(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH);
   
    CameraComponent(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    void SetId(int id);

    int GetId();

    void SetCamera(Engine::RenderSystem::ICamera* camera);

    Engine::RenderSystem::ICamera* GetCamera();
    
    void SetCameraType(Engine::RenderSystem::ECameraType eCameraType);

    Engine::RenderSystem::ECameraType GetCameraType();

    void SetCameraProjectionType(Engine::RenderSystem::ECameraProjectionType eCameraProjectionType);

    Engine::RenderSystem::ECameraProjectionType GetCameraProjectionType();

    glm::mat4 GetViewMatrix();

    void ProcessKeyboard(ECameraMovementMode direction, float deltaTime);

    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch = true);

    void ProcessMouseScroll(float yoffset);
};

} // namespace ObjectSystem
} // namespace Engine