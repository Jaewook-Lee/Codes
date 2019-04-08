#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    
    public:
        Node(int num)
        {
            data = num;
            next = 0;
        }
};

class SingleLinkedList
{
    private:
        Node *head;
    public:
        SingleLinkedList(){head = 0;}
        ~SingleLinkedList();
        void insertNode(int);
        void appendNode(int);
        void deleteNode(int);
        bool isEmpty();
        void traverse();
        void search(int);
};

SingleLinkedList::~SingleLinkedList()
{
    Node *p;

    while(head != 0){
        p = head;
        head = head->next;
        delete p;
    }
}

void SingleLinkedList::traverse()
{
    Node *p;

    if (!isEmpty()) {
        p = head;

        while(p){
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List is empty!\n";
    }
}

void SingleLinkedList::insertNode(int num)
{
    Node *temp = new Node(num);
    Node *p, *q;

    if (head == 0)
        head = temp;
    else if (temp->data < head->data)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        p = head;
        while((p != 0) && (p->data < temp->data)){
            q = p;
            p = p->next;
        }
        if (p != 0)
        {
            temp->next = p;
        }
        q->next = temp;
    }
}

void SingleLinkedList::appendNode(int num)
{
    Node *temp = new Node(num);

    if (head == 0)
        head = temp;
    else
    {
        Node *p = head;
        while(p->next != 0){
            p = p->next;
        }
        p->next = temp;
    }    
}

void SingleLinkedList::deleteNode(int num)
{
    Node *p, *q;

    if (head->data == num)
    {
        p = head;
        head = head->next;
        delete p;
    }
    else
    {
        p = head;
        while(p != 0 && p->data != num){
            q = p;
            p = p->next;
        }
        if (p != 0) {
            q->next = p->next;
            delete p;
        }
        else
        {
            cout << num << " is not in the list.\n";
        }       
    }
}

bool SingleLinkedList::isEmpty()
{
    if (head == 0)
        return true;
    else
        return false;
}

void SingleLinkedList::search(int num)
{
    Node *p;

    if (head != 0)
    {
        p = head;
        while(p != 0 && p->data != num){
            p = p->next;
        }
        if (p)
            cout << p->data << " is found." << endl;
        else
            cout << num << " is not in the list." << endl;
    }
    else
    {
        cout << "List is empty\n";
    }
    
}