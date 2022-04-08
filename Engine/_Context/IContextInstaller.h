namespace Engine {
namespace _Context {

struct IContextInstaller 
{ 
    virtual void InstallBindings() = 0;
    virtual void CreateContext() = 0;
};

} // namespace _Context
} // namespace Engine
