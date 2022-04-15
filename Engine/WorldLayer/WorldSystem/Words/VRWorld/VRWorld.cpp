#include "VRWorld.h"

namespace Engine {
namespace WorldSystem {

VRWorld::VRWorld()
{
    // TODO:
    _id = 1;

    _name = "";

    _type = EWorldType::VRWorld;

}

void VRWorld::Initialize(std::string name, EWorldType eWorldType, EWorldMode eWorldName)
{
    // TODO:
}

void VRWorld::StartSimulate()
{
    // TODO:
}

void VRWorld::StopSimulate()
{
    // TODO:
}

void VRWorld::ReStart()
{
    // TODO:
}

int VRWorld::GetId()
{
    // TODO:
    return -1;
}

EWorldType VRWorld::GetType()
{
    // TODO:
    return EWorldType::VRWorld;
}

std::string VRWorld::GetName()
{
    // TODO:
    return "";
}

void VRWorld::SetCurrentMode(EWorldMode eWorldMode)
{
    // TODO:
}

EWorldMode VRWorld::GetCurrentMode()
{
    // TODO:
    return EWorldMode::Combine;
}

} // namespace WorldSystem
} // namespace Engine