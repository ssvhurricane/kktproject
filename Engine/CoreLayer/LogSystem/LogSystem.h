#pragma once

#include <iostream>
#include <string>
#include "Base/ELogOutputLocationType.h"
#include "Base/ELogLayer.h"
#include "Base/LogMessageData.h"
#include "../../_Context/Base/ISystem.h"
#include "../../_Context/Base/Defines.h"

namespace Engine {
namespace LogSystem{

class ENGINE_API LogSystem : public _Context::ISystem
{
private:
// TODO:
    void MessageProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType);

    void WarningProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType);

    void ErrorProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType);

public:

  LogSystem();

    void Initialize();

    void ShowLog(std::string itemName,
            ELogType logType,
            std::string message,
            ELogOutputLocationType logOutputLocationType = ELogOutputLocationType::Console);
};

} // namespace Engine
} // namespace LogSystem