#ifndef _PATTERN_SINGLETON_H
#define _PATTERN_SINGLETON_H

class Singleton{
private:
    Singleton();
    Singleton(const Singleton &other);
public:
    static Singleton *getInstance();
    static Singleton *m_instance;
};

Singleton *Singleton::m_instance = nullptr;

// 线程非安全版本
Singleton *Singleton::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Singleton();
    }

    return m_instance;
}

// 多线程安全版本实现
// 但是锁的代价过高。每个线程都会来抢占一次这个锁
// 全是读的操作情况下，占用了时间。在高并发的情况下，没必要加锁
Singleton *Singleton::getInstance()
{
    Lock lock;
    if (m_instance == nullptr)
    {
        m_instance = new Singleton();
    }

    return m_instance;
}

// double check lock, 存在的问题：cpu的动态调度问题
Singleton *Singleton::getInstance()
{
    if (m_instance == nullptr) // 减少了加锁的代价
    {
        Lock lock; // 在为空的时候加锁,为了避免不正确
        if (m_instance == nullptr)
        {
            m_instance = new Singleton();
        }
    }
}

// 双检查锁的问题解决(volatile)
// c++11的跨平台方案实现
std::atomic<Singleton*> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton* Singleton::getInstance()
{
    Singleton *temp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); //获取内存fence
    if (temp == nullptr)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        temp = m_instance.load(std::memory_order_relaxed);
        if (temp == nullptr)
        {
            temp = new Singleton();
            std::atomic_thread_fence(std::memory_order_release); // 释放内存fence
            m_instance.store(temp, std::memory_order_relaxed);
        }
    }

    return temp;
}

#endif // _PATTERN_SINGLETON_H
