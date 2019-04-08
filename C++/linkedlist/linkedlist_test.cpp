#include <iostream>
#include "single_linked_list.h"
using namespace std;

int main()
{
    SingleLinkedList list;

    list.insertNode(40);
    list.insertNode(30);
    list.traverse();

    list.appendNode(80);
    list.appendNode(50);
    list.traverse();
}