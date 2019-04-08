#include <iostream>
#include "single_linked_list.h"
using namespace std;

int main()
{
    SingleLinkedList list;
    list.traverse();

    list.insertNode(40);
    list.insertNode(30);
    list.traverse();

    list.appendNode(80);
    list.appendNode(50);
    list.traverse();

    list.deleteNode(30);
    list.deleteNode(5);
    list.traverse();

    list.search(80);
    list.search(100);

    list.~SingleLinkedList();
    list.traverse();
}