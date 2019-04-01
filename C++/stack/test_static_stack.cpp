#include <iostream>
#include "static_stack.h"
using namespace std;

int main()
{
    StaticStack int_stack = StaticStack();
    // cout << int_stack.top << endl; --> Error!
    int_stack.push(1);
    int_stack.displayStack();
    if (int_stack.isFull())
    {
        cout << "Stack is full" << endl;
    }
    else if (int_stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    int_stack.pop();
    int_stack.displayStack();
    if (int_stack.isFull())
    {
        cout << "Stack is full" << endl;
    }
    else if (int_stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

    for (int i=0; i<100; i++)
    {
        int_stack.push(i);
    }
    if (int_stack.isFull())
    {
        cout << "Stack is full" << endl;
        int_stack.displayStack();
    }
    else if (int_stack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }

}