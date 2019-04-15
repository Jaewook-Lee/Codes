#include <iostream>
using namespace std;

struct Node
{
    public:
        int value;
        Node *prev;
        Node *next;

        Node(int data)
        {
            value = data;
            prev = 0;
            next = 0;
        }
};

class DoubleLinkedList
{
    private:
        Node *head;
    public:
        DoubleLinkedList() {head = 0;}
        ~DoubleLinkedList();
        int isEmpty();
        void insertNode(int);
        void deleteNode(int);
        void search(int);
        int searchNth(int);
        void showForward();
        void showBackward();
};
DoubleLinkedList::~DoubleLinkedList()
{
    Node *p;
    while (head != 0)
    {
        p = head;
        head = head->next;
        delete p;
    }
    
}
int DoubleLinkedList::isEmpty()
{
    if (head == 0)
        return 1;
    else
        return 0;
}
void DoubleLinkedList::insertNode(int num)
{
    Node *temp = new Node(num);

    if (head == 0)
        head = temp;
    else if (temp->value < head->value)
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        Node *p = head;
        Node *q = head;

        while (p != 0 && p->value < temp->value)
        {
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
            temp->prev = q;
            q->next = temp;
            p->prev = temp;
        }
        else
        {
            q->next = temp;
            temp->prev = q;
        }
    }
}
void DoubleLinkedList::deleteNode(int num)
{
    Node *p, *q;

    if (head == 0)
        cout << "List Empty\n";
    else
    {
        if (head->value == num)
        {
            if (head->next != 0)
            {
                p = head;
                head = head->next;
                head->prev = 0;
                delete p;
            }
            else
                head = 0;
        }
        else
        {
            p = head;
            q = head;

            while (p != 0 && p->value != num)
            {
                q = p;
                p = p->next;
            }
            if (p == 0)
                cout << num << " is not in the list\n";
            else if (p->next != 0 && p->value == num)
            {
                q->next = p->next;
                p->next->prev = q;
                delete p;
            }
            else if (p->next == 0 && p->value == num)
            {
                q->next = 0;
                delete p;
            }
        }
    }
}
void DoubleLinkedList::search(int target)
{
    Node *p;

    if (head == 0)
        cout << "List empty\n";
    else
    {
        p = head;
        while (p != 0 && p->value != target)
        {
            p = p->next;
        }
        if (p != 0)
            cout << target << " is in the list\n";
        else
            cout << target << " is not in the list\n";
    }   
}
int DoubleLinkedList::searchNth(int position)
{
    Node *p;

    if (head == 0)
        cout << "List Empty!\n";
    else
    {
        p = head;
        int idx = 1;
        while (idx != position)
        {
            if (p == 0)
                break;
            
            p = p->next;
            idx++;
        }
        if (p == 0)
            cout << "No such a line\n";
        else
            cout << p->value << endl;
    }
    
}
void DoubleLinkedList::showForward()
{
    Node *p;

    if (head == 0)
        cout << "list Empty\n";
    else
    {
        p = head;
        while (p != 0)
        {
            cout << p->value << " ";
            p = p->next;
        }
        cout << endl;
    }
}
void DoubleLinkedList::showBackward()
{
    Node *p;

    if (head == 0)
        cout << "list empty\n";
    else
    {
        p = head;

        while (p->next != 0)
        {
            p = p->next;
        }
        while (p != 0)
        {
            cout << p->value << " ";
            p = p->prev;
        }
        cout << endl;
    }
}