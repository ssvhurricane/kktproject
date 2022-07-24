
KKT - crossplatform application engine, game engine.
It is written in C/C++.

Features:
 - cross-platform engine;
 - engine as dll;
 - support an run on Linux, Mac, Windows, Browser; 
 - create and build application on Windows, Linux, MacOS, Browser, Mobile(*);  
 - support keyboard, mouse and gamepad(for PC, Console games);
 - support OpenGL 3.3 graphic api, OpenGL ES 3.0(*), WebGL 1.0-2.0 api, Vulkan api;
 - create UI for application(PC, Web), games and editor(used nuklear);
 - support maths;
 - physics(games);
 - particle system(games);
 - animation;
 - support audio;
 - diagnostics instruments, perfomance.


Project arhitecture:
 KKTEngine(Engine).
 - base module, core. Build as dynamic library;
 - main file: KKTEngine.cpp, KKTEngine.h.

 KKTEngineDemo(EngineDemo).
 - demo project;
 - main filie: KKTEngineDemo.cpp, KKTEngineDemo.h.

 KKTEditor(Editor).
 - Editor application;
 - main file: KKTEditor.cpp, KKTEditor.h.

Build Project(Only visual studio code):
 - create folder(root): 
    bin->mac_os;
    bin->windows_os;
    bin->linux_os;
    bin->browser;
 - use Ctrl+P;
 - enter "task";
 - select build platfrom and type(lib, exe, etc).
 
 Run and Debug Project:
    - Menu "Run";
    - add breakpoint;
    - F5, Ctrl+F5;
    - if browser, neadd server simulate and run.

Warning! Need rebuild GLFW(cmake) without the option USE_MSVC_RUNTIME_LIBRARY_DLL.

(*) - support may be added in the future.