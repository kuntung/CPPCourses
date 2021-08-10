#include <iostream>
#include <vector>
#include <string>
#include "StudyCPPWithMe/testSrc/Shape.h"
#include "StudyCPPWithMe/testSrc/DynBase.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

void DrawAllShapes(const vector<Shape*>& v)
{
	for (auto& item : v)
		item->Draw();
}

void DelAllShapes(vector<Shape*>& v)
{
	for (auto& item : v)
		delete item;
}

int main(void)
{
	vector<Shape*> v;
	
	Shape* ps;

	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Circle"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Square"));
	v.push_back(ps);
	ps = static_cast<Shape*>(DynObjectFactory::CreateObject("Rectangle"));
	v.push_back(ps);

	DrawAllShapes(v);
	DelAllShapes(v);

	return 0;
}
