#include "LogSystem.h"

namespace Editor {
namespace LogSystem {

LogSystem::LogSystem()
{
     std::cout << "[EditorLayer] -> [LogSystem] -> [Create LogSystem.]"<< std::endl;
}

 void LogSystem::Initialize()
 {
     // TODO:
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
 
  void LogSystem::ShowLog(ELogLayer layerName, 
            std::string itemName,
            ELogType logType,
            std::string message,
            ELogOutputLocationType logOutputLocationType)
  {
      // TODO: Ref//

      switch (layerName)
      {

      case ELogLayer::Editor:
      {
            std::cout << "[EditorLayer] -> "<< "[" << itemName << "] -> " << "["<< message  << "]" << std::endl;

           break;

      }

      case ELogLayer::Engine:
      {
            std::cout << "[EngineLayer] -> "<< "[" << itemName << "] -> " <<  "["<< message  << "]" << std::endl;

           break;

      } 
      
      case ELogLayer::Game:
      {
            std::cout << "[GameLayer] -> "<< "[" << itemName << "] -> " << "["<< message  << "]" << std::endl;

           break;

      }
      
      default:
           break;
      }
     
  }

} // namespace Editor
} // namespace LogSystem
