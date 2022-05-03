// Dynamic Labriary or static lib.
// Con Engine or custom app.
// TODO:

#pragma once

#include <iostream>
#include <string>

#include "base_context/Singleton.h"
#include "base_context/Defines.h"
#include "base_context/IContextInstaller.h"

namespace UI {
#if defined _WIN32
class UI_API KKTUI : public Singleton<KKTUI>
#elif defined __APPLE__  || defined __linux__
class KKTUI : public Singleton<KKTUI>
#endif
{
private:

    //IContextInstaller* _mainContext; // Main Context (Use engine or app)
    
public:
#if defined _WIN32

     void __cdecl InitialUI(); 

     void __cdecl PrintDebugMessage(std::string str);
    
     IContextInstaller* __cdecl GetContext();

#elif defined __APPLE__  || defined __linux__

     void  InitialUI(); 

     void PrintDebugMessage(std::string str);
    
     IContextInstaller*  GetContext();
     
#endif 
     
};
} // namespace UI