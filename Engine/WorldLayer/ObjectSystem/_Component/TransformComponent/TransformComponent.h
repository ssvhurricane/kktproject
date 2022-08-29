#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

#include "Base/Position.h"
#include "Base/Rotation.h"
#include "Base/Scale.h"

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API TransformComponent : public IComponent
#else
#ifdef __APPLE__  
class TransformComponent : public IComponent
#endif
#ifdef  __linux__
class TransformComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class TransformComponent : public IComponent
#endif
#endif
{
private:

   int _id;

   Position _position;

   Rotation _rotation;

   Scale _scale;

public:

    TransformComponent();
     
    void SetId(int id);

    int GetId();

    void SetPostion(int x, int y, int z);

    //void SetPostion(Vector3 vec3);

    //Vector3 GetPostion();
};

} // namespace ObjectSystem
} // namespace Engine