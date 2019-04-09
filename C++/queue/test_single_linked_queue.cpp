#include <iostream>
#include "single_linked_queue.h"
using namespace std;

int main()
{
    SingleLinkedQueue queue;
    queue.traverse();
    queue.dequeue();

    for (int i=0; i<10; i++)
    {
        queue.enqueue(i+1);
    }
    queue.traverse();

    queue.search(7);
    queue.search(11);

    for (int i=0; i<5; i++)
    {
        queue.dequeue();
    }
    queue.traverse();

    queue.~SingleLinkedQueue();
    queue.enqueue(25);
    queue.traverse();
}