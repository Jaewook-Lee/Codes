#include <iostream>
using namespace std;

const int SIZE = 3;
class StaticCircularQueue
{
    private:
        char char_queue[SIZE];
        int front, rear;
        int flag = 0; // For checking existing

    public:
        StaticCircularQueue()
        {
            front = -1;
            rear = -1;
        }

        void c_enqueue(char value) // For using Queue as Circular.
        {
            if (front == rear && flag == 1)
            {
                cout << "Queue is Full." << endl;
            }
            else
            {
                char_queue[rear] = value;
                rear = (rear + 1) % SIZE;
            }
        }
        char c_dequeue() // For using Queue as Circular.
        {
            char item;
            if (front == rear && flag == 0)
            {
                cout << "Queue is Empty." << endl;
            }
            else
            {
                item = char_queue[front];
                front = (front + 1) % SIZE;
                flag = 0;
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
        void displayCircularQueue()
        {
            int i;
            if (front == rear)
            {
                cout << "Can't display. Queue is empty." << endl;
            }
            else
            {
                i = front + 1;
                cout << "-------Your Queue-------" << endl;
                while (i <= rear)
                {
                    cout << char_queue[i] << "\n";
                    i += 1;
                }
            }
        }
};