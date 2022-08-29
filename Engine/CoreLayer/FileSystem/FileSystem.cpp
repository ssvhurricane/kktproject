#include "FileSystem.h"

namespace Engine {
namespace FileSystem {

FileSystem::FileSystem()
{
    // TODO:
}

void FileSystem::Initialize()
{
    // TODO:
}

std::string FileSystem::GetFileData(const char* filePath)
{
    std::string convertCode;
  
    std::ifstream vFile;

    std::stringstream vStream;
	
    vFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);

    try 
    {
         vFile.open(filePath);
		
         vStream << vFile.rdbuf();
       
         vFile.close();
        
         convertCode = vStream.str();

    }
    catch (std::ifstream::failure& e)
    { 
        dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                        "FILE_NOT_SUCCESFULLY_READ!" + (std::string)filePath,
                                        Engine::LogSystem::ELogOutputLocationType::All);
    } 
    
     dynamic_cast<Engine::LogSystem::LogSystem*>
                (Engine::KKTEngine::InstancePtr()
                                  ->GetContext()
                                  ->GetSystem(ESystemType::LogSystem))
                                  ->ShowLog(Engine::LogSystem::ELogLayer::Engine, 
                                        typeid(this).name(),  
                                        Engine::LogSystem::ELogType::Error,
                                        "FILE_DATA: " + convertCode,
                                        Engine::LogSystem::ELogOutputLocationType::All);

     return convertCode;
}

} // namespace FileSystem
} // namespace Engine