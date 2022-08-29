#include "AppWorld.h"

namespace Engine {
namespace WorldSystem {

AppWorld::AppWorld()
{
    // TODO:

    _id = 1;

    _name = "";

    _type = EWorldType::AppWorld;

}

void AppWorld::Initialize(std::string name, EWorldType eWorldType, EWorldMode eWorldName)
{
    // TODO:
}

void AppWorld::StartSimulate()
{
    // TODO:
}

void AppWorld::StopSimulate()
{
    // TODO:
}

void AppWorld::ReStart()
{
    // TODO:
}

int AppWorld::GetId()
{
    // TODO:
    return -1;
}

EWorldType AppWorld::GetType()
{
    // TODO:
    return EWorldType::AppWorld;
}

std::string AppWorld::GetName()
{
    // TODO:
    return "";
}

void AppWorld::SetCurrentMode(EWorldMode eWorldMode)
{
    // TODO:
}

EWorldMode AppWorld::GetCurrentMode()
{
    // TODO:
    return EWorldMode::Combine;
}

} // namespace WorldSystem
} // namespace Engine