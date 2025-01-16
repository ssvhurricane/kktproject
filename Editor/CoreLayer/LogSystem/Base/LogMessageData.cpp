#include "LogMessageData.h"

namespace Editor {
namespace LogSystem{

LogMessageData::LogMessageData(string prefix, string itemName, string message, ELogType logType /*,Color color*/)
{
    Prefix = prefix;

    ItemName = itemName;

    Message = message;

    LogType = logType;

    //Color = color;
}


} // namespace Editor
} // namespace LogSystem