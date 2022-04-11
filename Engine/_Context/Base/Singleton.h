namespace Engine {

template<typename T>
class Singleton
{
public:
    Singleton(){}
    ~Singleton(){}

    static T& Instance(void)
    {
        return mSingleton;
    }
    static T* InstancePtr(void)
    {
        return &mSingleton;
    }

protected:
    static T mSingleton;

private:
    Singleton(Singleton const&){}
    Singleton & operator = (Singleton const&){}
};

template<typename T>
T Singleton<T>::mSingleton = T();

} // namespace Engine
