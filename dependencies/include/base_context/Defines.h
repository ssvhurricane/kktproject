// If you are building the DLL project on the command line,
// use the /D compiler option to define the MATHDLLWIN32_EXPORTS symbol.
#pragma once

#ifdef ENGINEDLL_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif // ENGINEDLL_EXPORTS

#ifdef UIDLL_EXPORTS
#define UI_API __declspec(dllexport)
#else
#define UI_API __declspec(dllimport)
#endif // UIDLL_EXPORTS