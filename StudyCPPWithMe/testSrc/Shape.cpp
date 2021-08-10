#include "Shape.h"
#include "DynBase.h"
#include <string>
#include <iostream>

using std::cout;
using std::string;
using std::endl;

void Circle::Draw()
{
	cout << "Circle::Draw() ... " << endl;
}

Circle::~Circle()
{
	cout << "Circle::~Circle()" << endl;
}

void Square::Draw()
{
	cout << "Square::Draw() ... " << endl;
}

Square::~Square()
{
	cout << "Square::~Square()" << endl;
}

void Rectangle::Draw()
{
	cout << "Rectangle::Draw() ... " << endl;
}

Rectangle::~Rectangle()
{
	cout << "Rectangle::~Rectangle()" << endl;
}

REGISTER_CLASS(Circle);
REGISTER_CLASS(Square);
REGISTER_CLASS(Rectangle);

/*
// 以Circle为例
class CircleRegister
{
public:
	static void* NewInstance()
	{
		return new Circle;
	}
private:
	static Register reg_; // 声明
};

Register CircleRegister::reg_("Circle", CircleRegister::NewInstance) // 注册一个函数NewInstance
*/
