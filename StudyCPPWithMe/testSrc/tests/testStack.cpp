#include "StudyCPPWithMe/testSrc/stack.h"
#include <iostream>

using namespace std;

int main(void)
{
    Stack<int> s;
    s.Push(1);
    s.Push(2);
    s.Push(3);

    while (!s.Empty())
    {
        cout << s.Top() << endl;
        s.Pop();
    }

    return 0;
}
