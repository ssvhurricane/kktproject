// This is non Context System (you can't use distanced services here).
#pragma once

#include "base_context/ISystem.h"

namespace Engine {
namespace PlatformFileSystem {
class PlatformFileSystem : public ISystem
{
private:
// TODO:
public:

    PlatformFileSystem();

    void Initialize();
};

} // namespace PlatformFileSystem
} // namespace Engine