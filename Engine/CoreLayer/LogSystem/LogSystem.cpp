#include "LogSystem.h"

namespace Engine {
namespace LogSystem{

LogSystem::LogSystem(){}

 void LogSystem::Initialize()
 {
        std::cout << "LogSystem Initialize!" << std::endl;
 }

 void LogSystem::MessageProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType)
 {
      //TODO:
 }

 void  LogSystem::WarningProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType)
 {
      //TODO:
 }

 void LogSystem::ErrorProcess(LogMessageData logMessageData, ELogOutputLocationType logOutputLocationType)
 {
      //TODO:
 }
 
  void LogSystem::ShowLog(std::string itemName,
            ELogType logType,
            std::string message,
            ELogOutputLocationType logOutputLocationType)
  {
      // TODO:
      std::cout << "[Log] -> " << "["<< message  << "]" << std::endl;
  }

} // namespace Engine
} // namespace LogSystem
