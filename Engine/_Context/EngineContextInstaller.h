#ifndef ENGINE_CONTEXT_INSTALLER_H_
#define ENGINE_CONTEXT_INSTALLER_H_
//#include "boost/di.hpp"

//#include "CoreLayer/LogSystem/LogSystem.h"

//namespace di = boost::di;
//namespace core = boost::ext::di::v1_2_0::core;
//namespace ver = boost::ext::di::v1_2_0;

#include <iostream>
#include "IContextInstaller.h"

namespace Engine {
namespace _Context {

class EngineContextInstaller: public IContextInstaller
{
private:

    // core::injector<ver::config, core::pool_t<>> _injector;
    
    void InstallBindings();

    void CreateContext();

public: 

  EngineContextInstaller();

  void GetSystem();
};


} // namespace _Context
} // namespace Engine


#endif  // ENGINE_CONTEXT_INSTALLER_H_