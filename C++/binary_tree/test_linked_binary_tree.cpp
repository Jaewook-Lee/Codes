#include "linked_binary_tree.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string expression;
    cout << "Enter expression : ";
    getline(cin, expression);

    LinkedBinTree tree(expression);
    cout << "InOrder : ";
    tree.infixTraverse(tree.root);
    cout << "PostOrder : ";
    tree.postfixTraverse(tree.root);
    cout << "PreOrder : ";
    tree.prefixTraverse(tree.root);
    cout << "Evaluation: " << tree.eval(tree.root) << endl;
    tree.drawTree(tree.root);

    tree.DestructLinkedBinTree(tree.root);
    tree.infixTraverse(tree.root);
}