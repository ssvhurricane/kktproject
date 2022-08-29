#include "LogMessageData.h"

namespace Engine {
namespace LogSystem{

LogMessageData::LogMessageData(string prefix, string itemName, string message, ELogType logType /*,Color color*/)
{
    Prefix = prefix;

    ItemName = itemName;

    Message = message;

    LogType = logType;

    //Color = color;
}


} // namespace Engine
} // namespace LogSystem