#include <iostream>
#include "double_linked_list.h"
using namespace std;

int main()
{
    DoubleLinkedList list;
    list.showForward();

    list.insertNode(45);
    list.insertNode(27);
    list.insertNode(89);
    list.insertNode(16);
    list.showForward();
    list.showBackward();

    list.deleteNode(45);
    list.deleteNode(5);
    list.showForward();
    list.showBackward();

    list.search(27);
    list.searchNth(1);
    list.searchNth(6);

    list.~DoubleLinkedList();
    list.insertNode(100);
    list.showForward();
    list.showBackward();
}