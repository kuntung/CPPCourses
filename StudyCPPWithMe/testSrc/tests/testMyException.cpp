#include <iostream>
#include <string>

using namespace std;

class MyException
{
public:
    MyException(const char* message) : message_(message)
    {
        cout << "MyException..." << endl;
    }
    MyException(const MyException& other) : message_(other.message_)
    {
        cout << "MyException..." << endl;
    }
    ~MyException()
    {
        cout << "~MyException" << endl;
    }
    string what() const
    { return message_; }
private:
    string message_;
};

double Divide(double a, double b)
{
    if (b == 0.0d)
    {
        MyException e("division by zeros");
        throw e;
    }
}

void myTerminate()
{
    cout << "Myterminate()" << endl;
}

void testMyException1()
{
    try
    {
        cout << Divide(5.0, 0.0d) << endl;
    }
    catch(MyException& e)
    {
        cout << e.what() << endl;
    }
}

void testMyException2()
{
    try{
        try
        {
	throw MyException("exception throw in inner try " );
        }
        catch(int)
        {
	cout << "catch int exception" << endl;
        }
    }
    catch (MyException& e)
    {
          cout << "catch inner exception" << e.what() << endl;
    }

}
int main(void)
{
   set_terminate(myTerminate);
   testMyException1();
   testMyException2();
    
    return 0;
}