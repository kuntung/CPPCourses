#ifndef _STUDYCPP_STACK_H_
#define _STUDYCPP_STACK_H_

#include <deque>
#include <exception>

using std::deque;

template<typename T, typename CONT = deque<T> >

class Stack
{
public:
    Stack(): c()
    {
    }
    
    ~Stack()
    {
    }

    void Push(const T &elem)
    {
        c.emplace_back(elem);
    }

    void Pop() 
    {
        c.pop_back();
    }

    T &Top() 
    {
        return c.back();
    }

    const T& Top() const
    {
        return c.back();
    }

    bool Empty()
    {
        return c.empty();
    }

private:
   CONT c;
   int top_;

};
#endif // _STUDYCPP_STACK_H_
