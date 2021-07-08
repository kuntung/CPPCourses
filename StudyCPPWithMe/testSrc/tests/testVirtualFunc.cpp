#include <iostream>

using namespace std;

class Base
{
public:
    virtual void Func1()
    {
        cout << "Base::Func1() ... " << endl;
    }
    virtual void Func2()
    {
        cout << "Base::Func2() ... " << endl;
    }
    int data1_;
};

class Derived : public Base
{
public:
    virtual void Func2()
    {
        cout << "Derived::Func2() ..." << endl;
    }
    
    virtual void Func3()
    {
		cout << "Derived::Func3() ..." << endl;
    }
    int data2_;
};

typedef void (*FUNC)(); // 定义一个函数指针，名称为FUNC
int main(void)
{
    Base b;
    cout << sizeof(Base) << endl;
    cout << sizeof(Derived) << endl;
    
    long** p = (long**)&b; // 指向base的虚表指针所指向的虚表
    FUNC fun = (FUNC)p[0][0]; // 将p[0][0]强制转换为FUNC
    fun();
    fun = (FUNC)p[0][1]; // Func2
    fun();
    
    Derived d;
    p = (long**)&d;
    
    fun = (FUNC)p[0][0]; // Base::Func1
    fun();
    fun = (FUNC)p[0][1]; // Derived::Func2
    fun();
    fun = (FUNC)p[0][2]; // Derived::Func3
    fun();
    
    return 0;
}