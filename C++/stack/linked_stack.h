#include <iostream>
using namespace std;

struct Node
{
    public:
        int data;
        Node *next;

        Node(int value)
        {
            data = value;
            next = 0;
        }
};

class LinkedStack
{
    private:
        Node *head;
    public:
        LinkedStack() {head = 0;}
        ~LinkedStack() {};
        void createStack();
        void push(int);
        int pop();
        bool isEmpty();
        void traverse();
        void search(int);
};

void LinkedStack::createStack()
{
    head = 0;
}

void LinkedStack::push(int num)
{
    Node *temp = new Node(num);

    if (head != 0)
    {
        temp->next = head;
    }
    head = temp;
}

int LinkedStack::pop()
{
    if (!isEmpty())
    {
        Node *p;
        int num;

        num = head -> data;
        p = head;
        head = head -> next;
        delete p;

        return num;
    }
    else
    {
        cout << "Stack is empty.\n";
    }
}

bool LinkedStack::isEmpty()
{
    if (head == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void LinkedStack::traverse()
{
    Node *p;

    if (!isEmpty())
    {
        p = head;
        while (p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "Stack is empty!\n";
    }
}

void LinkedStack::search(int target)
{
    Node *p;

    if (head != 0) {
        p = head;
        while (p != 0 && p->data != target)
        {
            p = p->next;
        }
        if (p)
        {
            cout << p->data << " is found." << endl;
        }
        else
        {
            cout << target << " is not in the stack." << endl;
        }
    }
    else
    {
        cout << "Stack is empty.\n";
    }
}