// Singleton for objects.
#pragma once

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
    Singleton(Singleton const&);
    Singleton & operator = (Singleton const&);
};

#ifdef __EMSCRIPTEN__
template<typename T>
T Singleton<T>::mSingleton;
#else
template<typename T>
T Singleton<T>::mSingleton = T();
#endif

