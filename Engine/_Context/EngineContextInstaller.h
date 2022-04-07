#ifndef ENGINE_CONTEXT_INSTALLER_H_
#define ENGINE_CONTEXT_INSTALLER_H_
//#include "boost/di.hpp"

//#include "CoreLayer/LogSystem/LogSystem.h"

//namespace di = boost::di;
//namespace core = boost::ext::di::v1_2_0::core;
//namespace ver = boost::ext::di::v1_2_0;

namespace Engine {
namespace _Context {

class EngineContextInstaller 
{
private:

  // core::injector<ver::config, core::pool_t<>> _injector;

   virtual void InstallBindings();

public: 

   EngineContextInstaller ();

   virtual ~EngineContextInstaller ();

   virtual void CreateContext();
};

} // namespace _Context
} // namespace Engine


#endif  // ENGINE_CONTEXT_INSTALLER_H_