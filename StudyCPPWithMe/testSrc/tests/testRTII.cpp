#include <iostream>

using namespace std;

class Shape{
public:
    virtual void  Draw() = 0;
    virtual ~Shape(){}
};

class Circle : public Shape
{
public:
    void Draw()
    {
        cout << "Circle::Draw()" << endl;
    }
};
class Square: public Shape
{
public:
    void Draw()
    {
        cout << "Square::Draw()" << endl;
    }
};

class Rectangle: public Shape
{
public:
    void Draw()
    {
        cout << "Rectangle::Draw()" << endl;
    }

};
int main(void)
{
    Shape* p;
    Circle c;

    p = &c;
    p->Draw();
    
    if (dynamic_cast<Circle*>(p))
        cout << "p is a pointer to a Circle object" << endl;
    else if (dynamic_cast<Square*>(p))
        cout << "p is a pointer to a Square object" << endl;
    else
        cout << "p is a pointer to other object " << endl;
    return 0;
}
