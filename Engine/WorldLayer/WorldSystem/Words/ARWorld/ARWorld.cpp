#include "ARWorld.h"

namespace Engine {
namespace WorldSystem {

ARWorld::ARWorld()
{
    // TODO:
    _id = 1;

    _name = "";

    _type = EWorldType::ARWorld;

}

void ARWorld::Initialize(std::string name, EWorldType eWorldType, EWorldMode eWorldName)
{
    // TODO:
}

void ARWorld::StartSimulate()
{
    // TODO:
}

void ARWorld::StopSimulate()
{
    // TODO:
}

void ARWorld::ReStart()
{
    // TODO:
}

int ARWorld::GetId()
{
    // TODO:
    return -1;
}

EWorldType ARWorld::GetType()
{
    // TODO:
    return EWorldType::ARWorld;
}

std::string ARWorld::GetName()
{
    // TODO:
    return  "";
}

void ARWorld::SetCurrentMode(EWorldMode eWorldMode)
{
    // TODO:
}

EWorldMode ARWorld::GetCurrentMode()
{
    // TODO:
    return EWorldMode::Combine;
}

} // namespace WorldSystem
} // namespace Engine