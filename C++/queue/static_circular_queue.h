#include <iostream>
using namespace std;

const int SIZE = 10;
class StaticCircularQueue
{
    private:
        int queue[SIZE];
        int front, rear;
        int element_count = 0;
    public:
        StaticCircularQueue()
        {
            front = -1;
            rear = -1;
        }

        void c_enqueue(int value) // For using Queue as Circular.
        {
            if ((front == rear) && (element_count == SIZE))
                cout << "Queue is full." << endl;
            else
            {
                rear = (rear + 1) % SIZE;
                queue[rear] = value;
                element_count++;
            }
        }
        int c_dequeue() // For using Queue as Circular.
        {
            int item;

            if ((front == rear) && (element_count == 0))
            {
                cout << "Queue is empty." << endl;
                exit(-1);
            }
            else
            {
                front = (front + 1) % SIZE;
                item = queue[front];
                element_count--;

                return item;
            }
        }
        int queue_full()
        {
            if (element_count == SIZE)
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
            if (element_count == 0)
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
            if (element_count == 0)
                cout << "Queue is empty!" << endl;
            else
            {
                int printer = (front + 1) % SIZE;
                int display_cnt = element_count;

                while (display_cnt != 0)
                {
                    cout << queue[printer] << " ";
                    display_cnt--;
                    printer = (printer + 1) % SIZE;
                }
                cout << endl;
            }
        }
};