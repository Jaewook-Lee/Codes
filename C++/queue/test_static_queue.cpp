#include <iostream>
#include "static_queue.h"
using namespace std;

int main()
{
    StaticQueue int_queue = StaticQueue();
    // cout << int_queue.front << int_queue.rear << endl; --> Error!
    for (int i=1; i<=100; i++)
    {
        int_queue.enqueue(i);
    }
    int_queue.displayQueue();

    for (int i=0; i<50; i++)
    {
        int_queue.dequeue();
    }
    int_queue.displayQueue();

    int_queue.enqueue(101);
    int_queue.displayQueue();
}
