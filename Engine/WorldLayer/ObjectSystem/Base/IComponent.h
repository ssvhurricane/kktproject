#pragma once

namespace Engine {
namespace ObjectSystem {

struct IComponent
{
    virtual void SetId(int id) = 0;
    virtual int GetId() = 0;
};

} // namespace ObjectSystem
} // namespace Engine
