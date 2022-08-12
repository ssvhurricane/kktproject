#include "MaterialComponent.h"

namespace Engine {
namespace ObjectSystem {

MaterialComponent::MaterialComponent()
{
    // TODO:
}

void MaterialComponent::SetId(int id)
{
   _id = id;
}

int MaterialComponent::GetId()
{
    return _id;
}

} // namespace ObjectSystem
} // namespace Engine