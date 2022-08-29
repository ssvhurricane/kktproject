#pragma once

#include "../../../../KKTEngine.h"
#include "../../../../CoreLayer/LogSystem/LogSystem.h"
#include "../../Base/IComponent.h"

#include <assimp/Importer.hpp> // TODO: Remove this
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Engine {
namespace ObjectSystem {
#ifdef _WIN32
class ENGINE_API MeshComponent : public IComponent
#else
#ifdef __APPLE__  
class MeshComponent : public IComponent
#endif
#ifdef  __linux__
class MeshComponent : public IComponent
#endif
#ifdef __EMSCRIPTEN__
class MeshComponent : public IComponent
#endif
#endif
{
private:

   int _id;

  
public:

    MeshComponent();
     
    void SetId(int id);

    int GetId();
};

} // namespace ObjectSystem
} // namespace Engine