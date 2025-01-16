#pragma once

#include <string>
#include "ELogType.h"

using namespace std;

namespace Editor {
namespace LogSystem{

struct LogMessageData
{
public:
    std::string Prefix;

    std::string ItemName;

    std::string Message;

    ELogType LogType;

    // Color Color; TODO: 

    LogMessageData(string prefix, string itemName, string message, ELogType logType /*,Color color*/);
   
};

} // namespace Engine
} // namespace LogSystem
