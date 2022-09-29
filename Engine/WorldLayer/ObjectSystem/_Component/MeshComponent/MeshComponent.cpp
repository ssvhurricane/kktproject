#include "MeshComponent.h"

namespace Engine {
namespace ObjectSystem {

MeshComponent::MeshComponent()
{
    // TODO:
}

void MeshComponent::SetId(int id)
{
   _id = id;
}

int MeshComponent::GetId()
{
    return _id;
}

} // namespace ObjectSystem
} // namespace Engine