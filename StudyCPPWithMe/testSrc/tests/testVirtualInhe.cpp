#include <iostream>

using namespace std;

class BB
{
public:
    BB(){}
    BB(int b) : bb_(b){}
    
public:
    int bb_;
};

class B1 : virtual public BB
{
public:
    B1(){}
    B1(int b1, int b) : b1_(b1), BB(b){}
    int b1_;
};

class B2 : virtual public BB
{
public:
    B2(){}
    B2(int b2, int b) : b2_(b2), BB(b){}
    int b2_;
};

class B3 : public B1
{
public:
    B3(){}
    int b3_;
};
class DD : public B1, public B2
{
public:
    DD(){}
    DD(int d, int b1, int b2, int b) : dd_(d), B1(b1, b), B2(b2, b), BB(b)
    {}
    int dd_;
};
// 钻石继承的方式

int main(void)
{
    	cout << sizeof(BB) << endl; // 4
 	   cout << sizeof(B1) << endl; // 16
 	   cout << sizeof(DD) << endl; // 40
   	 cout << sizeof(int) << endl; // 4
	cout << "sizeof(B3) = " << sizeof(B3) << endl;
	cout << "sizeof(B3::b3_) " << sizeof(B3::b3_) << endl;
  	  int a = 10;
 	   int* pa = &a;
    	cout << sizeof(pa) << endl; // 8
	cout << "打印B1对象的内存模型" << endl;
	B1 objB1;
	long** pb1 = (long**)&objB1;
	cout << &objB1 << endl;
	cout << &objB1.bb_ << endl;
	cout << &objB1.b1_ << endl;
	cout << "打印B2对象的内存模型" << endl;
	B2 objB2;
	long** pb2 = (long**)&objB2;
	cout << &objB2 << endl;
	cout << &objB2.bb_ << endl;
	cout << &objB2.b2_ << endl;
	cout << "打印B3对象的内存模型" << endl;
	B3 objB3;
	long** pb3 = (long**)&objB3;
	cout << &objB3 << endl;
	cout << &objB3.bb_ << endl;
	cout << &objB3.b1_ << endl;
	cout << &objB3.b3_ << endl;
	cout << "打印objB2的虚表指针" << endl;
	cout << pb2[0][0] << endl;
	cout << pb2[0][1] << endl;
    	cout << "打印dd的内存状况" << endl;
    	DD dd;
	cout << &dd << endl;
	cout << &dd.bb_ << endl;
	cout << &dd.b1_ << endl;
	cout << &dd.b2_ << endl;
	cout << &dd.dd_ << endl;
	
	long** p = (long**)&dd;
	cout << p[0][0] << endl;
	cout << p[0][1] << endl;
	cout << endl;
	cout << p[1][0] << endl;
	cout << p[1][1] << endl;

	BB* pp;
	pp = &dd;
	cout << "&dd = " << &dd << endl;
	cout << "pp = " << pp << endl;

    	return 0;
}