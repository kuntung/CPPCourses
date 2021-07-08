#ifndef _CPPCOURSE_SHAPE_H
#define _CPPCOURSE_SHAPE_H

class Shape
{
public:
    virtual void Draw() = 0; // 纯虚函数

    virtual ~Shape() {} // 纯虚析构，但是要给出默认实现
};

class Circle : public Shape
{
public:
    virtual void Draw();
    ~Circle();
};

class Square : public Shape
{
public:
    virtual void Draw();
    
    ~Square();
};

class Rectangle : public Shape
{
public:
    virtual void Draw();
    
    ~Rectangle();
};


#endif // _CPPCOURSE_SHAPE_H