#include "StudyCPPWithMe/testSrc/Singleton.h"
#include <iostream>

class ApplicationImpl
{
public:
    ApplicationImpl() {cout << "ApplicationImpl..." << endl; }
    ~ApplicationImpl() { cout << "~ApplicationImpl..." << endl;}

    void Run() { cout << "Run..." << endl; }
};

typedef Singleton<ApplicationImpl> Application;
int main(void)
{
    
    Application::GetInstance().Run();
    Application::GetInstance().Run(); // 这时候Application是一个单例模式类

    return 0;
}

