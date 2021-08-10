#ifndef _STUDYCPP_SINGLETON_H_
#define _STUDYCPP_SINGLETON_H_

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

template <typename T> 
class Singleton
{
public:
    static T &GetInstance()
    {
        Init();

        return *instance_;
    }

private:
    
    static void Init()
    {
        if (instance_ == 0)
        {
            instance_ = new T;
            atexit(Destory);
        }

    }

    static void Destory()
    {
        delete instance_;
    }

    Singleton()
    {
        cout << "Singleton()..." << endl;
    }
    Singleton(const Singleton & other) = default;
    Singleton& operator= (const Singleton &other) = default;
    ~Singleton()
    {
        cout << "~Singleton()..." << endl;
    }
    
    static T* instance_; // 智能指针实现对象释放
};

// 类外初始化
template <typename T>
T* Singleton<T>::instance_ = 0;
#endif // _STUDYCPP_SINGLETON_H_
