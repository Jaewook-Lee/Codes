#include <iostream>
using namespace std;

const int SIZE = 10;
class StaticQueue
{
    private:
        int queue[SIZE];
        int front, rear;

    public:
        StaticQueue()
        {
            front = -1;
            rear = -1;
        }

        void enqueue(int value)
        {
            if (rear == SIZE - 1)
            {
                cout << "QueueFull." << endl;
            }
            else
            {
                queue[++rear] = value;
            }
        }
        int dequeue()
        {
            int item;
            if (front == rear)
            {
                cout << "QueueEmpty." << endl;
            }
            else
            {
                item = queue[++front];
                return item;
            }
        }
        int queue_full()
        {
            if (rear == SIZE - 1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        int queue_empty()
        {
            if (front == rear)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        void displayQueue()
        {
            int i;
            if (front == rear)
            {
                cout << " QueueEmpty." << endl;
            }
            else
            {
                i = front + 1;
                while (i <= rear)
                {
                    if (i == rear)
                    {
                        cout << queue[i] << endl;
                    }
                    else
                    {
                        cout << queue[i] << ", ";
                    }
                    i += 1;
                }
            }
        }
};