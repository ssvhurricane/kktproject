#include "LightComponent.h"

namespace Engine {
namespace ObjectSystem {

LightComponent::LightComponent()
{
    // TODO:
}

void LightComponent::SetId(int id)
{
   _id = id;
}

int LightComponent::GetId()
{
    return _id;
}

} // namespace ObjectSystem
} // namespace Engine