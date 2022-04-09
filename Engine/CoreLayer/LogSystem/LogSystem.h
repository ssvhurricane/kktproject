#ifndef ENGINE_LOG_SYSTEM_H_
#define ENGINE_LOG_SYSTEM_H_
#pragma once

#include <iostream>
#include <string>
#include "Base/ELogOutputLocationType.h"
#include "Base/ELogLayer.h"
#include "Base/LogMessageData.h"
#include "../../_Context/Base/ISystem.h"

namespace Engine {
namespace LogSystem{

class LogSystem : public _Context::ISystem
{
private:
// TODO:
    void MessageProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType);

    void WarningProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType);

    void ErrorProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType);

public:

    explicit LogSystem();

    void ShowLog(std::string itemName,
            ELogType logType,
            std::string message,
            ELogOutputLocationType logOutputLocationType = ELogOutputLocationType::Console);
};

} // namespace Engine
} // namespace LogSystem


#endif  // ENGINE_LOG_SYSTEM_H_