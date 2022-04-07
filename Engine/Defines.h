#ifdef ENGINEDLL_EXPORTS
#define ENGINE_API __declspec(dllexport)
#else
#define ENGINE_API __declspec(dllimport)
#endif // ENGINEDLL_EXPORTS