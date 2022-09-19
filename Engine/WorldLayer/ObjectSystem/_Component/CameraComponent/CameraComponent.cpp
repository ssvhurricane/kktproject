#include "CameraComponent.h"

namespace Engine {
namespace ObjectSystem {

CameraComponent::CameraComponent(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
{
    MovementSpeed = SPEED;
    MouseSensitivity = SENSITIVITY;
    Zoom = ZOOM;
   
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;

    UpdateCameraVectors();
}  
   
CameraComponent::CameraComponent(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch)
{
    MovementSpeed = SPEED;
    MouseSensitivity = SENSITIVITY;
    Zoom = ZOOM;

    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;

    UpdateCameraVectors();
}  
      
void CameraComponent::SetId(int id)
{
    _id = id;
}

int CameraComponent::GetId()
{
    return _id;
}

void CameraComponent::SetCamera(Engine::RenderSystem::ICamera* camera)
 {
    _camera = camera;
 }

Engine::RenderSystem::ICamera* CameraComponent::GetCamera()
{
    return _camera;
}

void CameraComponent::SetCameraType(Engine::RenderSystem::ECameraType eCameraType)
{
    // TODO:
}

Engine::RenderSystem::ECameraType CameraComponent::GetCameraType()
{
    // TODO:
    return Engine::RenderSystem::ECameraType::Free;
}

void CameraComponent::SetCameraProjectionType(Engine::RenderSystem::ECameraProjectionType eCameraProjectionType)
{
    // TODO:
}

Engine::RenderSystem::ECameraProjectionType CameraComponent::GetCameraProjectionType()
{
    // TODO:
    return Engine::RenderSystem::ECameraProjectionType::Orthographic;
}

glm::mat4 CameraComponent::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}

void CameraComponent::ProcessKeyboard(ECameraMovementMode direction, float deltaTime)
{
    float velocity = MovementSpeed * deltaTime;
    if (direction == FORWARD)
         Position += Front * velocity;
    if (direction == BACKWARD)
        Position -= Front * velocity;
    if (direction == LEFT)
        Position -= Right * velocity;
    if (direction == RIGHT)
        Position += Right * velocity;
}

void CameraComponent::ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch)
{
    xoffset *= MouseSensitivity;
    yoffset *= MouseSensitivity;

    Yaw  += xoffset;
     Pitch += yoffset;

    // Убеждаемся, что когда тангаж выходит за пределы обзора, экран не переворачивается
     if (constrainPitch)
    {
        if (Pitch > 89.0f)
            Pitch = 89.0f;
        if (Pitch < -89.0f)
             Pitch = -89.0f;
    }

    // Обновляем значения вектора-прямо, вектора-вправо и вектора-вверх, используя обновленные значения углов Эйлера
    UpdateCameraVectors();
}

void CameraComponent::ProcessMouseScroll(float yoffset)
{
    if (Zoom >= 1.0f && Zoom <= 45.0f)
         Zoom -= yoffset;
    if (Zoom <= 1.0f)
        Zoom = 1.0f;
     if (Zoom >= 45.0f)
        Zoom = 45.0f;
}

// Вычисляет вектор-прямо по (обновленным) углам Эйлера камеры
void CameraComponent::UpdateCameraVectors()
{
    // Вычисляем новый вектор-прямо
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // Также пересчитываем вектор-вправо и вектор-вверх
    Right = glm::normalize(glm::cross(Front, WorldUp));  // Нормализуем векторы, потому что их длина становится стремится к 0 тем больше, чем больше вы смотрите вверх или вниз, что приводит к более медленному движению.
    Up    = glm::normalize(glm::cross(Right, Front));
}

} // namespace ObjectSystem
} // namespace Engine