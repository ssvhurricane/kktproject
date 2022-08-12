#include "TextComponent.h"

namespace Engine {
namespace ObjectSystem {

TextComponent::TextComponent()
{
    // TODO:
}
void TextComponent::SetId(int id)
{
   _id = id;
}

int TextComponent::GetId()
{
    return _id;
}

} // namespace ObjectSystem
} // namespace Engine