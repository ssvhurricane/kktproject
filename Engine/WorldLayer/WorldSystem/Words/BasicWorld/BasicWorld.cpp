#include "BasicWorld.h"

namespace Engine {
namespace WorldSystem {

BasicWorld::BasicWorld()
{
    // TODO:
    _id = 1;

    _name = "";

    _type = EWorldType::BasicWorld;

}

void BasicWorld::Initialize(std::string name, EWorldType eWorldType, EWorldMode eWorldMode)
{
    // TODO:
}

void BasicWorld::StartSimulate()
{
    // TODO:
}

void BasicWorld::StopSimulate()
{
    // TODO:
}

void BasicWorld::ReStart()
{
    // TODO:
}

int BasicWorld::GetId()
{
    // TODO:
    return -1;
}

EWorldType BasicWorld::GetType()
{
    // TODO:
    return EWorldType::BasicWorld;
}

std::string BasicWorld::GetName()
{
    // TODO:
    return "";
}

void BasicWorld::SetCurrentMode(EWorldMode eWorldMode)
{
    // TODO:
}

EWorldMode BasicWorld::GetCurrentMode()
{
    // TODO:
    return EWorldMode::Combine;
}

} // namespace WorldSystem
} // namespace Engine