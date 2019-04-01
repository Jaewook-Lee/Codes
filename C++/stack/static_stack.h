#include <iostream>
using namespace std;

const int SIZE = 100;
class StaticStack
{
    private:
        int stack[SIZE];
        int top;

    public:
        StaticStack()
        {
            top = -1;
        }

        void push(int value)
        {
            if (top == SIZE - 1)
            {
                cout << "Stack is Full!" << endl;
            }
            else
            {
                stack[++top] = value;
            }
        }
        int pop()
        {
            return stack[top--];
        }
        int isEmpty()
        {
            if (top == -1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int isFull()
        {
            if (top == SIZE - 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void displayStack()
        {
            int temp;

            if (top == -1)
            {
                cout << "Stack is Empty!!" << endl;
            }
            else
            {
                temp = top;
                while (temp != -1)
                {
                    cout << stack[temp--] << "\n";
                }
            }
        }
};