#include <iostream>
#include "static_circular_queue.h"
using namespace std;

int main()
{
    StaticCircularQueue int_queue = StaticCircularQueue();
    // cout << int_queue.front << int_queue.rear << endl; --> Error!
    for (int i=1; i<=10; i++)
    {
        int_queue.c_enqueue(i);
    }
    int_queue.displayCircularQueue();

    for (int j=0; j<5; j++)
        int_queue.c_dequeue();
    int_queue.displayCircularQueue();

    int_queue.c_enqueue(11);
    int_queue.displayCircularQueue();
}
