#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    char grade;
    char name;
    int id;
    string major;
    Node *next;

    public:
        Node(char s_name, int s_id, string s_major, char s_grade)
        {
            name = s_name;
            id = s_id;
            major = s_major;
            grade = s_grade;
        }
};

class SinglyLinkedList
{
    public:
        Node *head;
    public:
        SinglyLinkedList() {head = 0;}
        ~SinglyLinkedList();
        void insertNode(char, int, string, char);
        void traverse();
        void filterGrade(char);
        void filterMajor(string);
};         

SinglyLinkedList::~SinglyLinkedList()    
{
}

void SinglyLinkedList::insertNode(char s_name, int s_id, string s_major, char s_grade)
{
    Node *temp = new Node(s_name, s_id, s_major, s_grade);
    Node *p, *q;

    if (head == 0)
    {
        head = temp;
    }
    else if (temp->name < head->name)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        p = head;
        while (p != 0 && p->name < temp->name)
        {
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

void SinglyLinkedList::traverse()
{
    Node *p;
    if (head == 0)
    {
        cout << "This list is empty.\n";
    }
    else
    {
        cout << "Name\tID\tMajor\tGrade\n";

        p = head;
        while (p != 0)
        {
            cout << p->name << "\t" << p->id << "\t" << p->major << "\t" << p->grade << endl;
            p = p->next;
        }
        cout << "\n";
    }
}

void SinglyLinkedList::filterGrade(char s_grade)
{
    Node *p;
    if (head == 0)
    {
        cout << "This list is empty.\n";
    }
    else
    {
        cout << "Name\tID\tMajor\tGrade\n";

        p = head;
        while (p != 0)
        {
            if (p->grade == s_grade)
            {
                cout << p->name << "\t" << p->id << "\t" << p->major << "\t" << p->grade << endl;
            }
            p = p->next;
        }
        cout << "\n";
    }
}

void SinglyLinkedList::filterMajor(string s_major)
{
    Node *p;
    if (head == 0)
    {
        cout << "This list is empty.\n";
    }
    else
    {
        cout << "Name\tID\tMajor\tGrade\n";

        p = head;
        while (p != 0)
        {
            if (p->major.compare(s_major) == 0)
            {
                cout << p->name << "\t" << p->id << "\t" << p->major << "\t" << p->grade << endl;
            }
            p = p->next;
        }
        cout << "\n";
    }
}


SinglyLinkedList makeSLL(string file_name);
SinglyLinkedList mergeList(SinglyLinkedList a, SinglyLinkedList b);

int main()
{
    SinglyLinkedList students_list = makeSLL("students_file.txt");
    students_list.traverse();
    students_list.filterGrade('A');

    SinglyLinkedList students_list2 = makeSLL("students_file2.txt");
    SinglyLinkedList students_database = mergeList(students_list, students_list2);
    students_database.filterMajor("CS");
}

SinglyLinkedList makeSLL(const string file_name)
{
    SinglyLinkedList sll;
    ifstream reader;
    reader.open(file_name);

    while (!reader.eof())
    {
        char s_name, s_grade;
        int s_id;
        string s_major;

        reader >> s_name >> s_id >> s_major >> s_grade;
        if (reader.eof())
        {
            break;
        }
        sll.insertNode(s_name, s_id, s_major, s_grade);
    }
    reader.close();
    
    return sll;
}

SinglyLinkedList mergeList(SinglyLinkedList a, SinglyLinkedList b)
{
    SinglyLinkedList final_list;
    Node *p, *q;

    if (a.head == 0 || b.head == 0)
    {
        cout << "You sent empty list.\n";
    }
    else
    {
        p = a.head;
        q = b.head;

        while (p != 0 && q != 0)
        {
            if (p->name < q->name)
            {
                final_list.insertNode(p->name, p->id, p->major, p->grade);
                p = p->next;
            }
            else
            {
                final_list.insertNode(q->name, q->id, q->major, q->grade);
                q = q->next;
            }
            
        }
        if (p != 0)
        {
            while (p != 0)
            {
                final_list.insertNode(p->name, p->id, p->major, p->grade);
                p = p->next;
            }
        }
        else if (q != 0)
        {
            while (q != 0)
            {
                final_list.insertNode(q->name, q->id, q->major, q->grade);
                q = q->next;
            }
        }
    }

    return final_list;
}