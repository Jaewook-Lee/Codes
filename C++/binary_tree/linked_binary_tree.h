#include <iostream>
#include <string>
using namespace std;

struct Node
{
    char data;
    int prior;
    Node *left_link;
    Node *right_link;

    public:
        Node(char token) : prior(4), left_link(0), right_link(0)
        {
            data = token;
        }
};
class LinkedBinTree
{
    private: char priorities[2][4] = {{'*', '/', '+', '-'}, {'2', '2', '1', '1'}};
    public:
        Node *root;
        LinkedBinTree(string exp);
        void DestructLinkedBinTree(Node *a);
        void insertNode(char data);
        void infixTraverse(Node *a);
        void postfixTraverse(Node *a);
        void prefixTraverse(Node *a);
        void drawTree(Node *a, int level=1);
        int eval(Node *a);
};
LinkedBinTree::LinkedBinTree(string expression) : root(0)
{
    for (int i=0; i<expression.length(); i++)
    {
        if (expression[i] == ' ') continue;
        else insertNode(expression[i]);
    }
}
void LinkedBinTree::DestructLinkedBinTree(Node *a)
{
    if (a == 0) return;
    DestructLinkedBinTree(a->left_link);
    DestructLinkedBinTree(a->right_link);
    delete a;
}
void LinkedBinTree::insertNode(char data)
{
    Node *new_node = new Node(data);
    int i;
    for (i=0; i<4; i++)
    {
        if (new_node->data == priorities[0][i])
        {
            new_node->prior = priorities[1][i] - '0';
            break;
        }
    }

    if (i == 4)
    {
        if (root == 0) root = new_node;
        else
        {
            Node *p = root;
            while (p->right_link != 0)
                p = p->right_link;
            p->right_link = new_node;
        }
    }
    else
    {
        if (root->prior >= new_node->prior)
        {
            new_node->left_link = root;
            root = new_node;
        }
        else
        {
            new_node->left_link = root->right_link;
            root->right_link = new_node;
        }
    }
}
void LinkedBinTree::infixTraverse(Node *a)
{
    if (a)
    {
        infixTraverse(a->left_link);
        cout << a->data << " ";
        infixTraverse(a->right_link);
    }

    if (a == root) cout << endl;
}
void LinkedBinTree::postfixTraverse(Node *a)
{
    if (a)
    {
        postfixTraverse(a->left_link);
        postfixTraverse(a->right_link);
        cout << a->data << " ";
    }
    if (a == root) cout << endl;
}
void LinkedBinTree::prefixTraverse(Node *a)
{
    if (a)
    {
        cout << a->data << " ";
        prefixTraverse(a->left_link);
        prefixTraverse(a->right_link);
    }
    if (a == root) cout << endl;
}
void LinkedBinTree::drawTree(Node *a, int level)
{
    if (a == root) cout << "Tree Structure" << endl;
    if (a != 0)
    {
        drawTree(a->right_link, level + 1);

        for (int i=0; i<level-1; i++) cout << "    ";
        cout << a->data << " ";

        if (a->left_link != 0 && a->right_link != 0) cout << "<" << endl;
        else if (a->right_link != 0) cout << "/" << endl;
        else if (a->left_link != 0) cout << "\\" << endl;
        else cout << endl;

        drawTree(a->left_link, level + 1);
    }
}
int LinkedBinTree::eval(Node *a)
{
    int value;
    if (a)
    {
        if (a->data - '0' >= 0 && a->data - '0' <= 9) value = a->data - '0';
        else
        {
            int left_value = eval(a->left_link);
            int right_value = eval(a->right_link);

            switch (a->data)
            {
                case '+':
                    value = left_value + right_value;
                    break;
                case '-':
                    value = left_value - right_value;
                    break;
                case '*':
                    value = left_value * right_value;
                    break;
                case '/':
                    value = left_value / right_value;
                    break;
            }
        }
        return value;
    }
}